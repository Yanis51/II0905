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
    uint8_t nbPan;
    SYSTEM_Initialize();
    uartInitialize();
    MiApp_ProtocolInit(false);
    MiApp_SetChannel(11);
    nbPan =  MiApp_SearchConnection(10,0xFFFF);
    //if(!nbPan) 
    MiApp_EstablishConnection(0xFF, CONN_MODE_INDIRECT);
   // MiApp_StartConnection(START_CONN_DIRECT, 10, 32);
  
    
    
    
    uartPrint("Test");
   
	while(1)
    {

        if (uartRead())
        {
            CleanScreen();
            uartRead();
        }
    }
}