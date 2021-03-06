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

#include "Screen.h"

#ifndef Q_WS_QWS
#include "ScreenEmu.h"
#elif MX508
#include "ScreenMx508.h"
#endif

Screen* Screen::_instance = NULL;

Screen* Screen::getInstance()
{
    return _instance;
}

void Screen::staticInit()
{
    if (_instance == NULL)
    {
#ifndef Q_WS_QWS
            _instance = new ScreenEmu();
#elif MX508
            _instance = new ScreenMx508();
#endif
    }
}

void Screen::staticDone()
{
    if(_instance)
    {
        delete _instance;
        _instance = NULL;
    }
}

Screen::Screen()
    : _screenOrientation(Screen::ROTATE_0)
{

}
