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

#ifndef RPOLYLINEDATA_H
#define RPOLYLINEDATA_H

#include "entity_global.h"

#include "RBox.h"
#include "REntityData.h"
#include "RPolyline.h"
#include "RVector.h"

class RDocument;
class RLine;
class RRefPoint;

#ifndef RDEFAULT_MIN1
#define RDEFAULT_MIN1 -1
#endif

/**
 * Stores and manages all data that defines the geometry and
 * appearance of a polyline entity.
 *
 * \scriptable
 * \copyable
 * \ingroup entity
 */
class QCADENTITY_EXPORT RPolylineData: public REntityData, public RPolyline {

    friend class RPolylineEntity;

protected:
    RPolylineData(RDocument* document, const RPolylineData& data);

public:
    RPolylineData();

    /**
     * \nonscriptable
     */
    RPolylineData(RDocument* document);

    RPolylineData(const RPolyline& polyline);

    virtual RS::EntityType getType() const {
        return RS::EntityPolyline;
    }

    bool isValid() const {
        return RPolyline::isValid();
    }
    virtual QList<RVector> getEndPoints(const RBox& queryBox = RDEFAULT_RBOX, QList<RObject::Id>* subEntityIds = NULL) const {
        return REntityData::getEndPoints(queryBox, subEntityIds);
    }
    virtual void setZ(double z) {
        RPolyline::setZ(z);
    }
    virtual void to2D() {
        RPolyline::to2D();
    }
    virtual RBox getBoundingBox(bool ignoreEmpty=false) const {
        return REntityData::getBoundingBox();
    }
    virtual QList<RVector> getMiddlePoints(const RBox& queryBox = RDEFAULT_RBOX, QList<RObject::Id>* subEntityIds = NULL) const {
        return REntityData::getMiddlePoints(queryBox, subEntityIds);
    }
    virtual QList<RVector> getCenterPoints(const RBox& queryBox = RDEFAULT_RBOX, QList<RObject::Id>* subEntityIds = NULL) const {
        return REntityData::getCenterPoints(queryBox, subEntityIds);
    }
    virtual QList<RVector> getArcReferencePoints(const RBox& queryBox = RDEFAULT_RBOX) const {
        return REntityData::getArcReferencePoints(queryBox);
    }
    virtual QList<RVector> getPointsWithDistanceToEnd(double distance, int from = RS::FromAny, const RBox& queryBox = RDEFAULT_RBOX, QList<RObject::Id>* subEntityIds = NULL) const {
        return REntityData::getPointsWithDistanceToEnd(distance, from, queryBox, subEntityIds);
    }
    virtual QList<RVector> getIntersectionPoints(const RShape& shape, bool limited = true, const RBox& queryBox = RDEFAULT_RBOX, bool ignoreComplex = true) const {
        return REntityData::getIntersectionPoints(shape, limited, queryBox, ignoreComplex);
    }
    virtual RVector getVectorTo(const RVector& point, bool limited=true, double strictRange = RMAXDOUBLE) const {
        return REntityData::getVectorTo(point, limited, strictRange);
    }
    virtual bool intersectsWith(const RShape& shape) const {
        return REntityData::intersectsWith(shape);
    }
    virtual bool move(const RVector& offset) {
        return RPolyline::move(offset);
    }
    virtual bool rotate(double rotation, const RVector& center = RDEFAULT_RVECTOR) {
        return RPolyline::rotate(rotation, center);
    }
    virtual bool scale(const RVector& scaleFactors, const RVector& center = RDEFAULT_RVECTOR) {
        return RPolyline::scale(scaleFactors, center);
    }
    virtual bool mirror(const RLine& axis) {
        return RPolyline::mirror(axis);
    }
    virtual bool mirror(const RVector& axis1, const RVector& axis2) {
        return REntityData::mirror(axis1, axis2);
    }
    virtual bool flipHorizontal() {
        return REntityData::flipHorizontal();
    }
    virtual bool flipVertical() {
        return REntityData::flipVertical();
    }
    virtual bool stretch(const RPolyline& area, const RVector& offset) {
        return RPolyline::stretch(area, offset);
    }
    virtual QList<RBox> getBoundingBoxes(bool ignoreEmpty=false) const;

    virtual QList<RRefPoint> getReferencePoints(RS::ProjectionRenderingHint hint = RS::RenderTop) const;

    virtual bool moveReferencePoint(const RVector& referencePoint, const RVector& targetPoint, Qt::KeyboardModifiers modifiers = Qt::NoModifier);

    virtual RShape* castToShape() {
        return this;
    }

    virtual double getDistanceTo(const RVector& point, bool limited = true, double range = 0.0, bool draft = false, double strictRange = RMAXDOUBLE) const {
        if (!hasWidths()) {
            return REntityData::getDistanceTo(point, limited, range, draft, strictRange);
        }

        // polylines with custom segment widths:
        double ret = RPolyline::getDistanceTo(point, limited, strictRange);
        if (ret>range) {
            return RNANDOUBLE;
        }
        return ret;
    }

    RPolyline getPolylineShape() const {
        return *this;
    }

    void clear() {
        RPolyline::clear();
    }

    void normalize(double tolerance = RS::PointTolerance) {
        RPolyline::normalize(tolerance);
    }

    QList<RVector> getVertices() const {
        return RPolyline::getVertices();
    }

