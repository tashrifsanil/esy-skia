/*
 * Copyright 2016 Xamarin Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// EXPERIMENTAL EXPERIMENTAL EXPERIMENTAL EXPERIMENTAL
// DO NOT USE -- FOR INTERNAL TESTING ONLY

#ifndef sk_svg_DEFINED
#define sk_svg_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_canvas_t* sk_svgcanvas_create(const sk_rect_t* bounds, sk_xmlwriter_t* writer);

SK_C_API sk_svgdom_t* sk_svgdom_create_from_stream(sk_stream_t* stream);
SK_C_API void sk_svgdom_unref(const sk_svgdom_t* dom);
SK_C_API void sk_svgdom_get_container_size(const sk_svgdom_t* dom, sk_size_t* size);
SK_C_API void sk_svgdom_set_container_size(sk_svgdom_t* dom, const sk_size_t* size);
SK_C_API void sk_svgdom_render(sk_svgdom_t* dom, sk_canvas_t* canvas);

SK_C_PLUS_PLUS_END_GUARD

#endif
