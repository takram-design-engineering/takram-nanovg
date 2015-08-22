//
//  takram/nanovg/types.h
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
#ifndef TAKRAM_NANOVG_TYPES_H_
#define TAKRAM_NANOVG_TYPES_H_

#include "nanovg.h"

#include "takram/math/rectangle.h"
#include "takram/math/size.h"
#include "takram/math/vector.h"

namespace takram {
namespace nanovg {

using Real = float;
using Vec = Vec2<Real>;
using Size = Size2<Real>;
using Rect = Rect2<Real>;

using Color = NVGcolor;
using Paint = NVGpaint;
using GlyphPosition = NVGglyphPosition;
using TextRow = NVGtextRow;

enum Winding {
  CCW = NVG_CCW,
  CW = NVG_CW
};

enum Solidity {
  SOLID = NVG_SOLID,
  HOLE = NVG_HOLE
};

enum LineCap {
  BUTT = NVG_BUTT,
  ROUND = NVG_ROUND,
  SQUARE = NVG_SQUARE,
  BEVEL = NVG_BEVEL,
  MITER = NVG_MITER
};

enum Align {
  LEFT = NVG_ALIGN_LEFT,
  CENTER = NVG_ALIGN_CENTER,
  RIGHT = NVG_ALIGN_RIGHT,
  TOP = NVG_ALIGN_TOP,
  MIDDLE = NVG_ALIGN_MIDDLE,
  BOTTOM = NVG_ALIGN_BOTTOM,
  BASELINE = NVG_ALIGN_BASELINE,
};

enum ImageFlag {
  GENERATE_MIPMAPS = NVG_IMAGE_GENERATE_MIPMAPS,
  REPEAT_X = NVG_IMAGE_REPEATX,
  REPEAT_Y = NVG_IMAGE_REPEATY,
  REPEAT = REPEAT_X | REPEAT_Y,
  FLIPY = NVG_IMAGE_FLIPY,
  PREMULTIPLIED = NVG_IMAGE_PREMULTIPLIED
};

}  // namespace nanovg

namespace nvg = nanovg;

}  // namespace takram

#endif  // TAKRAM_NANOVG_TYPES_H_
