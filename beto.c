#include "vxWorks.h"
#include "taskLib.h"
#include "stdio.h"
#include "semLib.h"
#include "wdLib.h"
#include "sysLib.h"
#include "dio96.h"
#include "partie_reactive_architecture.h"

//Addresses Capteurs
#define ADDR_C1 0x04
#define ADDR_C2 0x02
#define ADDR_C3 0x01
#define ADDR_C4 0x80
#define ADDR_C5 0x20
#define ADDR_C6 0x10
#define ADDR_C7 0x08
#define ADDR_C8 0x04
#define ADDR_C9 0x80
#define ADDR_C10 0x80
#define ADDR_C11 0x40
#define ADDR_C12 0x40
#define ADDR_C13 0x20
#define ADDR_C14 0x20
#define ADDR_C15 0x10
#define ADDR_C16 0x10
#define ADDR_C17 0x08
#define ADDR_C18 0x04
#define ADDR_URG 0x08
#define ADDR_DEM 0x04
	


//Adresses Actionneurs

#define ADDR_TR1 0x04
#define ADDR_TR2 0x02
#define ADDR_TR3 0x01
#define ADDR_TR4 0x80
#define ADDR_TR5 0x20
#define ADDR_TR6 0x10
#define ADDR_TR7 0x08
#define ADDR_TR8 0x04
#define ADDR_TR9 0x20
#define ADDR_TR10 0x20
#define ADDR_ALIM 0x10
#define ADDR_TR11 0x10

 
#define ADDR_AG1D 0x08
#define ADDR_AG1G 0x08
#define ADDR_AG2D 0x04
#define ADDR_AG2G 0x04
#define ADDR_AG3D 0x02
#define ADDR_AG3G 0x02
#define ADDR_AG4D 0x01
#define ADDR_AG4G 0x01
 


#define cPriot_atelier 150
#define cPriopartie_reactive_reset_architecture 150
#define cPrioTacheA 150
#define cPrioTacheB 100
#define cPrioTacheC 99
#define cPrioTacheDialogue 50
#define STACK_SIZE 20000
#define ValTempo 200 /* 2s*/


int Tidt_atelier;
int TidTacheA ;
int TidTacheB ;
int TidTacheC ;
int TidTacheDialogue ;

typedef enum {false,true} boolean;


//Entrees
UINT8 PPIB_PA;
UINT8 PPIB_PB;
UINT8 PPIC_PC;
UINT8 PPID_PC;

//Sorties
UINT8 PPIA_PA;
UINT8 PPIA_PB;
UINT8 PPIC_PB;
UINT8 PPID_PB;

inC_partie_reactive_architecture entree_cap;
outC_partie_reactive_architecture sortie_act;




char c;
SEM_ID semA;
SEM_ID semB;

WDOG_ID WdId;
SEM_ID EvtFinTempo;

void FonctTempo(void){
 semGive(EvtFinTempo);
}

void TacheA(void) {
 int i;
 
 for(;;){
 semTake(semA,WAIT_FOREVER);
 for(i=0;i<99;i++){
  printf("a");
 }
 printf("\n");
 }
}

void TacheB(void) {
 int i; 
 
 for(;;){
 semTake(semB,WAIT_FOREVER);
 for(i=0;i<99;i++){
  printf("b");
 }
 printf("\n");
 }
}

void TacheC(void){
 int i;
 for(;;){
  wdStart(WdId,ValTempo, (FUNCPTR) FonctTempo,0);
  semTake(EvtFinTempo, WAIT_FOREVER);
  for(i=0;i<100;i++){
   printf("c");
  }
 }

}

void TacheDialogue(void) {
 char ch;
 
 for(;;){
  ch= getchar();
  if(ch=='a') {
   semGive(semA);
  } else if(ch=='b') {
   semGive(semB);
  }else {
	break;
  }
 }
}