    RVector getVertexAt(int i) const {
        return RPolyline::getVertexAt(i);
    }

    void setVertexAt(int i, const RVector& v) {
        RPolyline::setVertexAt(i, v);
    }

    void appendVertex(const RVector& vertex, double bulge = 0.0, double w1 = 0.0, double w2 = 0.0) {
        RPolyline::appendVertex(vertex, bulge, w1, w2);
    }

    void prependVertex(const RVector& vertex, double bulge = 0.0, double w1 = 0.0, double w2 = 0.0) {
        RPolyline::prependVertex(vertex, bulge, w1, w2);
    }

    void insertVertex(int index, const RVector& vertex) {
        RPolyline::insertVertex(index, vertex);
    }

    void removeLastVertex() {
        RPolyline::removeLastVertex();
    }

    void removeVertex(int index) {
        RPolyline::removeVertex(index);
    }

    int countSegments() const {
        return RPolyline::countSegments();
    }

    QSharedPointer<RShape> getSegmentAt(int i) const {
        return RPolyline::getSegmentAt(i);
    }

    double getBulgeAt(int i) const {
        return RPolyline::getBulgeAt(i);
    }

    void setBulgeAt(int i, double b) {
        RPolyline::setBulgeAt(i, b);
    }

    double getVertexAngle(int i, RS::Orientation orientation = RS::UnknownOrientation) const {
        return RPolyline::getVertexAngle(i, orientation);
    }

    double getDirection1() const {
        return RPolyline::getDirection1();
    }

    double getDirection2() const {
        return RPolyline::getDirection2();
    }

    bool reverse() {
        return RPolyline::reverse();
    }

    RVector getEndPoint() const {
        return RPolyline::getEndPoint();
    }

    RVector getStartPoint() const {
        return RPolyline::getStartPoint();
    }

    bool relocateStartPoint(const RVector& p) {
        return RPolyline::relocateStartPoint(p);
    }

    bool relocateStartPoint(double dist) {
        return RPolyline::relocateStartPoint(dist);
    }

    void setClosed(bool on) {
        RPolyline::setClosed(on);
    }

    bool isClosed() const {
        return RPolyline::isClosed();
    }

    bool isGeometricallyClosed(double tolerance=RS::PointTolerance) const {
        return RPolyline::isGeometricallyClosed(tolerance);
    }

    bool autoClose() {
        return RPolyline::toLogicallyClosed();
    }

    bool toLogicallyClosed(double tolerance=RS::PointTolerance) {
        return RPolyline::toLogicallyClosed(tolerance);
    }

    bool toLogicallyOpen() {
        return RPolyline::toLogicallyOpen();
    }

    RS::Orientation getOrientation(bool implicitelyClosed = false) const {
        return RPolyline::getOrientation(implicitelyClosed);
    }

    void setGlobalWidth(double w) {
        RPolyline::setGlobalWidth(w);
    }

    void setStartWidthAt(int i, double w) {
        RPolyline::setStartWidthAt(i, w);
    }

    double getStartWidthAt(int i) const {
        return RPolyline::getStartWidthAt(i);
    }

    void setEndWidthAt(int i, double w) {
        RPolyline::setEndWidthAt(i, w);
    }

    double getEndWidthAt(int i) const {
        return RPolyline::getEndWidthAt(i);
    }

    bool hasWidths() const {
        return RPolyline::hasWidths();
    }

    void setStartWidths(const QList<double>& sw) {
        RPolyline::setStartWidths(sw);
    }

    QList<double> getStartWidths() const {
        return RPolyline::getStartWidths();
    }

    void setEndWidths(const QList<double>& ew) {
        RPolyline::setEndWidths(ew);
    }

    QList<double> getEndWidths() const {
        return RPolyline::getEndWidths();
    }

    QList<QSharedPointer<RShape> > getExploded(int segments = RDEFAULT_MIN1) const {
        return RPolyline::getExploded(segments);
    }

    RPainterPath toPainterPath() const {
        return RPolyline::toPainterPath();
    }

    void simplify(double angleTolerance) {
        RPolyline::simplify(angleTolerance);
    }

    RPolyline roundAllCorners(double radius) {
        return RPolyline::roundAllCorners(radius);
    }

    QList<RVector> verifyTangency(double toleranceMin = RS::AngleTolerance, double toleranceMax = M_PI_4) {
        return RPolyline::verifyTangency(toleranceMin, toleranceMax);
    }

    virtual QList<QSharedPointer<RShape> > getShapes(const RBox& queryBox = RDEFAULT_RBOX, bool ignoreComplex = false, bool segment = false, QList<RObject::Id>* entityIds = NULL) const;

    virtual QList<RVector> getIntersectionPoints(
            const REntityData& other, bool limited = true, bool same = false,
            const RBox& queryBox = RDEFAULT_RBOX, bool ignoreComplex = true) const;

    void setPolylineGen(bool on) {
        polylineGen = on;
    }
    bool getPolylineGen() const {
        return polylineGen;
    }
    void setElevation(double v);
    double getElevation() const;

protected:
    bool polylineGen;
};

Q_DECLARE_METATYPE(RPolylineData)
Q_DECLARE_METATYPE(RPolylineData*)
Q_DECLARE_METATYPE(const RPolylineData*)
Q_DECLARE_METATYPE(QSharedPointer<RPolylineData>)

#endif
