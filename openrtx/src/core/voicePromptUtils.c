/***************************************************************************
 *   Copyright (C) 2022 by Federico Amedeo Izzo IU2NUO,                    *
 *                         Niccolò Izzo IU2KIN,                            *
 *                         Silvano Seva IU2KWO                             *
 *                         Joseph Stephen VK7JS                            *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/
 // This file contains functions for announcing radio functions using the building blocks in voicePrompts.h/c.
 
 #include "core/voicePromptUtils.h"

static void vpInitIfNeeded(VoicePromptQueueFlags_T flags)
{
	if (flags&vpqInit)
		vpInit();
}

static void vpPlayIfNeeded(VoicePromptQueueFlags_T flags)
{
	if (flags&vpqPlayImmediatley)
		vpPlay();
}

void announceChannelName(channel_t* channel, uint16_t channelIndex, VoicePromptQueueFlags_T flags)
{
	vpInitIfNeeded(flags);
	
	if (flags&vpqIncludeDescriptions)
	{
		vpQueuePrompt(PROMPT_CHANNEL);
	}
	vpQueueInteger(channelIndex);
	
	// Only queue the name if it is not the same as the raw number.
	// Otherwise the radio will say channel 1 1 for channel 1.
	if (strcmp(atoi(channelIndex), channel->name) != 0)
		vpQueueString(channel->name);
	
	vpPlayIfNeeded(flags);
}

void announceFrequencies(freq_t rx, freq_t tx, VoicePromptQueueFlags_T flags)
{
	vpInitIfNeeded(flags);
		// if rx and tx frequencies differ, announce both, otherwise just announce one.
	if (rx==tx)
		announceFrequency(rx);
	else
	{
		vpQueuePrompt(PROMPT_RECEIVE);
		announceFrequency(rx);
		vpQueuePrompt(PROMPT_TRANSMIT);
		announceFrequency(tx);
	}
	vpPlayIfNeeded(flags);
} 

void announceRadioMode(uint8_t mode, VoicePromptQueueFlags_T flags)
{
	vpInitIfNeeded(flags);

	if (flags&vpqIncludeDescriptions)
		vpQueuePrompt(PROMPT_MODE);
	
	switch(mode)
	{
		case OPMODE_DMR:
			vpQueuePrompt(PROMPT_DMR);
			break;
		case OPMODE_FM:
			vpQueuePrompt(PROMPT_FM);
			break;
		case OPMODE_M17:
			vpQueuePrompt(PROMPT_M17);
			break;
	}
	
	vpPlayIfNeeded(flags);
}

void vpAnnounceChannelSummary(channel_t* channel, uint16_t channelIndex, bool init, VoicePromptQueueFlags_T flags)
{
	 	if (!channel) return;
	vpInitIfNeeded(flags);
		
		VoicePromptQueueFlags_T localFlags=flags&vpqIncludeDescriptions; // mask off init and play because this function will handle init and play.
		
	announceChannelName(channel, channelIndex, localFlags);
	announceFrequencies(channel->rx_frequency , channel->tx_frequency, localFlags);
	announceRadioMode(channel->mode,  localFlags);
	
	vpPlayIfNeeded(flags);
}
 