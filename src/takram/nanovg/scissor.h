//
//  takram/nanovg/scissor.h
//
//  The MIT License
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
#ifndef TAKRAM_NANOVG_SCISSOR_H_
#define TAKRAM_NANOVG_SCISSOR_H_

#include "nanovg.h"

#include "takram/nanovg/context.h"
#include "takram/nanovg/types.h"

namespace takram {
namespace nanovg {

// Scissoring
void scissor(Real width, Real height);
void scissor(const Size& size);
void scissor(Real x, Real y, Real width, Real height);
void scissor(const Vec& vec, const Size& size);
void scissor(const Rect& rect);

// Intersecting
void intersectScissor(Real width, Real height);
void intersectScissor(const Size& size);
void intersectScissor(Real x, Real y, Real width, Real height);
void intersectScissor(const Vec& vec, const Size& size);
void intersectScissor(const Rect& rect);

// Resetting
void resetScissor();

#pragma mark -

inline void scissor(Real width, Real height) {
  nvgScissor(Context::current(), Real(), Real(), width, height);
}

inline void scissor(const Size& size) {
  nvgScissor(Context::current(), Real(), Real(), size.w, size.h);
}

inline void scissor(Real x, Real y, Real width, Real height) {
  nvgScissor(Context::current(), x, y, width, height);
}

inline void scissor(const Vec& vec, const Size& size) {
  nvgScissor(Context::current(), vec.x, vec.y, size.w, size.h);
}

inline void scissor(const Rect& rect) {
  nvgScissor(Context::current(), rect.x, rect.y, rect.w, rect.h);
}

inline void intersectScissor(Real width, Real height) {
  nvgIntersectScissor(Context::current(), Real(), Real(), width, height);
}

inline void intersectScissor(const Size& size) {
  nvgIntersectScissor(Context::current(), Real(), Real(), size.w, size.h);
}

inline void intersectScissor(Real x, Real y, Real width, Real height) {
  nvgIntersectScissor(Context::current(), x, y, width, height);
}

inline void intersectScissor(const Vec& vec, const Size& size) {
  nvgIntersectScissor(Context::current(), vec.x, vec.y, size.w, size.h);
}

inline void intersectScissor(const Rect& rect) {
  nvgIntersectScissor(Context::current(), rect.x, rect.y, rect.w, rect.h);
}

inline void resetScissor() {
  nvgResetScissor(Context::current());
}

}  // namespace nanovg

namespace nvg = nanovg;

}  // namespace takram

#endif  // TAKRAM_NANOVG_SCISSOR_H_
