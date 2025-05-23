/**
 * Copyright (c) 2011-2018 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */

#ifndef RGRAPHICSVIEWIMAGE_H
#define RGRAPHICSVIEWIMAGE_H

#include "gui_global.h"

#include <QMutex>
#include <QTransform>

#include "RGraphicsSceneDrawable.h"
#include "RGraphicsView.h"
#include "RPainterPath.h"

class RAction;
class RColor;
class RBox;
class RDocument;
class RDocumentInterface;
class RGraphicsScene;
class RGraphicsSceneQt;
class RGraphicsViewImage;
class RGraphicsViewQt;
class RGraphicsViewWorker;
class RGrid;
class RImageData;
class RLine;
class RMouseEvent;
class RObject;
class RPainterPath;
class RRefPoint;
class RShape;
class RSnap;
class RSnapRestriction;
class RTabletEvent;
class RTerminateEvent;
class RTextBasedData;
class RTextLabel;
class RTextLayout;
class RTransform;
class RVector;
class RWheelEvent;

/**
 * \brief QImage based 2d graphics view.
 *
 * This graphics view renders a rectangular area of a RGraphicsSceneQt into a QImage.
 *
 * \ingroup gui
 * \scriptable
 */
class QCADGUI_EXPORT RGraphicsViewImage : public QObject, public RGraphicsView {
    Q_OBJECT

public:
    RGraphicsViewImage(QObject* parent=NULL);
    virtual ~RGraphicsViewImage();

    int getNumThreads() const {
        return numThreads;
    }
    void setNumThreads(int n);

    void clear();

    virtual void setCursor(Qt::CursorShape cursorShape);
    virtual void setCursor(const QCursor& cursor);

    virtual QCursor getCursor();

    // TODO: these methods are not found in RGraphicsViewQt, due to the
    // multiple inheritance of RGraphicsViewQt (QWidget and RGraphicsViewImage)
    // unless they are re-declared here again:
//    void setViewportNumber(int n) {
//        RGraphicsView::setViewportNumber(n);
//    }

//    int getViewportNumber() const {
//        return RGraphicsView::getViewportNumber();
//    }

//    void setNavigationAction(RAction* action) {
//        RGraphicsView::setNavigationAction(action);
//    }

//    RBox getBox() const {
//        return RGraphicsView::getBox();
//    }

//    void autoZoom(int margin = RDEFAULT_MIN1, bool ignoreEmpty=false, bool ignoreLineweight=false) {
//        RGraphicsView::autoZoom(margin, ignoreEmpty, ignoreLineweight);
//    }

//    void zoomTo(const RBox &window, int margin = 0) {
//        RGraphicsView::zoomTo(window, margin);
//    }

//    void zoom(const RVector& center, double factor) {
//        RGraphicsView::zoom(center, factor);
//    }

//    void pan(const RVector& delta, bool regen=true) {
//        RGraphicsView::pan(delta, regen);
//    }

//    void centerToBox(const RBox& box) {
//        RGraphicsView::centerToBox(box);
//    }

//    void centerToPoint(const RVector& point) {
//        RGraphicsView::centerToPoint(point);
//    }

//    void setGrid(RGrid* grid) {
//        RGraphicsView::setGrid(grid);
//    }

//    RGrid* getGrid() {
//        return RGraphicsView::getGrid();
//    }

//    double getFactor(bool includeStepFactor=true) const {
//        return RGraphicsView::getFactor(includeStepFactor);
//    }

//    void setFactor(double f, bool regen=true) {
//        RGraphicsView::setFactor(f, regen);
//    }

//    RVector getOffset(bool includeStepOffset=true) const {
//        return RGraphicsView::getOffset(includeStepOffset);
//    }

//    void setOffset(const RVector& offset, bool regen=true) {
//        RGraphicsView::setOffset(offset, regen);
//    }

//    QColor getBackgroundColor() {
//        return RGraphicsView::getBackgroundColor();
//    }

//    void setMargin(int m) {
//        RGraphicsView::setMargin(m);
//    }

//    void setColorMode(RGraphicsView::ColorMode cm) {
//        RGraphicsView::setColorMode(cm);
//    }

//    void setHairlineMode(bool on) {
//        RGraphicsView::setHairlineMode(on);
//    }

//    bool getHairlineMode() {
//        return RGraphicsView::getHairlineMode();
//    }

//    void setHairlineMinimumMode(bool on) {
//        RGraphicsView::setHairlineMinimumMode(on);
//    }

//    bool getHairlineMinimumMode() {
//        return RGraphicsView::getHairlineMinimumMode();
//    }

//    void setAntialiasing(bool on) {
//        RGraphicsView::setAntialiasing(on);
//    }

//    bool getAntialiasing() const {
//        return RGraphicsView::getAntialiasing();
//    }

//    RGraphicsScene* getScene() const {
//        return RGraphicsView::getScene();
//    }

//    RDocument* getDocument() const {
//        return RGraphicsView::getDocument();
//    }

//    RDocumentInterface* getDocumentInterface() const {
//        return RGraphicsView::getDocumentInterface();
//    }

//    void setExporting(bool on) {
//        RGraphicsView::setExporting(on);
//    }

//    bool isExporting() const {
//        return RGraphicsView::isExporting();
//    }

//    bool isPrintingOrExporting() const {
//        return RGraphicsView::isPrintingOrExporting();
//    }

//    void setPrinting(bool on) {
//        RGraphicsView::setPrinting(on);
//    }

//    bool isPrinting() const {
//        return RGraphicsView::isPrinting();
//    }

//    void setPrintPreview(bool on) {
//        RGraphicsView::setPrintPreview(on);
//    }

//    bool isPrintPreview() const {
//        return RGraphicsView::isPrintPreview();
//    }

//    void setPrintPointSize(const RVector& s) {
//        RGraphicsView::setPrintPointSize(s);
//    }

