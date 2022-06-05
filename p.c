#include "h.h"

void AskName(char* p_np, char* p_np2){// Ask the name of the Player and the ally
	printf("What is your name?:\n");
	scanf("%s", p_np);
	printf("What is the name of your ally ?:\n");
	scanf("%s", p_np2);
}

void DisplayPersona(Persona* Personas){// display every persona with his stats, actions and type
	int i;
	for (i=0; i<7; i++){
		printf("\33[38;2;0;255;0m%s \33[0m\n Health Point: %d \n Mana point: %d \n Attack: %d \n Defense: %d \n Agility: %d \n Type: %s \n Action 1: %s \n Action 2: %s \n\n", Personas[i].name, Personas[i].hp, Personas[i].mp, Personas[i].dam, Personas[i].def, Personas[i].ag, Personas[i].type, Personas[i].act1, Personas[i].act2);
	}
}

void ChoicePersona(Persona* tab,PersonaFinal* tabf, PersonaFinal* CP1, PersonaFinal* CP2, char* NamePl1, char* NamePl2, int* N1){// allow the player to choose a persona among the list of personas
	int B1, B2, i;
	char NP1[50];
	char NP2[50];
	printf("\nAmong the Personas below, choice a persona for %s (write his name as in the list)\n", NamePl1);
	sleep(4);
	DisplayPersona(tab);
	B1=0;
	while(B1==0){//while the Player doesn't write the exact name of a Persona, repeat 
		printf("Write a valid name:\n");
		scanf("%s", NP1);
		printf("%s? \n",NP1);
		for(i=0;i<NUMBEROFPERSONA;i++){
			if(0==strcmp(NP1,tabf[i].name)){//Compare every name of the list and what the player write, if good give the persona to the player
				printf("Persona chosen\n");
				B1=1;
				*CP1= *(tabf+i);
				*N1=i;
			}
		}
	}
	printf("\nAmong the Personas below, choice a persona for %s (write his name as in the list)\n\n", NamePl2);
	sleep(4);
	DisplayPersona(tab);
	B2=0;
	int j;
	while(B2==0){//same but for the ally
		printf("Write a valid name:\n");

		scanf("%s", NP2);
		for(j=0;j<NUMBEROFPERSONA;j++){
			if(0==strcmp(NP2,tabf[j].name)){//same but for the ally
				printf("Persona chosen\n");
				B2=1;
				*CP2= *(tabf+j);
			}
		}
	}
}
/* void clearScanf(){   //i tried but it doesn't work
	int res;
	char value;
	while(res==1 && value!='\n'){
		printf("Write a number");
		res=scanf("%c", &value);
	}
} */

void Difficulty(int* p){//Make the Player choose his difficulty
	int v=0;
	while(*p<1 || *p>4 || 1!=v){
		printf(" Select the difficulty, 1 for noob, 2 for easy, 3 for normal, 4 for hard:\n");
		v=scanf("%d", p);
	}
}

//printf("\n%s | %d hp | %d mp             %s | %d hp | %d mp \n\n", (*F1).name, (*F1).hp, (*F1).mp, (*F2).name, (*F2).hp, (*F2).mp);


