/**
 * TP II0905 
 *
 * Nom binôme :
 *
 * Version :
 *
 */






/************************ HEADERS ****************************************/
#include "VT100.h"
#include "system.h"
#include "system_config.h"
#include "miwi/miwi_api.h"


/************************** PROTOTYPES ************************************/





/************************** VARIABLES ************************************/
        
extern API_UINT16_UNION                 myPANID;        						// mon PANID
extern uint8_t                          myLongAddress[MY_ADDRESS_LENGTH];		// mon adresse IEEE
extern API_UINT16_UNION                 myShortAddress;                     	// mon adresse logique
extern ACTIVE_SCAN_RESULT               ActiveScanResults[ACTIVE_SCAN_RESULT_SIZE];		// table des actives scan



extern RECEIVED_MESSAGE  rxMessage;




void main (void)
{
    //RECEIVED_MESSAGE messageQ;
    uint8_t nbPan;
    SYSTEM_Initialize();
    uartInitialize();
    CleanScreen();
    MiApp_ProtocolInit(false);
    MiApp_SetChannel(15);
    nbPan =  MiApp_SearchConnection(10,0xFFFF);
    if(!nbPan) 
    {
        MiApp_StartConnection(START_CONN_DIRECT, 0, 0);
        uartPrint("Aucun Pan trouve creation du pan");
    }
    else uartPrint("Pan trouve !");
      MiApp_EstablishConnection(0xFF, CONN_MODE_DIRECT);
	while(1)
    {
        uartPrint(rxMessage.Payload);
        MiApp_DiscardMessage();
        if(MiApp_MessageAvailable())
        {
            MiApp_DiscardMessage();
        }
         MiApp_FlushTx();
         MiApp_WriteData(0x48);
         MiApp_BroadcastPacket(false);
        
    }
}