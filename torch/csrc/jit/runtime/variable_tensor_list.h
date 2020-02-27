
copy: fbcode/caffe2/torch/csrc/jit/runtime/variable_tensor_list.h
copyrev: 93f578c4e600b804b2352c6d71ff40047c47dc6d

#pragma once
#include <ATen/ATen.h>

namespace torch {
namespace jit {

// a wrapper to mark places where we expect all the at::Tensors to be
// variables
struct variable_tensor_list : public std::vector<at::Tensor> {
  variable_tensor_list() = default;
  template <class InputIt>
  variable_tensor_list(InputIt first, InputIt last)
      : std::vector<at::Tensor>(first, last) {}
  explicit variable_tensor_list(std::vector<at::Tensor>&& tensor)
      : std::vector<at::Tensor>(std::move(tensor)) {}
};

} // namespace jit
} // namespace torch