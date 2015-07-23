//
//  takram/nanovg/text.h
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
#ifndef TAKRAM_NANOVG_TEXT_H_
#define TAKRAM_NANOVG_TEXT_H_

#include <string>
#include <utility>

#include "nanovg.h"

#include "takram/nanovg/context.h"
#include "takram/nanovg/types.h"

namespace takram {
namespace nanovg {

// Font creation
int createFont(const std::string& name, const std::string& filename);
int findFont(const std::string& name);

// Font settings
void fontSize(Real size);
void fontBlur(Real blur);
  
// Text settings
void textLetterSpacing(Real spacing);
void textLineHeight(Real height);
void textAlign(Align align);

// Font face
void fontFace(int font);
void fontFace(const std::string& font);

// Text
Real text(const std::string& text);
Real text(Real x, Real y, const std::string& text);
Real text(const Vec& vec, const std::string& text);
  
// Text box
void textBox(Real width, const std::string& text);
void textBox(Real x, Real y, Real width, const std::string& text);
void textBox(const Vec& vec, Real width, const std::string& text);

// Bounds
std::pair<Real, Rect> textBounds(const std::string& text);
std::pair<Real, Rect> textBounds(Real x, Real y, const std::string& text);
std::pair<Real, Rect> textBounds(const Vec& vec, const std::string& text);

// Box bounds
Rect textBoxBounds(Real width, const std::string& text);
Rect textBoxBounds(Real x, Real y, Real width, const std::string& text);
Rect textBoxBounds(const Vec& vec, Real width, const std::string& text);

#pragma mark -

inline int createFont(const std::string& name, const std::string& filename) {
  return nvgCreateFont(Context::current(), name.c_str(), filename.c_str());
}

inline int findFont(const std::string& name) {
  return nvgFindFont(Context::current(), name.c_str());
}

inline void fontSize(Real size) {
  nvgFontSize(Context::current(), size);
}

inline void fontBlur(Real blur) {
  nvgFontBlur(Context::current(), blur);
}

inline void textLetterSpacing(Real spacing) {
  nvgTextLetterSpacing(Context::current(), spacing);
}

inline void textLineHeight(Real height) {
  nvgTextLineHeight(Context::current(), height);
}

inline void textAlign(Align align) {
  nvgTextAlign(Context::current(), align);
}

inline void fontFace(int font) {
  nvgFontFaceId(Context::current(), font);
}

inline void fontFace(const std::string& font) {
  nvgFontFace(Context::current(), font.c_str());
}

inline Real text(const std::string& text) {
  return nvgText(Context::current(), Real(), Real(), text.c_str(), nullptr);
}

inline Real text(Real x, Real y, const std::string& text) {
  return nvgText(Context::current(), x, y, text.c_str(), nullptr);
}

inline Real text(const Vec& vec, const std::string& text) {
  return nvgText(Context::current(), vec.x, vec.y, text.c_str(), nullptr);
}

inline void textBox(Real width, const std::string& text) {
  nvgTextBox(Context::current(), Real(), Real(), width, text.c_str(), nullptr);
}

inline void textBox(Real x, Real y, Real width, const std::string& text) {
  nvgTextBox(Context::current(), x, y, width, text.c_str(), nullptr);
}

inline void textBox(const Vec& vec, Real width, const std::string& text) {
  nvgTextBox(Context::current(), vec.x, vec.y, width, text.c_str(), nullptr);
}

inline std::pair<Real, Rect> textBounds(const std::string& text) {
  return textBounds(Real(), Real(), text);
}

inline std::pair<Real, Rect> textBounds(Real x, Real y,
                                        const std::string& text) {
  std::pair<Real, Rect> result;
  struct { Real xmin; Real ymin; Real xmax; Real ymax; } values;
  result.first = nvgTextBounds(Context::current(), x, y,
                               text.c_str(), nullptr, &values.xmin);
  result.second.set(Vec(values.xmin, values.ymin),
                    Vec(values.xmax, values.ymax));
  return std::move(result);
}

inline std::pair<Real, Rect> textBounds(const Vec& vec,
                                        const std::string& text) {
  return textBounds(vec.x, vec.y, text);
}

inline Rect textBoxBounds(Real width, const std::string& text) {
  return textBoxBounds(Real(), Real(), width, text);
}

inline Rect textBoxBounds(Real x, Real y, Real width, const std::string& text) {
  struct { Real xmin; Real ymin; Real xmax; Real ymax; } values;
  nvgTextBoxBounds(Context::current(), x, y, width,
                   text.c_str(), nullptr, &values.xmin);
  return Rect(Vec(values.xmin, values.ymin), Vec(values.xmax, values.ymax));
}

inline Rect textBoxBounds(const Vec& vec, Real width, const std::string& text) {
  return textBoxBounds(vec.x, vec.y, width, text);
}

}  // namespace nanovg

namespace nvg = nanovg;

}  // namespace takram

#endif  // TAKRAM_NANOVG_STYLE_H_
