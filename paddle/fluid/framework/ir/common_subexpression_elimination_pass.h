// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <iostream>

#include "paddle/fluid/framework/ir/fuse_pass_base.h"

namespace paddle {
namespace framework {
namespace ir {

class Graph;

class CommonSubexpressionEliminationPass : public FusePassBase {
 public:
  CommonSubexpressionEliminationPass() {}

 protected:
  void ApplyImpl(ir::Graph* graph) const override;

 private:
  void CommonSubexpressionEliminate(
      ir::Graph* main_graph,
      ir::Graph* graph,
      std::function<Node*(Node*)> parent_exist_nodes) const;
};

struct HashOpNode {
  size_t operator()(const Node* node) const;
};

struct EqualOpNode {
  bool operator()(const Node* lhs, const Node* rhs) const;
};

}  // namespace ir
}  // namespace framework
}  // namespace paddle