void DisplayInterface(PersonaFinal* P1, PersonaFinal* P2, PersonaFinal* F1, PersonaFinal* F2, PersonaFinal* Other, char* NamePl1, char* NamePl2, int* bF1, int* bF2, int* bP1, int* bP2){// Display the interface of the current game, with the name, hp and mp of every persona and his state( KO )

	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\33[38;2;128;0;255m%s \33[0m | \33[38;2;255;0;0m%d hp \33[0m| \33[38;2;0;200;255m%d mp \33[0m            \33[38;2;128;0;255m%s \33[0m| \33[38;2;255;0;0m%d hp \33[0m| \33[38;2;0;200;255m%d mp \33[0m \n\n", (*F1).name, (*F1).hp, (*F1).mp, (*F2).name, (*F2).hp, (*F2).mp);  

	if(*bF1==1){
		printf("   \33[38;2;128;0;255m%s \33[0m is KO   ", (*F1).name);
	}
	if(*bF2==1){
		printf("   \33[38;2;128;0;255m%s \33[0m is KO   ", (*F2).name);
	}
	else if(*bF1==0 && *bF2==0 && *bP1==0 && *bP2==0 ){
		printf("\n \33[38;2;128;0;255m%s  %s \33[38;2;0;255;0m%s \33[0m and \33[38;2;0;255;0m%s  \33[0m: Not Knock out\n", (*F1).name, (*F2).name, (*P1).name, (*P2).name);
	}
	printf("\n\n\n\n\n\n\n\n\n\n");
	if(*bP1==1){
		printf("  \33[38;2;0;255;0m %s \33[0mis KO   ", (*P1).name);
	}
	if(*bP2==1){
		printf("  \33[38;2;0;255;0m %s \33[0mis KO   ", (*P2).name);
	}
	printf("\n\n");
	printf("%s:                                    %s:\n", NamePl1, NamePl2);
	printf("\n\33[38;2;0;255;0m%s \33[0m| \33[38;2;255;0;0m%d hp \33[0m| \33[38;2;0;200;255m%d mp             \33[38;2;0;255;0m%s \33[0m| \33[38;2;255;0;0m%d hp \33[0m| \33[38;2;0;200;255m%d mp           \33[38;2;0;255;0mSecond Persona\33[0m: \33[38;2;0;255;0m%s \33[0m|\33[38;2;255;0;0m %d hp \33[0m|\33[38;2;0;200;255m %d mp\33[0m\n\n\n", (*P1).name, (*P1).hp, (*P1).mp, (*P2).name, (*P2).hp, (*P2).mp, (*Other).name, (*Other).hp, (*Other).mp);
	printf("\n--------------------------------------------------------------------------------\n");
}

void DisplayInterfaceBoss(PersonaFinal* P1, PersonaFinal* P2, BossFinal* BAF, PersonaFinal* Other, char* NamePl1, char* NamePl2, int* BB, int* bP1, int* bP2){//Display the interface of the current game against the final boss, with the hp,mp, name and state of everybody(KO)

	printf("\n--------------------------------------------------\n");
	printf("\n\33[38;2;120;0;0mFinal Boss\33[0m: \33[38;2;120;0;0m%s \33[0m | \33[38;2;255;0;0m%d hp \33[0m  \n\n", (*BAF).name, (*BAF).hp);

	if(*BB==1){
		printf("   %s \33[0mis KO   ", (*BAF).name);
	}
	else if(*bP1==0 && *bP2==0 && *BB==0 ){
		printf("\n%s %s and %s : Not Knock out\n", (*P1).name, (*P2).name, (*BAF).name);
	}
	printf("\n\n\n\n\n\n\n\n\n\n");
	if(*bP1==1){
		printf("  \33[38;2;0;255;0m %s \33[0mis KO   ", (*P1).name);
	}
	if(*bP2==1){
		printf("  \33[38;2;0;255;0m %s \33[0mis KO   ", (*P2).name);
	}
	printf("\n\n");
	printf("%s:                                    %s:\n", NamePl1, NamePl2);
	printf("\n\33[38;2;0;255;0m%s \33[0m| \33[38;2;255;0;0m%d hp \33[0m| \33[38;2;0;200;255m%d mp             \33[38;2;0;255;0m%s \33[0m| \33[38;2;255;0;0m%d hp \33[0m| \33[38;2;0;200;255m%d mp           \33[38;2;0;255;0mSecond Persona\33[0m: \33[38;2;0;255;0m%s \33[0m|\33[38;2;255;0;0m %d hp \33[0m|\33[38;2;0;200;255m %d mp\33[0m\n\n\n", (*P1).name, (*P1).hp, (*P1).mp, (*P2).name, (*P2).hp, (*P2).mp, (*Other).name, (*Other).hp, (*Other).mp);
	printf("\n--------------------------------------------------\n");
}

void DisplayAttack(){//called when an attack hit the ennemy, display an emoticone of a orange punch
	int j;
	for(j=0;j<20;j++){
		if(j==0){
			printf("\33[38;2;255;81;0m                      ***************\n");
		
   		}
   		if(j==1){
       			printf("          ****************************************\n");

   		} 
   		if(j==2){
       			printf("**************************************************\n");

   		}
   		if(j==3){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==4){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==5){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==6){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==7){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==8){
       			printf("*       **           **             **           *\n");


   		} 
   		if(j==9){
       			printf("*       **           **             **           **\n");


   		}
   		if(j==10){
       			printf("*       **           **             **           ***\n");

		}
   		if(j==11){
       			printf("*       **           **             **           *****\n");


   		}

   		if(j==12){
       			printf("**********           **             **           ******\n");


   		}

   		if(j==13){
       			printf("         *           **             **           **    *\n");


   		}

   		if(j==14){
       			printf("         *           **             **************      *\n");


   		}
   		if(j==15){
      			printf("         **************             *                    *\n");


   		}
   		if(j==16){
       			printf("                      ***************                    *\n");


   		}
   		if(j==17){
       			printf("                           **                           *\n");


   		}
   		if(j==18){
       			printf("                           **                         **\n");


   		}
   		if(j==19){
       			printf("                           ***************************\33[0m\n");


   		}
	}
}


void DisplayAttackF(){//called when the final boss use his ultimate move, display an emoticone of a red punch
	int j;
	for(j=0;j<20;j++){
		if(j==0){
			printf("\33[38;2;255;0;0m                      ***************\n");
		
   		}
   		if(j==1){
       			printf("          ****************************************\n");

   		} 
   		if(j==2){
       			printf("**************************************************\n");

   		}
   		if(j==3){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==4){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==5){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==6){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==7){
       			printf("*       **           **             **           *\n");


   		}
   		if(j==8){
       			printf("*       **           **             **           *\n");


   		} 
   		if(j==9){
       			printf("*       **           **             **           **\n");


   		}
   		if(j==10){
       			printf("*       **           **             **           ***\n");

		}
   		if(j==11){
       			printf("*       **           **             **           *****\n");


   		}

   		if(j==12){
       			printf("**********           **             **           ******\n");


   		}

   		if(j==13){
       			printf("         *           **             **           **    *\n");


   		}

   		if(j==14){
       			printf("         *           **             **************      *\n");


   		}
   		if(j==15){
      			printf("         **************             *                    *\n");


   		}
   		if(j==16){
       			printf("                      ***************                    *\n");


   		}
   		if(j==17){
       			printf("                           **                           *\n");


   		}
   		if(j==18){
       			printf("                           **                         **\n");


   		}
   		if(j==19){
       			printf("                           ***************************\33[0m\n");


   		}
	}
}
