/* 
 * Copyright (C) 2005,2006 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_DESTINATION_HOLDER_H
#define MANGOS_DESTINATION_HOLDER_H

#include "Platform/Define.h"
#include "Timer.h"

class Object;

#define TRAVELLER_UPDATE_INTERVAL  300

template<typename TRAVELLER>
class MANGOS_DLL_DECL DestinationHolder
{
    TimeTracker i_tracker;
    uint32 i_totalTravelTime;
    uint32 i_timeStarted;
    float i_fromX, i_fromY, i_fromZ;
    float i_destX, i_destY, i_destZ;

    public:
        DestinationHolder() : i_tracker(TRAVELLER_UPDATE_INTERVAL), i_totalTravelTime(0), i_timeStarted(0) {}

        void SetDestination(TRAVELLER &traveller, float dest_x, float dest_y, float dest_z, float offset = 0);
        inline bool UpdateExpired(void) const { return i_tracker.Passed(); }
        inline void ResetUpdate(uint32 t = TRAVELLER_UPDATE_INTERVAL) { i_tracker.Reset(TRAVELLER_UPDATE_INTERVAL); }
        inline uint32 GetTotalTravelTime(void) const { return i_totalTravelTime; }
        inline uint32 GetStartTravelTime(void) const { return i_timeStarted; }
        inline bool HasArrived(void) const { return (i_totalTravelTime == 0 || (getMSTime() - i_timeStarted) >= i_totalTravelTime); }
        bool UpdateTraveller(TRAVELLER &traveller, uint32 diff, bool force_update);
        void UpdateLocation(TRAVELLER &traveller, float, float, float);
        void GetLocationNow(float &x, float &y, float &z) const;
        float GetDistanceFromDestSq(const Object &obj) const;

    private:
        void _findOffSetPoint(float x1, float y1, float x2, float y2, float offset, float &x, float &y);

};
#endif
