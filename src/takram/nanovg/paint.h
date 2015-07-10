//
//  takram/nanovg/paint.h
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
#ifndef TAKRAM_NANOVG_PAINT_H_
#define TAKRAM_NANOVG_PAINT_H_

#include "nanovg.h"

#include "takram/nanovg/context.h"
#include "takram/nanovg/types.h"

namespace takram {
namespace nanovg {

// Linear gradient
Paint linearGradient(Real start_x, Real start_y, Real stop_x, Real stop_y,
                     const Color& start_color, const Color& stop_color);
Paint linearGradient(const Vec& start, const Vec& stop,
                     const Color& start_color, const Color& stop_color);

// Box gradient
Paint boxGradient(Real x, Real y, Real width, Real height,
                  Real radius, Real feather,
                  const Color& start_color, const Color& stop_color);
Paint boxGradient(const Vec& vec, const Size& size,
                  Real radius, Real feather,
                  const Color& start_color, const Color& stop_color);
Paint boxGradient(const Rect& rect, Real radius, Real feather,
                  const Color& start_color, const Color& stop_color);

// Radial gradient
Paint radialGradient(Real x, Real y, Real start_radius, Real stop_radius,
                     const Color& start_color, const Color& stop_color);
Paint radialGradient(const Vec& vec, Real start_radius, Real stop_radius,
                     const Color& start_color, const Color& stop_color);

// Image pattern
Paint imagePattern(Real x, Real y, Real width, Real height,
                    Real angle, int image, Real alpha);
Paint imagePattern(const Vec& vec, const Size& size,
                   Real angle, int image, Real alpha);
Paint imagePattern(const Rect& rect, Real angle, int image, Real alpha);

#pragma mark -

inline Paint linearGradient(Real start_x, Real start_y,
                            Real stop_x, Real stop_y,
                            const Color& start_color, const Color& stop_color) {
  return nvgLinearGradient(Context::current(), start_x, start_y, stop_x, stop_y,
                           start_color, stop_color);
}

inline Paint linearGradient(const Vec& start, const Vec& stop,
                            const Color& start_color, const Color& stop_color) {
  return nvgLinearGradient(Context::current(), start.x, start.y, stop.x, stop.y,
                           start_color, stop_color);
}

inline Paint boxGradient(Real x, Real y, Real width, Real height,
                         Real radius, Real feather,
                         const Color& start_color, const Color& stop_color) {
  return nvgBoxGradient(Context::current(), x, y, width, height,
                        radius, feather, start_color, stop_color);
}

inline Paint boxGradient(const Vec& vec, const Size& size,
                         Real radius, Real feather,
                         const Color& start_color, const Color& stop_color) {
  return nvgBoxGradient(Context::current(), vec.x, vec.y, size.w, size.h,
                        radius, feather, start_color, stop_color);
}

inline Paint boxGradient(const Rect& rect, Real radius, Real feather,
                         const Color& start_color, const Color& stop_color) {
  return nvgBoxGradient(Context::current(), rect.x, rect.y, rect.w, rect.h,
                        radius, feather, start_color, stop_color);
}

inline Paint radialGradient(Real x, Real y, Real start_radius, Real stop_radius,
                            const Color& start_color, const Color& stop_color) {
  return nvgRadialGradient(Context::current(), x, y,
                           start_radius, stop_radius, start_color, stop_color);
}

inline Paint radialGradient(const Vec& vec, Real start_radius, Real stop_radius,
                            const Color& start_color, const Color& stop_color) {
  return nvgRadialGradient(Context::current(), vec.x, vec.y,
                           start_radius, stop_radius, start_color, stop_color);
}

inline Paint imagePattern(Real x, Real y, Real width, Real height,
                          Real angle, int image, Real alpha) {
  return nvgImagePattern(Context::current(), x, y, width, height,
                         angle, image, alpha);
}

inline Paint imagePattern(const Vec& vec, const Size& size,
                          Real angle, int image, Real alpha) {
  return nvgImagePattern(Context::current(), vec.x, vec.y, size.w, size.h,
                         angle, image, alpha);
}

inline Paint imagePattern(const Rect& rect, Real angle, int image, Real alpha) {
  return nvgImagePattern(Context::current(), rect.x, rect.y, rect.w, rect.h,
                         angle, image, alpha);
}

}  // namespace nanovg

namespace nvg = nanovg;

}  // namespace takram

#endif  // TAKRAM_NANOVG_PAINT_H_