    virtual void simulateMouseMoveEvent();

//    void setTextHeightThresholdOverride(int v) {
//        RGraphicsView::setTextHeightThresholdOverride(v);
//    }

//    int getTextHeightThresholdOverride() const {
//        return RGraphicsView::getTextHeightThresholdOverride();
//    }

//    bool isGridVisible() const {
//        return RGraphicsView::isGridVisible();
//    }

//    void setGridVisible(bool on) {
//        RGraphicsView::setGridVisible(on);
//    }
    
    virtual void setScene(RGraphicsSceneQt* scene, bool regen=true);

    virtual void setBackgroundColor(const QColor& col);

    virtual void regenerate(bool force=false);
    virtual void repaintView();
    virtual void updateImage();

    virtual void giveFocus();
    virtual bool hasFocus();
    virtual void removeFocus();

    void saveViewport();
    void restoreViewport();

    virtual RVector mapFromView(const RVector& v, double z=0.0) const;
    virtual RVector mapToView(const RVector& v) const;
    virtual double mapDistanceFromView(double d) const;
    virtual double mapDistanceToView(double d) const;
    
    virtual int getWidth() const;
    virtual int getHeight() const;
    virtual void resizeImage(int w, int h);

    virtual void paintGridPoint(const RVector& ucsPosition);
    virtual void paintGridLine(const RLine& ucsPosition);
    virtual void paintCursorLine(const RLine& ucsPosition);

    void setPaintOrigin(bool val);

    void setPanOptimization(bool on);
    bool getPanOptimization();

    virtual void paintEntities(QPainter* painter, const RBox& queryBox);
    void paintEntitiesMulti(const RBox& queryBox);
    //void paintEntitiesThread(int threadId, const QList<RObject::Id>& list, int start, int end);
    //void paintDrawablesThread(int threadId, const QList<RGraphicsSceneDrawable>& list, int start, int end);

    virtual void paintEntityThread(RGraphicsViewWorker* worker, RObject::Id id, bool preview = false);
    virtual void paintDrawableThread(RGraphicsViewWorker* worker, RGraphicsSceneDrawable& drawable, const RBox& clipRectangle, bool preview = false);

    virtual void paintOverlay();

    QImage getBuffer() const;
    QTransform getTransform() const;

    void clearBackground();
    void addToBackground(const RGraphicsSceneDrawable& drawable);
    void setBackgroundTransform(double bgFactor, const RVector& bgOffset);

    void clearOverlay(int overlayId);
    void clearOverlay(int overlayId, RObject::Id objectId);
    void addToOverlay(int overlayId, RObject::Id objectId, const RGraphicsSceneDrawable& drawable);

    void setColorCorrectionOverride(bool on) {
        colorCorrectionOverride = (int)on;
    }

    bool getColorCorrectionOverride() const {
        return (colorCorrectionOverride!=0);
    }

    void setMinimumLineweight(double lw) {
        minimumLineweight = lw;
    }

    double getMinimumLineweight() const {
        return minimumLineweight;
    }

    void setMaximumLineweight(double lw) {
        maximumLineweight = lw;
    }

    double getMaximumLineweight() const {
        return maximumLineweight;
    }

    void setPaintOffset(const RVector& offset) {
        paintOffset = offset;
    }

    RVector getPaintOffset() const {
        return paintOffset;
    }

    bool isAlphaEnabled() const {
        return alphaEnabled;
    }

    void setAlphaEnabled(bool on) {
        alphaEnabled = on;
    }

    double getDrawingScale() const {
        return drawingScale;
    }
    void setDrawingScale(double s) {
        drawingScale = s;
    }

    QImage getGraphicsBufferWithPreview() const {
        return graphicsBufferWithPreview;
    }

    RVector getLastKnownScreenPosition() const {
        return lastKnownScreenPosition;
    }

    void setLastKnownScreenPosition(const RVector& p) {
        lastKnownScreenPosition = p;
    }

    void setLastKnownModelPosition(const RVector& p) {
        lastKnownModelPosition = p;
    }

