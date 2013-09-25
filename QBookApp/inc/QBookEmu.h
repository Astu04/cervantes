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

#ifndef QBOOKEMU_H
#define QBOOKEMU_H

#include <QMainWindow>

namespace Ui { class QBookEmu; }

class QBookApp;

class QBookEmu : public QMainWindow
{
	Q_OBJECT

public:
	QBookEmu(QWidget* parent = 0);
    virtual ~QBookEmu();

    QBookApp* appWidget();

public slots:
    void handleAction(QAction* action);

private:
    void sendPressKey(int key);
    void sendKey(int key);
    int res;
    Ui::QBookEmu* m_ui;
    QBookApp* m_app;
};


#endif