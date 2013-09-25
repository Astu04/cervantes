/*************************************************************************

bq Cervantes e-book reader application
Copyright (C) 2011-2013  Mundoreader, S.L

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the source code.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/

#ifndef VIEWERPAGEHANDLER_H
#define VIEWERPAGEHANDLER_H

#include "ui_ViewerPageHandler.h"
#include "MouseFilter.h"

class ViewerPageHandler : public QWidget,
                          protected Ui::ViewerPageHandler
{
    Q_OBJECT

public:
    ViewerPageHandler(QWidget*);
    virtual ~ViewerPageHandler();

    void                                setCurrentPageMode                  ( bool isPdf );
    bool                                shouldBeShown                       ();
    void                                hideBackBtn                         ();
    void                                showBackBtn                         ();

    void                                setCurrentPage                      (int value);
    virtual void                        updateDisplay                       ();
    void                                hideChapterInfo                     ();
    void                                setPdfToolbarState                  (bool shouldBeShown){m_pdfToolbarShowed = shouldBeShown;}

public slots:
    void                                handlePageChange                    (int, int, int);
    void                                resetPager                          ();
    void                                setChapterPage                      (int);

signals:
    void                                goBack                              ();
    void                                pdfMenuBtnClicked                   ();
    void                                pressEvent                          (TouchEvent*);

protected:
    void                                updatePageHandler                   ();
    virtual void                        mousePressEvent                     (QMouseEvent*);

    int                                 m_currentPageIni;
    int                                 m_currentPageEnd;
    int                                 m_totalPages;
    bool                                m_pdfToolbarShowed;

    enum EViewerPageHandlerMask
    {
        EVPHM_NONE          =   0,

        EVPHM_PROGRESSBAR   =   (1u << 1),
        EVPHM_PAGE          =   (1u << 2),
        EVPHM_BACK_BTN      =   (1u << 3),
        EVPHM_PDF           =   (1u << 4),
        EVPHM_CLOSE_BTN     =   (1u << 5),
        EVPHM_PROGRESS      =   (1u << 6),
        EVPHM_CHAPTER       =   (1u << 7)
    };

    int                                 m_visibleMask;// Indicates which info can be shown.
};

#endif // VIEWERPAGEHANDLER_H
