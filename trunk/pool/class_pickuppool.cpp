#include "../main.h"
#include "class_pickuppool.h"

tPickupPool* __PickupPoolEx = NULL;

uint32_t CPickupPool::New ( uint32_t a_uint32_Model, uint32_t a_uint32_Type, float a_float_X, float a_float_Y, float a_float_Z, uint8_t a_uint8_Static )
{
	logprintf ( "[Call]-> CPickupPool::New ( %d, %d, %f, %f, %f, %d )", a_uint32_Model, a_uint32_Type, a_float_X, a_float_Y, a_float_Z, a_uint8_Static );

	//// TODO: Remove that Shitty !
	__NetGame = *( uint32_t* )( 0x004F6270 );
	__PickupPoolEx = ( tPickupPool* )( *( uint32_t* )( __NetGame + 0x10 ) );

	//if ( this->m_uint32_PickupCount >= LIMIT_MAX_PICKUPS )
	//	return -1;

	if ( __PickupPoolEx->m_uint32_PickupCount >= LIMIT_MAX_PICKUPS )
		return -1;

	for ( uint32_t i = 0; i < LIMIT_MAX_PICKUPS; i++ )
	{
		if ( __PickupPoolEx->m_uint8_Active[ i ] == 0 )
		{
			__PickupPoolEx->m_Pickups[ i ].m_uint32_Model = a_uint32_Model;
			__PickupPoolEx->m_Pickups[ i ].m_uint32_Type = a_uint32_Type;
			__PickupPoolEx->m_Pickups[ i ].m_float_X = a_float_X;
			__PickupPoolEx->m_Pickups[ i ].m_float_Y = a_float_Y;	
			__PickupPoolEx->m_Pickups[ i ].m_float_Z = a_float_Z;
			if ( a_uint8_Static )
			{
				// Static, Ne Peut Pas Etre D�truit ?!?
				__PickupPoolEx->m_uint8_Active[ i ] = -1;
			}
			else
			{
				// Dynamic, Peut Etre D�truit ?!?
				__PickupPoolEx->m_uint8_Active[ i ] = 1;
			}
			__PickupPoolEx->m_uint32_PickupCount++;
			
			/*
			RakNet::BitStream bsPickup;
			bsPickup.Write(i);
			bsPickup.Write((PCHAR)&m_Pickups[i], sizeof (PICKUP));
			pNetGame->GetRakServer()->RPC(RPC_Pickup, &bsPickup, HIGH_PRIORITY, RELIABLE, 0, UNASSIGNED_PLAYER_ID, true, false);
			*/
			return i;
		}
	}


	/*
	for ( uint32_t i = 0; i < LIMIT_MAX_PICKUPS; i++ )
	{
		if ( this->m_uint8_Active[ i ] == 0 )
		{
			this->m_Pickups[ i ].m_uint32_Model = a_uint32_Model;
			this->m_Pickups[ i ].m_uint32_Type = a_uint32_Type;
			this->m_Pickups[ i ].m_float_X = a_float_X;
			this->m_Pickups[ i ].m_float_Y = a_float_Y;	
			this->m_Pickups[ i ].m_float_Z = a_float_Z;
			if ( a_uint8_Static )
			{
				// Static, Ne Peut Pas Etre D�truit ?!?
				this->m_uint8_Active[ i ] = -1;
			}
			else
			{
				// Dynamic, Peut Etre D�truit ?!?
				this->m_uint8_Active[ i ] = 1;
			}
			this->m_uint32_PickupCount++;
			
			/*
			RakNet::BitStream bsPickup;
			bsPickup.Write(i);
			bsPickup.Write((PCHAR)&m_Pickups[i], sizeof (PICKUP));
			pNetGame->GetRakServer()->RPC(RPC_Pickup, &bsPickup, HIGH_PRIORITY, RELIABLE, 0, UNASSIGNED_PLAYER_ID, true, false);
			
			return i;
		}
	}
	*/
	return -1;
}

uint8_t CPickupPool::Destroy ( uint32_t a_uint32_PickupIndex )
{
	if ( ( a_uint32_PickupIndex >= 0 ) && 
			( a_uint32_PickupIndex < LIMIT_MAX_PICKUPS ) && 
			( this->m_uint8_Active[ a_uint32_PickupIndex ] == 1 ) )
	{
		this->m_uint8_Active[ a_uint32_PickupIndex ] = 0;
		this->m_uint32_PickupCount--;

		/*
		RakNet::BitStream bsPickup;
		bsPickup.Write(iPickup);
		pNetGame->GetRakServer()->RPC(RPC_DestroyPickup, &bsPickup, HIGH_PRIORITY, RELIABLE, 0, UNASSIGNED_PLAYER_ID, true, false);
		*/
		return 1;
	}
	return 0;
}

void CPickupPool::InitForPlayer ( uint8_t a_uint8_PlayerIndex )
{	
	/*
	//RakNet::BitStream *pbsPickup;

	uint32_t x = 0;

	pbsPickup = new RakNet::BitStream();

	while(x != MAX_PICKUPS)
	{
		if (m_bActive[x])
		{
			pbsPickup->Write(x);
			pbsPickup->Write((PCHAR)&m_Pickups[x], sizeof (PICKUP));
		
			pNetGame->GetRakServer()->RPC(RPC_Pickup,pbsPickup,HIGH_PRIORITY,RELIABLE,
				0,pNetGame->GetRakServer()->GetPlayerIDFromIndex(bytePlayerID),false,false);

			pbsPickup->Reset();
		}

		x++;
	}

	delete pbsPickup;
	*/
}