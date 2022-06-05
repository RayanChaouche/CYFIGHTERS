#include "h.h"


int main(){
srand(time(NULL));
char NamePlayer1[50];// Name of the Player
char NamePlayer2[50];// Name of the ally

char* PNamePlayer2=NULL;// Pointer on the name of the ally
PNamePlayer2= &NamePlayer2[50];

char* PNamePlayer1=NULL;// Pointer on the name of the Player 
PNamePlayer1= &NamePlayer1[50];

Persona* tabp=NULL;// Array of the Personas without theirs action and type
Type* tabt=NULL;// Array of the Types
Action* taba=NULL;// Array of the Actions without theirs type
PersonaFinal* tabf=NULL;// Array of the Personas witht theirs action and type
ActionFinal* tabaf=NULL;// Array of the Actions with theirs type


Boss Boss_Ashura;// Final Boss without his actions and type
Boss* pBoss_Ashura=&Boss_Ashura;// Pointer on the final boss

PersonaFinal CP1;// Persona of the Player
PersonaFinal CP2;// Persona of the ally
PersonaFinal* PCP1= &CP1;// Pointer on the Persona of the Player
PersonaFinal* PCP2= &CP2;// Pointer on the Persona of the ally

PersonaFinal F1;// 1st Persona ennemy
PersonaFinal F2;// 2nd Persona ennemy
PersonaFinal* PF1= &F1;// Pointer on the first ennemy
PersonaFinal* PF2= &F2;// Pointer on the second ennemy

BossFinal BossAshuraF;// Final Boss with his actions and type
BossFinal* pBossAshuraF=&BossAshuraF;// Pointer on the final boss with his actions and type

tabp=getPersonalist();// create an array of Persona without actions and type
tabt=getTypelist();// create an array of type
taba=getActionlist();// create an array of actions without type
tabaf=AttributeTypetoAction(taba, tabt);// Attribute the type to the actions, return a array of complete actions
tabf=AttributeStructtoPersona(tabp, tabaf, tabt);// Attribute the type and actions to the Personas, return a array of complete Personas

Boss_Ashura=getBoss();// create the Final boss with his stats
BossAshuraF=AttributeStructtoBoss( Boss_Ashura, tabaf, tabt);// Attribute to the boss his actions and type

int bF1;// int which'll allow to see if the first ennemy is Knock out or not
int* pbF1=&bF1;

int bF2;// int which'll allow to see if the second ennemy is Knock out or not
int* pbF2=&bF2;

int bP1;// int which'll allow to see if the Persona of the Player is Knock out or not
int* pbP1=&bP1;

int bP2;// int which'll allow to see if the Persona of the ally is Knock out or not
int* pbP2=&bP2;

int BB;// int which'll allow to see if the final boss is Knock out or not
int* pBB=&BB;

int level;// difficulty of the game ( 1 to 4 )
int* plevel=&level;

PersonaFinal Other;// Second Persona, if a negotiation succeed, the persona ennemy will become an ally in this emplacement
PersonaFinal* pOther=&Other;

Other=TakeOther(tabf);// create a hollow second persona for be able to put the new allied persona in

Difficulty(&level);// functions who'll make the player choose the difficulty

AskName(&NamePlayer1[50],&NamePlayer2[50]);// Ask the names of the Player and the ally

int NF1;//Take the number of the Persona of the Player so the first ennemy isn't the same persona as the persona of the player
int* PNF1=&NF1;


ChoicePersona(tabp, tabf, &CP1, &CP2, &NamePlayer1[50], &NamePlayer2[50], &NF1);//Choose the persona for the player and the ally

F1=RandFoe(tabf, &NF1);// choose a persona randomly for the ennemy 1, not the same as the player
F2=RandFoe(tabf, &NF1);// choose a persona randomly for the ennemy 2, not the same as the player

Battle(&CP1, &CP2, &F1, &F2, &Other, tabf, &bF1, &bF2, &bP1, &bP2, &level, &NamePlayer1[50], &NamePlayer2[50], &BossAshuraF, &BB);//the whole battle (end if one of both team is dead).




free(taba);
free(tabaf);
free(tabf);
free(tabp);
free(tabt);
return(0);
}

