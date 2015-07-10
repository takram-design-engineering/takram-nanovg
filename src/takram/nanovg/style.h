//
//  takram/nanovg/style.h
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
#ifndef TAKRAM_NANOVG_STYLE_H_
#define TAKRAM_NANOVG_STYLE_H_

#include "nanovg.h"

#include "takram/nanovg/context.h"
#include "takram/nanovg/types.h"

namespace takram {
namespace nanovg {

// Stroke
void strokeColor(const Color& color);
void strokePaint(const Paint& paint);

// Fill
void fillColor(const Color& color);
void fillPaint(const Paint& paint);

// Stroke settings
void miterLimit(Real limit);
void strokeWidth(Real size);
void lineCap(LineCap cap);
void lineJoin(LineCap join);

// Global settings
void globalAlpha(Real alpha);

#pragma mark -

inline void strokeColor(const Color& color) {
  nvgStrokeColor(Context::current(), color);
}

inline void strokePaint(const Paint& paint) {
  nvgStrokePaint(Context::current(), paint);
}

inline void fillColor(const Color& color) {
  nvgFillColor(Context::current(), color);
}

inline void fillPaint(const Paint& paint) {
  nvgFillPaint(Context::current(), paint);
}

inline void miterLimit(Real limit) {
  nvgMiterLimit(Context::current(), limit);
}

inline void strokeWidth(Real size) {
  nvgStrokeWidth(Context::current(), size);
}

inline void lineCap(LineCap cap) {
  nvgLineCap(Context::current(), cap);
}

inline void lineJoin(LineCap join) {
  nvgLineJoin(Context::current(), join);
}

inline void globalAlpha(Real alpha) {
  nvgGlobalAlpha(Context::current(), alpha);
}

}  // namespace nanovg

namespace nvg = nanovg;

}  // namespace takram

#endif  // TAKRAM_NANOVG_STYLE_H_
