/*************************************************************************

bq Cervantes e-book reader application
Copyright (C) 2011-2016  Mundoreader, S.L

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

#include "SettingsGeneralTermsInfo.h"
#include "FullScreenWidget.h"

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QScrollBar>

#define PERCENT_STEP_VALUE 0.75

SettingsGeneralTermsInfo::SettingsGeneralTermsInfo(QWidget* parent) : FullScreenWidget(parent){

        qDebug() << "--->" << Q_FUNC_INFO;
        setupUi(this);

        connect(backBtn,SIGNAL(clicked()),this, SIGNAL(hideMe()));
        connect(verticalPage, SIGNAL(previousPageReq()),  this , SLOT(previousPage()));
        connect(verticalPage, SIGNAL(nextPageReq()), this, SLOT(nextPage()));
        generalTermsResult->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vbar = generalTermsResult->verticalScrollBar();
}

SettingsGeneralTermsInfo::~SettingsGeneralTermsInfo(){
        qDebug() << "--->" << Q_FUNC_INFO;
}

void SettingsGeneralTermsInfo::fillInfo(){
    QString text = generalTermsResult->toHtml();
    switch(QBook::getInstance()->getResolution())
    {
        case QBook::RES1072x1448:
            text = text.replace(QRegExp("font-size\\s*:[\\w'-,\\s\"]*;"), QString("font-size:6pt;"));
            generalTermsResult->setHtml(text);
            break;
        case QBook::RES758x1024:
            text = text.replace(QRegExp("font-size\\s*:[\\w'-,\\s\"]*;"), QString("font-size:13pt;"));
            generalTermsResult->setHtml(text);
            break;
        case QBook::RES600x800: default:
            //Do nothing
            break;
    }

    //Define a single step as the 75% of the normal height in the widget.
    vbar->setSingleStep(generalTermsResult->height()*PERCENT_STEP_VALUE);
    setupPagination();
}

void SettingsGeneralTermsInfo::previousPage()
{
    qDebug() << Q_FUNC_INFO;
    vbar->triggerAction(QAbstractSlider::SliderSingleStepSub);
}

void SettingsGeneralTermsInfo::nextPage()
{
    qDebug() << Q_FUNC_INFO;
    vbar->triggerAction(QAbstractSlider::SliderSingleStepAdd);
}

void SettingsGeneralTermsInfo::setupPagination (){

    qDebug() << Q_FUNC_INFO;
    int pageNumber;
    if(vbar->maximum() % vbar->singleStep() == 0)
        pageNumber = vbar->maximum() / vbar->singleStep() + 1;
    else
        pageNumber = vbar->maximum() / vbar->singleStep() + 2;
    verticalPage->setup(pageNumber);
}

void SettingsGeneralTermsInfo::keyReleaseEvent(QKeyEvent *event){

        qDebug() << "--->" << Q_FUNC_INFO;
        if( event->key() == QBook::QKEY_BACK )
        {
            qDebug() << ": Closing...";
            emit hideMe();
            event->accept();
            return;
        }
        QWidget::keyReleaseEvent(event);
}

void SettingsGeneralTermsInfo::paintEvent (QPaintEvent *){
         QStyleOption opt;
         opt.init(this);
         QPainter p(this);
         style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
 }
