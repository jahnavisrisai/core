/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SC_SOURCE_FILTER_INC_AUTOFILTERCONTEXT_HXX
#define INCLUDED_SC_SOURCE_FILTER_INC_AUTOFILTERCONTEXT_HXX

#include "excelhandlers.hxx"
#include "autofilterbuffer.hxx"

namespace oox::xls {

class AutoFilter;
class FilterColumn;
class FilterSettingsBase;

class FilterSettingsContext : public WorksheetContextBase
{
public:
    explicit            FilterSettingsContext( WorksheetContextBase& rParent, FilterSettingsBase& rFilterSettings );

protected:
    virtual ::oox::core::ContextHandlerRef onCreateContext( sal_Int32 nElement, const AttributeList& rAttribs ) override;
    virtual void        onStartElement( const AttributeList& rAttribs ) override;

    virtual ::oox::core::ContextHandlerRef onCreateRecordContext( sal_Int32 nRecId, SequenceInputStream& rStrm ) override;
    virtual void        onStartRecord( SequenceInputStream& rStrm ) override;

private:
    FilterSettingsBase& mrFilterSettings;
};

class FilterColumnContext : public WorksheetContextBase
{
public:
    explicit            FilterColumnContext( WorksheetContextBase& rParent, FilterColumn& rFilterColumn );

protected:
    virtual ::oox::core::ContextHandlerRef onCreateContext( sal_Int32 nElement, const AttributeList& rAttribs ) override;
    virtual void        onStartElement( const AttributeList& rAttribs ) override;

    virtual ::oox::core::ContextHandlerRef onCreateRecordContext( sal_Int32 nRecId, SequenceInputStream& rStrm ) override;
    virtual void        onStartRecord( SequenceInputStream& rStrm ) override;

private:
    FilterColumn&       mrFilterColumn;
};

// class SortConditionContext

class SortConditionContext : public WorksheetContextBase
{
public:
    explicit            SortConditionContext( WorksheetContextBase& rFragment, SortCondition& rSortCondition );

protected:
    virtual ::oox::core::ContextHandlerRef onCreateContext( sal_Int32 nElement, const AttributeList& rAttribs ) override;
    virtual void        onStartElement( const AttributeList& rAttribs ) override;

    virtual ::oox::core::ContextHandlerRef onCreateRecordContext( sal_Int32 nRecId, SequenceInputStream& rStrm ) override;
    virtual void        onStartRecord( SequenceInputStream& rStrm ) override;

private:
    SortCondition&      mrSortCondition;
};

// class SortStateContext

class SortStateContext : public WorksheetContextBase
{
public:
    explicit            SortStateContext( WorksheetContextBase& rFragment, AutoFilter& rAutoFilter );

protected:
    virtual ::oox::core::ContextHandlerRef onCreateContext( sal_Int32 nElement, const AttributeList& rAttribs ) override;
    virtual void        onStartElement( const AttributeList& rAttribs ) override;

    virtual ::oox::core::ContextHandlerRef onCreateRecordContext( sal_Int32 nRecId, SequenceInputStream& rStrm ) override;
    virtual void        onStartRecord( SequenceInputStream& rStrm ) override;

private:
    AutoFilter&         mrAutoFilter;
};

// class AutoFilterContext

class AutoFilterContext : public WorksheetContextBase
{
public:
    explicit            AutoFilterContext( WorksheetFragmentBase& rFragment, AutoFilter& rAutoFilter );

protected:
    virtual ::oox::core::ContextHandlerRef onCreateContext( sal_Int32 nElement, const AttributeList& rAttribs ) override;
    virtual void        onStartElement( const AttributeList& rAttribs ) override;

    virtual ::oox::core::ContextHandlerRef onCreateRecordContext( sal_Int32 nRecId, SequenceInputStream& rStrm ) override;
    virtual void        onStartRecord( SequenceInputStream& rStrm ) override;

private:
    AutoFilter&         mrAutoFilter;
};

} // namespace oox::xls

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
