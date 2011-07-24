#ifndef __CGMMANAGER_H__
#define __CGMMANAGER_H__

#include "../../SDK/amx/amx.h"
#include "../../SDK/plugincommon.h"

class CGamemodeManager
{
#pragma pack(1)
public:
	AMX gmAMX;
	bool gmIsInit;
	bool gmIsSleeping;
	float gmSleepTime;

	uint32_t OnPlayerConnect(cell playerid);
	uint32_t OnPlayerDisconnect(cell playerid, cell reason);
	uint32_t OnPlayerSpawn(cell playerid);
	uint32_t OnPlayerDeath(cell playerid, cell killerid, cell reason);
	uint32_t OnVehicleSpawn(cell vehicleid);
	uint32_t OnVehicleDeath(cell vehicleid, cell killerid);
	uint32_t OnPlayerText(cell playerid, unsigned char * szText);
	uint32_t OnPlayerCommandText(cell playerid, unsigned char * szCommandText);
	//uint32_t OnPlayerInfoChange(cell playerid);
	uint32_t OnPlayerRequestClass(cell playerid, cell classid);
	uint32_t OnPlayerRequestSpawn(cell playerid);
	uint32_t OnPlayerEnterVehicle(cell playerid, cell vehicleid, cell ispassenger);
	uint32_t OnPlayerExitVehicle(cell playerid, cell vehicleid);
	uint32_t OnPlayerStateChange(cell playerid, cell newstate, cell oldstate);
	uint32_t OnPlayerEnterCheckpoint(cell playerid);
	uint32_t OnPlayerLeaveCheckpoint(cell playerid);
	uint32_t OnPlayerEnterRaceCheckpoint(cell playerid);
	uint32_t OnPlayerLeaveRaceCheckpoint(cell playerid);
	uint32_t OnRconCommand(char* szCommand);
	uint32_t OnObjectMoved(cell objectid);
	uint32_t OnPlayerObjectMoved(cell playerid, cell objectid);
	uint32_t OnPlayerPickedUpPickup(cell playerid, cell pickupid);
	uint32_t OnPlayerExitedMenu(cell playerid);
	uint32_t OnPlayerSelectedMenuRow(cell playerid, cell row);
	uint32_t OnVehicleRespray(cell playerid, cell vehicleid, cell color1, cell color2);
	uint32_t OnVehicleMod(cell playerid, cell vehicleid, cell componentid);
	uint32_t OnEnterExitModShop(cell playerid, cell enterexit, cell uint32_teriorid);
	uint32_t OnVehiclePaintjob(cell playerid, cell vehicleid, cell pauint32_tjobid);
	uint32_t OnPlayerInteriorChange(cell playerid, cell newid, cell oldid);
	uint32_t OnPlayerKeyStateChange(cell playerid, cell newkeys, cell oldkeys);

	uint32_t OnRconLoginAttempt( unsigned char* szIP, unsigned char* szPassuint16_t, cell success );
	uint32_t OnPlayerUpdate(cell playerid);
	uint32_t OnPlayerStreamIn(cell playerid, cell forplayerid);
	uint32_t OnPlayerStreamOut(cell playerid, cell forplayerid);
	uint32_t OnVehicleStreamIn(cell vehicleid, cell forplayerid);
	uint32_t OnVehicleStreamOut(cell vehicleid, cell forplayerid);

	uint32_t OnDialogResponse(cell playerid, cell dialogid, cell response, cell listitem, unsigned char *szInputText);
	uint32_t OnPlayerClickPlayer(cell playerid, cell clickedplayerid, cell source);
	uint32_t OnVehicleDamageStatusUpdate(cell vehicleid, cell playerid);

	CGamemodeManager();
	~CGamemodeManager();
};

#endif