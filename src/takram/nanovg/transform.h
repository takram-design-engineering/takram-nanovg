//
//  takram/nanovg/transform.h
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
#ifndef TAKRAM_NANOVG_TRANSFORM_H_
#define TAKRAM_NANOVG_TRANSFORM_H_

#include "nanovg.h"

#include "takram/nanovg/context.h"
#include "takram/nanovg/types.h"

namespace takram {
namespace nanovg {

// Translation
void translateX(Real dx);
void translateY(Real dy);
void translate(Real value);
void translate(Real dx, Real dy);
void translate(const Vec& vec);

// Rotation
void rotate(Real angle);
void rotate(Real angle, const Vec& vec);

// Scaling
void scaleX(Real sx);
void scaleY(Real sy);
void scale(Real value);
void scale(Real sx, Real sy);
void scale(const Vec& vec);

// Skewing
void skewX(Real angle);
void skewY(Real angle);

#pragma mark -

inline void translateX(Real dx) {
  nvgTranslate(Context::current(), dx, 0.0);
}

inline void translateY(Real dy) {
  nvgTranslate(Context::current(), 0.0, dy);
}

inline void translate(Real value) {
  nvgTranslate(Context::current(), value, value);
}

inline void translate(Real dx, Real dy) {
  nvgTranslate(Context::current(), dx, dy);
}

inline void translate(const Vec& vec) {
  nvgTranslate(Context::current(), vec.x, vec.y);
}

inline void rotate(Real angle) {
  nvgRotate(Context::current(), angle);
}

inline void rotate(Real angle, const Vec& vec) {
  nvgTranslate(Context::current(), vec.x, vec.y);
  nvgRotate(Context::current(), angle);
  nvgTranslate(Context::current(), -vec.x, -vec.y);
}

inline void scaleX(Real sx) {
  nvgScale(Context::current(), sx, 1.0);
}

inline void scaleY(Real sy) {
  nvgScale(Context::current(), 1.0, sy);
}

inline void scale(Real value) {
  nvgScale(Context::current(), value, value);
}

inline void scale(Real sx, Real sy) {
  nvgScale(Context::current(), sx, sy);
}

inline void scale(const Vec& vec) {
  nvgScale(Context::current(), vec.x, vec.y);
}

inline void skewX(Real angle) {
  nvgSkewX(Context::current(), angle);
}

inline void skewY(Real angle) {
  nvgSkewY(Context::current(), angle);
}

}  // namespace nanovg

namespace nvg = nanovg;

}  // namespace takram

#endif  // TAKRAM_NANOVG_TRANSFORM_H_
