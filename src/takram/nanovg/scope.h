//
//  takram/nanovg/scope.h
//
//  MIT License
//
//  Copyright (C) 2015 Shota Matsuda
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.
//

#pragma once
#ifndef TAKRAM_NANOVG_SCOPE_H_
#define TAKRAM_NANOVG_SCOPE_H_

#include "nanovg.h"

#include "takram/nanovg/context.h"

namespace takram {
namespace nanovg {

class Scope final {
 public:
  Scope();
  explicit Scope(NVGcontext *context);
  ~Scope();

  // Disallow copy semantics
  Scope(const Scope&) = delete;
  Scope& operator=(const Scope&) = delete;

 private:
  NVGcontext *context_;
};

#pragma mark -

inline Scope::Scope() : context_(Context::current()) {
  if (context_) {
    nvgSave(context_);
  }
}

inline Scope::Scope(NVGcontext *context) : context_(context) {
  if (context_) {
    nvgSave(context_);
  }
}

inline Scope::~Scope() {
  if (context_) {
    nvgRestore(context_);
  }
}

}  // namespace nanovg

namespace nvg = nanovg;

}  // namespace takram

#endif  // TAKRAM_NANOVG_SCOPE_H_