    virtual bool isShared() const {
        // never delete image view:
        // owned by creator
        return true;
    }

    virtual bool registerForFocus() const {
        return true;
    }

    virtual void viewportChangeEvent();

    virtual void emitUpdateSnapInfo(RSnap* snap, RSnapRestriction* restriction);
    virtual void emitUpdateTextLabel(const RTextLabel& textLabel);

    virtual double getDevicePixelRatio() const;

    virtual void paintImage(RGraphicsViewWorker* worker, const RImageData& image, bool workingSet = true);
    virtual void paintText(RGraphicsViewWorker* worker, const RTextBasedData& text, bool workingSet = true);

protected:
    QList<RPainterPath> getTextLayoutsPainterPaths(const RTextBasedData& text, const QList<RTextLayout>& textLayouts);
    void applyMinimumLineweight(QPen& pen);
    void applyColorCorrection(QPen& pen);
    void applyColorCorrection(QBrush& brush);
    void applyColorMode(QPen& pen);
    void applyColorMode(QBrush& brush);
    double getPointSize(double pSize);
    virtual void drawDot(RGraphicsViewWorker* worker, QPointF pt);
    virtual void drawPlus(RGraphicsViewWorker* worker, QPointF pt, double pSize);
    virtual void drawEx(RGraphicsViewWorker* worker, QPointF pt, double pSize);
    virtual void drawVBar(RGraphicsViewWorker* worker, QPointF pt, double pSize);
    virtual void drawCircle(RGraphicsViewWorker* worker, QPointF pt, double pSize);
    virtual void drawSquare(RGraphicsViewWorker* worker, QPointF pt, double pSize);

    virtual void paintOrigin(RGraphicsViewWorker* worker);
    virtual void paintReferencePoint(RGraphicsViewWorker* worker, const RRefPoint& pos, bool highlight);
    virtual void paintErase(RGraphicsViewWorker* worker, const QRect& rect = QRect());
    virtual void paintGrid(RGraphicsViewWorker* worker, const QRect& rect = QRect());
    virtual void paintMetaGrid(RGraphicsViewWorker* worker, const QRect& rect = QRect());
    virtual void paintCursor(RGraphicsViewWorker* worker);
    virtual void paintRelativeZero(RGraphicsViewWorker* worker);
    virtual void paintDocument(const QRect& rect = QRect());
    virtual void paintBackground(RGraphicsViewWorker* worker, const QRect& rect = QRect());

    virtual void endPaint() const;
    virtual void setBrush(const QBrush& brush) const;
    virtual void setPen(const QPen& pen) const;
    virtual void drawLine(const QLineF& line) const;

    /**
     * \nonscriptable
     */
    void initPainter(QPaintDevice& device, bool erase, bool screen = false, const QRect& rect = QRect());

    void invalidate(bool force=false);
    virtual void initWorkers();
    virtual RGraphicsViewWorker* initWorker(int threadId);
    void updateTransformation() const;

signals:
    void viewportChanged();
    void updateSnapInfo(RGraphicsViewWorker* worker, RSnap* snap, RSnapRestriction* restriction);
    void updateTextLabel(RGraphicsViewWorker* worker, const RTextLabel& textLabel);

protected:
    //QList<QImage> graphicsBufferThread;
    //QList<QPainter*> painterThread;

    // graphics buffer with current drawing rendered into it, without preview:
    QImage graphicsBuffer;
    // graphics buffer with current drawing rendered into it, with preview:
    QImage graphicsBufferWithPreview;

    int numThreads;

protected:
    bool panOptimization;
    QMutex mutexSi;

    RGraphicsSceneQt* sceneQt;
    double currentScale;
    QSize lastSize;
    RVector lastOffset;
    double lastFactor;
    bool graphicsBufferNeedsUpdate;
    mutable QTransform transform;
    QTransform previousView;

    QPainter* painter;
    bool doPaintOrigin;

    bool isSelected;
    QSet<RObject::Id> selectedIds;
    int bgColorLightness;

    int colorCorrectionOverride;
    bool colorCorrection;
    bool colorCorrectionDisableForPrinting;
    int colorThreshold;

    double minimumLineweight;
    double maximumLineweight;

//    int textHeightThresholdOverride;
//    int textHeightThreshold;

    double drawingScale;

    QList<RGraphicsSceneDrawable> backgroundDecoration;
    //QTransform backgroundTransform;
    double backgroundFactor;
    RVector backgroundOffset;

    QMap<int, QMap<RObject::Id, QList<RGraphicsSceneDrawable> > > overlayDrawables;

    RBox clipBox;
    //QList<QStack<RTransform> > entityTransformThread;
    RVector paintOffset;
    bool alphaEnabled;

    QString lastScaleString;

    bool showOnlyPlottable;

    QList<RGraphicsViewWorker*> workers;
    RGraphicsViewWorker* decorationWorker;
};

Q_DECLARE_METATYPE(RGraphicsViewImage*)

#endif