void lecture_capteurs(inC_partie_reactive_architecture* entree_cap)
{
 boolean C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,C13,C14,C15,C16,C17,C18,DEM,URG;
 
 lecturePorts(&PPIB_PA,&PPIB_PB,&PPIC_PC,&PPID_PC);
 

 C1=((PPIB_PB&ADDR_C1)==ADDR_C1);
 C2=((PPIB_PB&ADDR_C2)==ADDR_C2);
 C3=((PPIB_PB&ADDR_C3)==ADDR_C3);
 C4=((PPIB_PA&ADDR_C4)==ADDR_C4);
 C5=((PPIB_PA&ADDR_C5)==ADDR_C5);
 C6=((PPIB_PA&ADDR_C6)==ADDR_C6);
 C7=((PPIB_PA&ADDR_C7)==ADDR_C7);
 C8=((PPIB_PA&ADDR_C8)==ADDR_C8);
 C9=((PPIC_PC&ADDR_C9)==ADDR_C9);
 C10=((PPID_PC&ADDR_C10)==ADDR_C10);
 C11=((PPID_PC&ADDR_C11)==ADDR_C11);
 C12=((PPID_PC&ADDR_C12)==ADDR_C12);
 C13=((PPID_PC&ADDR_C13)==ADDR_C13);
 C14=((PPID_PC&ADDR_C14)==ADDR_C14);
 C15=((PPID_PC&ADDR_C15)==ADDR_C15);
 C16=((PPID_PC&ADDR_C16)==ADDR_C16);
 C17=((PPID_PC&ADDR_C17)==ADDR_C17);
 C18=((PPID_PC&ADDR_C18)==ADDR_C18);
 DEM=((PPIC_PC&ADDR_DEM)==ADDR_DEM);
 URG=((PPID_PC&ADDR_URG)==ADDR_URG);
 
 printf("PPIB_PA %x\n",PPIB_PA);
 printf("PPIB_PB %x\n",PPIB_PB);
 printf("PPIC_PC %x\n",PPIC_PC);
 printf("PPID_PC %x\n",PPID_PC);

 //Capteurs
 entree_cap->info_capteurs[0]=C1;
 entree_cap->info_capteurs[1]=C2;
 entree_cap->info_capteurs[2]=C3;
 entree_cap->info_capteurs[3]=C4;
 entree_cap->info_capteurs[4]=C5;
 entree_cap->info_capteurs[5]=C6;
 entree_cap->info_capteurs[6]=C7;
 entree_cap->info_capteurs[7]=C8;
 entree_cap->info_capteurs[8]=C9;
 entree_cap->info_capteurs[9]=C10;
 entree_cap->info_capteurs[10]=C11;
 entree_cap->info_capteurs[11]=C12;
 entree_cap->info_capteurs[12]=C13;
 entree_cap->info_capteurs[13]=C14;
 entree_cap->info_capteurs[14]=C15;
 entree_cap->info_capteurs[15]=C16;
 entree_cap->info_capteurs[16]=C17;
 entree_cap->info_capteurs[17]=C18;
 
 
 //type_piece
 entree_cap->mode_de_fonctionnement[0]=DEM;
 entree_cap->mode_de_fonctionnement[1]=URG;
 
 
 //a completer
 
}

void ecriture_act(outC_partie_reactive_architecture* sortie_act)
{
	boolean ALIM,TR_1,TR_2,TR_3,TR_4,TR_5,TR_6,TR_7,TR_8,TR_9,TR_10,TR_11,AG1D,AG1G,AG2D,AG2G,AG3D,AG3G,AG4D,AG4G;

	ALIM=sortie_act->Alimentation;
	TR_1=sortie_act->instruction_actionneurs[0];
	TR_2=sortie_act->instruction_actionneurs[1];
	TR_3=sortie_act->instruction_actionneurs[2];
	TR_4=sortie_act->instruction_actionneurs[3];
	TR_5=sortie_act->instruction_actionneurs[4];
	TR_6=sortie_act->instruction_actionneurs[5];
	TR_7=sortie_act->instruction_actionneurs[6];
	TR_8=sortie_act->instruction_actionneurs[7];
	TR_9=sortie_act->instruction_actionneurs[8];
	TR_10=sortie_act->instruction_actionneurs[9];
	TR_11=sortie_act->instruction_actionneurs[10];
  
	AG1D=sortie_act->instruction_actionneurs[11];
	AG1G=sortie_act->instruction_actionneurs[12];
	AG2D=sortie_act->instruction_actionneurs[13];
	AG2G=sortie_act->instruction_actionneurs[14];
	AG3D=sortie_act->instruction_actionneurs[15];
	AG3G=sortie_act->instruction_actionneurs[16];
	AG4D=sortie_act->instruction_actionneurs[17];
	AG4G=sortie_act->instruction_actionneurs[18];
 
 
	PPIA_PA=
	ADDR_TR4*TR_4+
	ADDR_TR5*TR_5+
	ADDR_TR6*TR_6+
	ADDR_TR7*TR_7+
	ADDR_TR8*TR_8;
	 
	PPIA_PB=
	ADDR_TR1*TR_1+
	ADDR_TR2*TR_2+
	ADDR_TR3*TR_3;
	
	PPIC_PB=
	ADDR_TR9*TR_9+
	ADDR_TR11*TR_11+
	ADDR_AG1D*AG1D+
	ADDR_AG2D*AG2D+
	ADDR_AG3D*AG3D+
	ADDR_AG4D*AG4D+;
	
	PPID_PB=
	ADDR_TR10*TR_10+
	ADDR_ALIM*ALIM+
	ADDR_AG1G*AG1G+
	ADDR_AG2G*AG2G+
	ADDR_AG3G*AG3G+
	ADDR_AG4G*AG4G;
	
	ecriturePorts(PPIA_PA,PPIA_PB,PPIC_PB,PPID_PB);
}

void t_atelier(void)
{
 for(;;)
 {
  taskDelay(sysClkRateGet()/10);
  //
  lecture_capteurs(&entree_cap);
  //
  partie_reactive_architecture
   (&entree_cap,&sortie_act);
   
  //  
  ecriture_act(&sortie_act); 
  
 }
 
 
 
 
}

STATUS Debut(void)
{
 //changer sortie_act
 
 ConfigPPI();
 partie_reactive_reset_architecture(&sortie_act);
 partie_reactive_init_architecture(&sortie_act);
 
 Tidt_atelier=taskSpawn
  ("t_atelier", cPriot_atelier, 0, STACK_SIZE,
  (FUNCPTR) t_atelier,0,0,0,0,0,0,0,0,0,0);
}

void Fin(void) {
	
	//TODO Verifier deletion des taches
 taskDelete(TidTacheA);
 taskDelete(TidTacheB);
 taskDelete(TidTacheC);
 semDelete(semA);
 semDelete(semB);
 semDelete(EvtFinTempo); 
 wdDelete(WdId);
}