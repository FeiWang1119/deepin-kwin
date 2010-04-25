/********************************************************************
 KWin - the KDE window manager
 This file is part of the KDE project.

Copyright (C) 2009 Nikhil Marathe <nsm.nikhil@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*********************************************************************/

#ifndef KWIN_TILINGLAYOUTFACTORY_H
#define KWIN_TILINGLAYOUTFACTORY_H

namespace KWin
{

class Workspace;
class TilingLayout;
class Tile;
class TilingLayoutFactory
    {
    public:
        /** When adding your own layout, edit this
         * Remember to suffix an L for now
         */
        enum Layouts {
            First, // special, do not modify/move
            DefaultL,

            /* Actual layouts */
            SpiralL,
            ColumnsL,
            FloatingL,
            /* Put your layout above this line ^^^ */

            Last // special, do not modify/move
        };

        static TilingLayout* createLayout( int type, Workspace * );
        static TilingLayout* nextLayout( TilingLayout *curr );
        static TilingLayout* previousLayout( TilingLayout *curr );

        static int indexToLayoutIndex( int index );

    private:
        static TilingLayout* cycleLayout( TilingLayout *curr, bool next );

    };

inline TilingLayout* TilingLayoutFactory::nextLayout( TilingLayout *curr )
    {
    return cycleLayout( curr, true );
    }

inline TilingLayout* TilingLayoutFactory::previousLayout( TilingLayout *curr )
    {
    return cycleLayout( curr, false );
    }
} // end namespace

#endif
