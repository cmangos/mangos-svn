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

#ifndef MANGOS_CREATUREAI_H
#define MANGOS_CREATUREAI_H

#include "Platform/Define.h"
#include "Policies/Singleton.h"
#include "Dynamic/ObjectRegistry.h"
#include "Dynamic/FactoryHolder.h"

class Unit;
class Creature;

#define IN_LINE_OF_SIGHT         30
#define VISIBILITY_RANGE    100
#define SPIRIT_HEALER       5233

class MANGOS_DLL_DECL CreatureAI
{
    public:

        virtual ~CreatureAI();

        virtual void MoveInLineOfSight(Unit *) = 0;

        virtual void AttackStart(Unit *) = 0;

        virtual void AttackStop(Unit *) = 0;

        virtual void HealBy(Unit *healer, uint32 amount_healed) = 0;

        virtual void DamageInflict(Unit *done_by, uint32 amount_damage) = 0;

        virtual bool IsVisible(Unit *) const = 0;

        virtual void UpdateAI(const uint32 diff) = 0;
};

struct SelectableAI : public FactoryHolder<CreatureAI>, public Permissible<Creature>
{

    SelectableAI(const char *id) : FactoryHolder<CreatureAI>(id) {}
};

template<class REAL_AI>
struct CreatureAIFactory : public SelectableAI
{
    CreatureAIFactory(const char *name) : SelectableAI(name) {}

    CreatureAI* Create(void *) const;

    int Permit(const Creature *c) const { return REAL_AI::Permissible(c); }
};

#define NO_PERMIT  -1
#define IDLE_PERMIT_BASE 1
#define REACTIVE_PERMIT_BASE 100
#define PROACTIVE_PERMIT_BASE 200
#define FACTION_SPECIFIC_PERMIT_BASE 400
#define SPEICAL_PERMIT_BASE 800

typedef FactoryHolder<CreatureAI> CreatureAICreator;
typedef FactoryHolder<CreatureAI>::FactoryHolderRegistry CreatureAIRegistry;
typedef FactoryHolder<CreatureAI>::FactoryHolderRepository CreatureAIRepository;
#endif
