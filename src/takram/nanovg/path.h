//
//  takram/nanovg/path.h
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
#ifndef TAKRAM_NANOVG_PATH_H_
#define TAKRAM_NANOVG_PATH_H_

#include "nanovg.h"

#include "takram/nanovg/context.h"
#include "takram/nanovg/types.h"

namespace takram {
namespace nanovg {

// Low-level path operations
void beginPath();
void moveTo(Real x, Real y);
void moveTo(const Vec& point);
void lineTo(Real x, Real y);
void lineTo(const Vec& point);
void quadTo(Real cx, Real cy, Real x, Real y);
void quadTo(const Vec& control, const Vec& point);
void cubicTo(Real cx1, Real cy1, Real cx2, Real cy2, Real x, Real y);
void cubicTo(const Vec& control1, const Vec& control2, const Vec& point);
void closePath();
void pathWinding(int direction);

// Rect
void rect(Real width, Real height);
void rect(const Size& size);
void rect(Real x, Real y, Real width, Real height);
void rect(const Vec& vec, const Size& size);
void rect(const Rect& rect);

// Rounded rect
void roundedRect(Real x, Real y, Real width, Real height, Real radius);
void roundedRect(const Vec& vec, const Size& size, Real radius);
void roundedRect(const Rect& rect, Real radius);

// Ellipse
void ellipse(Real x, Real y, Real width, Real height);
void ellipse(const Vec& vec, const Size& size);
void ellipse(const Rect& rect);

// Circle
void circle(Real x, Real y, Real radius);
void circle(const Vec& vec, Real radius);

// Drawing
void fill();
void stroke();

#pragma mark -

inline void beginPath() {
  nvgBeginPath(Context::current());
}

inline void moveTo(Real x, Real y) {
  nvgMoveTo(Context::current(), x, y);
}

inline void moveTo(const Vec& point) {
  nvgMoveTo(Context::current(), point.x, point.y);
}

inline void lineTo(Real x, Real y) {
  nvgLineTo(Context::current(), x, y);
}

inline void lineTo(const Vec& point) {
  nvgLineTo(Context::current(), point.x, point.y);
}

inline void quadTo(Real cx, Real cy, Real x, Real y) {
  nvgQuadTo(Context::current(), cx, cy, x, y);
}

inline void quadTo(const Vec& control, const Vec& point) {
  nvgQuadTo(Context::current(), control.x, control.y, point.x, point.y);
}

inline void cubicTo(Real cx1, Real cy1, Real cx2, Real cy2, Real x, Real y) {
  nvgBezierTo(Context::current(), cx1, cy1, cx2, cy2, x, y);
}

inline void cubicTo(const Vec& control1,
                    const Vec& control2,
                    const Vec& point) {
  nvgBezierTo(Context::current(),
              control1.x, control1.y,
              control2.x, control2.y,
              point.x, point.y);
}

inline void closePath() {
  nvgClosePath(Context::current());
}

inline void pathWinding(int direction) {
  nvgPathWinding(Context::current(), direction);
}

inline void rect(Real width, Real height) {
  nvgRect(Context::current(), Real(), Real(), width, height);
}

inline void rect(const Size& size) {
  nvgRect(Context::current(), Real(), Real(), size.w, size.h);
}

inline void rect(float x, float y, float width, float height) {
  nvgRect(Context::current(), x, y, width, height);
}

inline void rect(const Vec& vec, const Size& size) {
  nvgRect(Context::current(), vec.x, vec.y, size.w, size.h);
}

inline void rect(const Rect& rect) {
  nvgRect(Context::current(), rect.x, rect.y, rect.w, rect.h);
}

inline void roundedRect(Real x, Real y, Real width, Real height, Real radius) {
  nvgRoundedRect(Context::current(), x, y, width, height, radius);
}

inline void roundedRect(const Vec& vec, const Size& size, Real radius) {
  nvgRoundedRect(Context::current(), vec.x, vec.y, size.w, size.h, radius);
}

inline void roundedRect(const Rect& rect, Real radius) {
  nvgRoundedRect(Context::current(), rect.x, rect.y, rect.w, rect.h, radius);
}

inline void ellipse(Real x, Real y, Real width, Real height) {
  nvgEllipse(Context::current(), x, y, width, height);
}

inline void ellipse(const Vec& vec, const Size& size) {
  nvgEllipse(Context::current(), vec.x, vec.y, size.w, size.h);
}

inline void ellipse(const Rect& rect) {
  nvgEllipse(Context::current(), rect.x, rect.y, rect.w, rect.h);
}

inline void circle(Real x, Real y, Real radius) {
  nvgCircle(Context::current(), x, y, radius);
}

inline void circle(const Vec& vec, Real radius) {
  nvgCircle(Context::current(), vec.x, vec.y, radius);
}

inline void fill() {
  nvgFill(Context::current());
}

inline void stroke() {
  nvgStroke(Context::current());
}

}  // namespace nanovg

namespace nvg = nanovg;

}  // namespace takram

#endif  // TAKRAM_NANOVG_PATH_H_
