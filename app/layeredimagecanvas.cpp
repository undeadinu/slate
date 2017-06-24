/*
    Copyright 2017, Mitch Curtis

    This file is part of Slate.

    Slate is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Slate is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Slate. If not, see <http://www.gnu.org/licenses/>.
*/

#include "layeredimagecanvas.h"

#include <QLoggingCategory>

#include "imagelayer.h"
#include "layeredimageproject.h"

LayeredImageCanvas::LayeredImageCanvas() :
    mLayeredImageProject(nullptr)
{
    qCDebug(lcCanvasLifecycle) << "constructing" << this;
}

LayeredImageCanvas::~LayeredImageCanvas()
{
    qCDebug(lcCanvasLifecycle) << "destructing" << this;
}

void LayeredImageCanvas::connectSignals()
{
    ImageCanvas::connectSignals();

    mLayeredImageProject = qobject_cast<LayeredImageProject*>(mProject);
    Q_ASSERT_X(mLayeredImageProject, Q_FUNC_INFO, "Non-layered image project set on LayeredImageCanvas");
}

void LayeredImageCanvas::disconnectSignals()
{
    mLayeredImageProject = nullptr;
}

QImage *LayeredImageCanvas::currentProjectImage()
{
    return mLayeredImageProject->currentLayer()->image();
}