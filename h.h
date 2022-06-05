#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define NUMBEROFPERSONA 8 // 7 Persona playable, the 8th is the Persona 'None' for change a persona while the battle
#define NUMBEROFACTION 17
#define NUMBEROFTYPE 9// 8 types, the 9th is the type linked to the type 'None' (The weakness and strenght of the type None is this 9th type)
/*srand(time(NULL));*/
int i;



typedef struct {// structure which define a type

	char name[50];// name of the type
	char weakness[50];// name of the type it is weak against
	char strength[50];// name of the type it is strong against

} Type;



typedef struct {// structure which define an action

	char name[50];// name of the action
	char type[50];// type of the action
	int hp_cost;// number of hp needed to launch the action/backlash
	int mp_cost;// number of hp needed to launch the action
	int dmg;// number of hp removed by the action to the foe

} Action;

typedef struct {// structure which define an action with his type

	char name[50];// name of the action
	Type type;// type of the action
	int hp_cost;// number of hp needed to launch the action/backlash
	int mp_cost;// number of hp needed to launch the action
	int dmg;// number of hp removed by the action to the foe

} ActionFinal;

typedef struct {// structure which define a Persona

	char name[50];// name of the Persona
	int hp;// number of health point the Persona got
	int mp;// number of magic point the Persona got
	int dam;// number of damage the Persona deal
	int def; // number of defense point the persona got,it will reduce the damage dealed ( not implemented )
	int ag;// agility of a Persona, the higher attack first
	char type[50];// type of the persona
	char act1[50];// one of the two action the persona got
	char act2[50];// one of the two action the persona got

} Persona;

typedef struct {// structure which define the Boss ( like a Persona but with 3 actions )

	char name[50];// name of the Persona
	int hp;// number of health point the Persona got
	int mp;// number of magic point the Persona got
	int ag;// agility of a Boss, the higher attack first
	char type[50];// type of the Boss
	char act1[50];// one of the three action the Boss got
	char act2[50];// one of the three action the Boss got
	char act3[50];// one of the three action the Boss got

} Boss;

typedef struct {// structure which define the Boss with his actions and his type

	char name[50];// name of the Persona
	int hp;// number of health point the Persona got
	int mp;// number of magic point the Persona got
	int ag;// agility of a Boss, the higher attack first
	Type type;// type of the Boss
	ActionFinal act1;// one of the three action the Boss got
	ActionFinal act2;// one of the three action the Boss got
	ActionFinal act3;// one of the three action the Boss got

} BossFinal;

typedef struct {// structure which define a Persona with his actions and a type

	char name[50];// name of the Persona
	int hp;// number of health point the Persona got
	int mp;// number of magic point the Persona got
	int dam;// number of damage the Persona deal
	int def; // number of defense point the persona got,it will reduce the damage dealed ( not implemented )
	int ag;// agility of a Persona, the higher attack first
	Type type;// type of the persona
	ActionFinal act1;// one of the two action the persona got
	ActionFinal act2;// one of the two action the persona got

} PersonaFinal;

void clearScanf();

Persona* getPersonalist();

void DisplayPersona(Persona* Personas);

Action* getActionlist();

void ChoicePersona(Persona* tabp, PersonaFinal* tab, PersonaFinal* CP1, PersonaFinal* CP2, char* NamePl1, char* NamePl2, int* N1);

Type* getTypelist();

void DisplayAttack();

void AskName(char* p_np, char* p_np2);

ActionFinal* AttributeTypetoAction(Action* taba, Type* tabt);

PersonaFinal* AttributeStructtoPersona(Persona* tabp, ActionFinal* tabaf, Type* tabt);

PersonaFinal RandFoe(PersonaFinal* tab, int* NF1);

int Move(PersonaFinal* P, PersonaFinal* P2, PersonaFinal* F1, PersonaFinal* F2, PersonaFinal* Other, char* NamePl, int* b1, int* b2, int* bP, int* bP2, int* di);

void Difficulty(int* p);

int MoveFoe(PersonaFinal* P1, PersonaFinal* P2, PersonaFinal* F1, PersonaFinal* FT, int* b1, int* b2 , int* b3, int* bFP, int* di);

int Negotiation(PersonaFinal* F1, int* n1, int* n2, int* n3, PersonaFinal* tab, PersonaFinal* New);

void DisplayInterface(PersonaFinal* P1, PersonaFinal* P2, PersonaFinal* F1, PersonaFinal* F2, PersonaFinal* Other, char* NamePl1, char* NamePl2, int* bF1, int* bF2, int* bP1, int* bP2);

BossFinal AttributeStructtoBoss(Boss BossAshura, ActionFinal* tabaf, Type* tabt);

Boss getBoss();

int Battle(PersonaFinal* P1, PersonaFinal* P2, PersonaFinal* F1, PersonaFinal* F2, PersonaFinal* Other, PersonaFinal* tab, int* bF1, int* bF2, int* bP, int* bP2, int* di, char* NamePl1, char* NamePl2, 
BossFinal* BAF, int* BB);

PersonaFinal TakeOther(PersonaFinal* tab);

int MoveAgainstBoss(PersonaFinal* P, PersonaFinal* P2, BossFinal* BAF, PersonaFinal* Other, char* NamePl, int* b1, int* bP, int* bP2, int* di);

int MoveofBoss(PersonaFinal* P1, PersonaFinal* P2, BossFinal* BAF, int* b1, int* b2, int* bB, int* d);

void DisplayInterfaceBoss(PersonaFinal* P1, PersonaFinal* P2, BossFinal* BAF, PersonaFinal* Other, char* NamePl1, char* NamePl2, int* BB, int* bP1, int* bP2);

int NegotiationBoss(BossFinal* BAF, int* n1, int* n2, int* nB, PersonaFinal* P1, PersonaFinal* P2);

int UltimateMove(PersonaFinal* P1, PersonaFinal* P2, BossFinal* BAF, int* b1, int* b2, int* bB);

void DisplayAttackF();
