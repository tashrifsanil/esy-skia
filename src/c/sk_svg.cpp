/*
 * Copyright 2016 Xamarin Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkSVGCanvas.h"
#include "../../experimental/svg/model/SkSVGDOM.h"

#include "sk_svg.h"

#include "sk_types_priv.h"

//////////////////////////////////////////////////////////////////////////////////////////////////

sk_canvas_t* sk_svgcanvas_create(const sk_rect_t* bounds, sk_xmlwriter_t* writer)
{
    return ToCanvas(SkSVGCanvas::Make(AsRect(*bounds), AsXMLWriter(writer)).release());
}

sk_svgdom_t* sk_svgdom_create_from_stream(sk_stream_t* stream)
{
    return ToSvgDom(SkSVGDOM::MakeFromStream(AsStream(*stream)).release());
}

void sk_svgdom_unref(const sk_svgdom_t* dom) {
    SkSafeUnref(AsSvgDom(dom));
}

void sk_svgdom_get_container_size(const sk_svgdom_t* dom, sk_size_t* size)
{
    if (size) {
        const SkSize& skSize = AsSvgDom(dom)->containerSize();
        *size = { skSize.fWidth, skSize.fHeight };
    }
}

void sk_svgdom_set_container_size(sk_svgdom_t* dom, const sk_size_t* size)
{
    AsSvgDom(dom)->setContainerSize(AsSize(*size));
}

void sk_svgdom_render(sk_svgdom_t* dom, sk_canvas_t* canvas)
{
    AsSvgDom(dom)->render(AsCanvas(canvas));
}
