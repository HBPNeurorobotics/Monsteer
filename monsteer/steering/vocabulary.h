
/* Copyright (c) 2006-2015, Jafet Villafranca Diaz <jafet.villafrancadiaz@epfl.ch>
 *
 * This file is part of Monsteer <https://github.com/BlueBrain/Monsteer>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#ifndef STEERING_VOCABULARY_H
#define STEERING_VOCABULARY_H

#include <zeq/types.h>
#include <zeq/event.h>

#include <monsteer/playbackState_zeq_generated.h>
#include <monsteer/stimulus_zeq_generated.h>
#include <monsteer/runSimTrigger_zeq_generated.h>
#include <monsteer/statusRequestMsg_zeq_generated.h>
#include <monsteer/proxyStatusMsg_zeq_generated.h>

#include <monsteer/types.h>

namespace monsteer
{
namespace steering
{

struct Stimulus
{
    Stimulus()
        : multiple(false)
    {}

    std::string messageID;
    brion::uint32_ts cells;
    std::string params;
    bool multiple;
};

struct SimulationPlaybackState
{
    enum State
    {
        PAUSE = 0u,
        PLAY = 1u,
        ONDEMAND = 2u
    };

    SimulationPlaybackState()
        : state( ONDEMAND ) {}

    std::string messageID;
    State state;
};

struct SimulationRunTrigger
{
    SimulationRunTrigger()
        : duration(20.0)
    {}

    std::string messageID;
    double duration;

};

struct ProxyStatus 
{
    enum State
    {
        READY = 0u,
        BUSY = 1u
    };

    ProxyStatus()
    {}

    std::string messageID;
    State state;
};

struct StatusRequest
{
    StatusRequest()
    {}

    std::string messageID;
};

zeq::Event serializeStimulus( const std::string& messageID,
                              const brion::uint32_ts& cells,
                              const std::string& params,
                              const bool multiple );
zeq::Event serializeStimulus( const Stimulus& stimulus );

Stimulus deserializeStimulus( const zeq::Event& event );

zeq::Event serializePlaybackState(  const std::string& messageID,
                                    const SimulationPlaybackState::State state );

SimulationPlaybackState deserializePlaybackState( const zeq::Event& event );

zeq::Event serializeSimulationRunTrigger( const std::string& messageID,
                                       const double duration );

SimulationRunTrigger deserializeSimulationRunTrigger( const zeq::Event& event );

zeq::Event serializeStatusRequest( const std::string& messageID );

StatusRequest deserializeStatusRequest( const zeq::Event& event );

zeq::Event serializeProxyStatus( const std::string& messageID,
                                 const ProxyStatus::State state );

ProxyStatus deserializeProxyStatus( const zeq::Event& event );

}
}
#endif // STEERING_VOCABULARY_H
