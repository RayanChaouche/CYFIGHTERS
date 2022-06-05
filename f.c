#include "h.h"

Persona* getPersonalist(){// Take from a file.txt every persona and put them in an array of persona
	FILE* file_Persona = NULL;
	file_Persona = fopen("Personas.txt", "r"); // open the file with the informations of every persona 
	if (file_Persona == NULL){
		printf("Ouverture du fichier impossible \n");
		exit(1);
	}
	Persona* Personas=NULL;
	Personas = malloc((NUMBEROFPERSONA)*sizeof(Persona));// create a list of Persona 
	int c;// cursor of the file
	char cc[200];
	int g,i;
		for(i=0;i<NUMBEROFPERSONA;i++){ // Will attribute every statistic of a persona to his attribute
			g=fscanf(file_Persona,"%s", (Personas[i].name));
			if(g==0){
				printf("\n error, fscanf(file_Persona, S , ((Personas+i)->name));");
				exit(1);
			}

			g=fscanf(file_Persona,"%d", &((Personas+i)->hp));
			if(g==0){
				printf("\n error, fscanf(file_Persona, d , ((Personas+i)->hp));");
				exit(1);
			}
			g=fscanf(file_Persona,"%d", &((Personas+i)->mp));
			if(g==0){
				printf("\n error, fscanf(file_Persona, d , ((Personas+i)->mp));");
				exit(1);
			}
			g=fscanf(file_Persona,"%d", &((Personas+i)->dam));
			if(g==0){
				printf("\n error, fscanf(file_Persona, d , ((Personas+i)->dam));");
				exit(1);
			}
			g=fscanf(file_Persona,"%d", &((Personas+i)->def));
			if(g==0){
				printf("\n error, fscanf(file_Persona, d , ((Personas+i)->def));");
				exit(1);
			}
			g=fscanf(file_Persona,"%d", &((Personas+i)->ag));
			if(g==0){
				printf("\n error, fscanf(file_Persona, d , ((Personas+i)->ag));");
				exit(1);
			}
			g=fscanf(file_Persona,"%s", ((Personas+i)->type));/////////////
			if(g==0){
				printf("\n error, fscanf(file_Persona, S , ((Personas+i)->type));");
				exit(1);
			}
			g=fscanf(file_Persona,"%s", ((Personas+i)->act1));/////////////
			if(g==0){
				printf("\n error, fscanf(file_Persona, S , ((Personas+i)->name));");
				exit(1);
			}
			g=fscanf(file_Persona,"%s", ((Personas+i)->act2));/////////////
			if(g==0){
				printf("\n error, fscanf(file_Persona, S , ((Personas+i)->name));");
				exit(1);
			}
		}

	fclose(file_Persona);
	return (Personas);
}




Action* getActionlist(){// Take from a file.txt every action and put them in an array of actions

	FILE* file_Action = NULL;
	file_Action = fopen("Action.txt", "r");/* open the file with the informations of every action */

	if (file_Action == NULL){
		printf("Ouverture du fichier impossible \n");
		exit(1);
	}
	Action* LAction=NULL;
	LAction = malloc((NUMBEROFACTION)*sizeof(Action));/* create a list of Action*/

	int g,i;
		for(i=0;i<NUMBEROFACTION;i++){ // Will attribute every statistic of an action to his attribute
			g=fscanf(file_Action,"%s", (LAction[i].name));
			if(g==0){
				printf("\n error, fscanf(file_Action, S , ((LAction+i)->name));");
				exit(1);
			}
			g=fscanf(file_Action,"%s", (LAction[i].type));
			if(g==0){
				printf("\n error, fscanf(file_Action, S , ((LAction+i)->type));");
				exit(1);
			}
			g=fscanf(file_Action,"%d", &((LAction+i)->hp_cost));
			if(g==0){
				printf("\n error, fscanf(file_Action, d , ((LAction+i)->hp_cost));");
				exit(1);
			}
			g=fscanf(file_Action,"%d", &((LAction+i)->mp_cost));
			if(g==0){
				printf("\n error, fscanf(file_Action, d , ((LAction+i)->mp_cost));");
				exit(1);
			}
			g=fscanf(file_Action,"%d", &((LAction+i)->dmg));
			if(g==0){
				printf("\n error, fscanf(file_Action, d , ((LAction+i)->dmg));");
				exit(1);
			}

		}

	fclose(file_Action);
	return(LAction);
}

Type* getTypelist(){// Take from a file.txt every type and put them in an array of type
	FILE* file_Type = NULL;
	file_Type = fopen("Type.txt", "r");/* open the file with the informations of every type */

	if (file_Type == NULL){
		printf("Ouverture du fichier impossible \n");
		exit(1);
	}
	Type* LType=NULL;
	LType = malloc((NUMBEROFTYPE)*sizeof(Type));/* create a list of Type*/

	int g,i;
		for(i=0;i<NUMBEROFTYPE;i++){ // Will attribute every type in a tab
			g=fscanf(file_Type,"%s", (LType[i].name));
			if(g==0){
				printf("\n error, fscanf(file_Type, S , ((LType+i)->name));");
				exit(1);
			}
			g=fscanf(file_Type,"%s", (LType[i].weakness));/////////////
			if(g==0){
				printf("\n error, fscanf(file_Type, S , ((LType+i)->weakness));");
				exit(1);
			}
			g=fscanf(file_Type,"%s", (LType[i].strength));
			if(g==0){
				printf("\n error, fscanf(file_Type, d , ((LType+i)->strenght));");
				exit(1);
			}

		}

	fclose(file_Type);
	return(LType);
}

ActionFinal* AttributeTypetoAction(Action* taba, Type* tabt){// Attribute the good structure type to an action
	ActionFinal* tabaf=NULL;
	tabaf=malloc((NUMBEROFACTION)*sizeof(ActionFinal));
	int i,j;
	for(i=0;i<NUMBEROFACTION;i++){//Dupplicate the actions except for the type
		for(j=0;j<51;j++){
			tabaf[i].name[j]=taba[i].name[j];
		}
		tabaf[i].hp_cost=taba[i].hp_cost;
		tabaf[i].mp_cost=taba[i].mp_cost;
		tabaf[i].dmg=taba[i].dmg;
		for(j=0;j<NUMBEROFTYPE;j++){
			if(0==strcmp(taba[i].type,tabt[j].name)){//compare between the name of the type of the unfinished action and the name of the type, if equal, put the right type in an action
				tabaf[i].type=tabt[j];
			}
		}

	}
	return(tabaf);
}

PersonaFinal* AttributeStructtoPersona(Persona* tabp, ActionFinal* tabaf, Type* tabt){// Attribute the good structure action to a persona
	PersonaFinal* tabf=NULL;
	tabf=malloc((NUMBEROFPERSONA)*sizeof(PersonaFinal));
	int i,j;
	for(i=0;i<NUMBEROFPERSONA;i++){//Dupplicate the personas except for the type and action
		for(j=0;j<51;j++){
			tabf[i].name[j]=tabp[i].name[j];
		}
		tabf[i].hp=tabp[i].hp;
		tabf[i].mp=tabp[i].mp;
		tabf[i].dam=tabp[i].dam;
		tabf[i].def=tabp[i].def;
		tabf[i].ag=tabp[i].ag;
		for(j=0;j<NUMBEROFACTION;j++){
			if(0==strcmp(tabp[i].act1,tabaf[j].name)){
				tabf[i].act1=tabaf[j];
			}		
		}
		for(j=0;j<NUMBEROFACTION;j++){//compare between the name of the action of the unfinished Persona and the name of the action, if equal, put the right action in the persona
			if(0==strcmp(tabp[i].act2,tabaf[j].name)){
				tabf[i].act2=tabaf[j];
			}
		}
		for(j=0;j<NUMBEROFTYPE;j++){//compare between the name of the type of the unfinished Persona and the name of the type, if equal, put the right type in the persona
			if(0==strcmp(tabp[i].type,tabt[j].name)){
				tabf[i].type=tabt[j];
			}
		}
		
		
	}
	return(tabf);
}
		
	

Boss getBoss(){//Take from a file.txt the stats of the final boss and put thoses stats in a Boss
	FILE* file_Boss = NULL;
	file_Boss = fopen("Boss.txt", "r"); // open the file with the informations of the boss
	if (file_Boss == NULL){
		printf("Ouverture du fichier impossible \n");
		exit(1);
	}
	Boss BossAshura;
	int c;// cursor of the file
	char cc[200];
	int g,i;

	g=fscanf(file_Boss,"%s", (BossAshura.name));
	if(g==0){
		printf("\n error, fscanf(file_Boss, S , ((Boss)->name));");
		exit(1);
	}
	g=fscanf(file_Boss,"%d", &(BossAshura.hp));
	if(g==0){
		printf("\n error, fscanf(file_Persona, d , ((Boss)->hp));");
		exit(1);
	}
	g=fscanf(file_Boss,"%d", &(BossAshura.mp));
	if(g==0){
		printf("\n error, fscanf(file_Boss, d , ((Boss)->mp));");
		exit(1);
	}
	g=fscanf(file_Boss,"%d", &(BossAshura.ag));
	if(g==0){
		printf("\n error, fscanf(file_Boss, d , ((Boss)->ag));");
		exit(1);
	}
	g=fscanf(file_Boss,"%s", (BossAshura.type));
	if(g==0){
		printf("\n error, fscanf(file_Boss, S , ((Boss)->type));");
		exit(1);
	}
	g=fscanf(file_Boss,"%s", (BossAshura.act1));
	if(g==0){
		printf("\n error, fscanf(file_Boss, S , ((Boss)->name));");
		exit(1);
	}
	g=fscanf(file_Boss,"%s", (BossAshura.act2));
	if(g==0){
		printf("\n error, fscanf(file_Persona, S , ((Boss)->name));");
		exit(1);
	}
	g=fscanf(file_Boss,"%s", (BossAshura.act3));
	if(g==0){
		printf("\n error, fscanf(file_Persona, S , ((Boss)->name));");
		exit(1);
	}

	fclose(file_Boss);
	return(BossAshura);
}

BossFinal AttributeStructtoBoss(Boss BossAshura, ActionFinal* tabaf, Type* tabt){// Attribute the right actions and type to the boss, same way as for the personas
	BossFinal BossAshuraF;
	int j;
		for(j=0;j<51;j++){
			BossAshuraF.name[j]=BossAshura.name[j];
		}
		BossAshuraF.hp=BossAshura.hp;
		BossAshuraF.mp=BossAshura.mp;
		BossAshuraF.ag=BossAshura.ag;
		for(j=0;j<NUMBEROFACTION;j++){
			if(0==strcmp(BossAshura.act1,tabaf[j].name)){
				BossAshuraF.act1=tabaf[j];
			}		
		}
		for(j=0;j<NUMBEROFACTION;j++){
			if(0==strcmp(BossAshura.act2,tabaf[j].name)){
				BossAshuraF.act2=tabaf[j];
			}		
		}
		for(j=0;j<NUMBEROFACTION;j++){
			if(0==strcmp(BossAshura.act3,tabaf[j].name)){
				BossAshuraF.act3=tabaf[j];
			}		
		}
		for(j=0;j<NUMBEROFTYPE;j++){
			if(0==strcmp(BossAshura.type,tabt[j].name)){
				BossAshuraF.type=tabt[j];
			}
		}
		
		
	return(BossAshuraF);
}
PersonaFinal RandFoe(PersonaFinal* tab, int* NF1){//Choose a random persona different than the one of the Player 1, and give it to the ennemy
	PersonaFinal Foe;
	int n;
	do{
		n=rand()%7;
	} while(n==*NF1);// if the random number is equal of the number of the persona of the player, reroll the number
	Foe=*(tab+n);
	return(Foe);
}

int Move(PersonaFinal* P, PersonaFinal* P2, PersonaFinal* F1, PersonaFinal* F2, PersonaFinal* Other, char* NamePl, int* b1, int* b2, int* bP, int* bP2, int* di){// function who'll do the move of the player or the ally
	int m, d, a, c, v, o;
	PersonaFinal Temp;
	v=1;
	m=6;
	a=5;
	c=6;
	if( ( (*P).hp==0 && (*P2).hp==0 ) || (*F1).hp==0 && (*F2).hp==0){// if the ennemy team is dead, don't act and quit the function
		printf("\nEverybody is dead, %s can't attack.", (*P).name);
		return(0);
	}
	if(*bP==1){//if knocked out, can't act and quit the function
		printf("You're knocked out so you can't act!");
		return(0);
	}
	while(m<1 || m>5 || 1!=v || ( (*Other).hp==0 && m==4 ) ){// ask what the player want to do
		printf("What do you want to do ? ( 1 for attack with %s, 2 for attack with %s, 3 for use an object, 4 for change your Persona, 5 for pass your turn)\n", NamePl, P->name);
		v=scanf("%d",&m);
		if( (*Other).hp==0 && m==4 ){// if he wants to change persone despite his second persona is either dead or non existent. Reask the choice
			printf("You don't have a valid Persona to change, choose another action.\n");
		}
		//clearScanf();/// i tried but it doesn't work
	}
	if(m==1){// lowest damage and fixed by the persona of the player
		while(c<1 || c>3 || 1!=v || ( (*F1).hp==0 && c==1 ) || ( (*F2).hp==0 && c==2 ) ){//ask who is the target while the target isnt avalaible, if everybody is unavalaible, he can pass his turn
			printf("Attack who? 1 for %s , 2 for %s, 3 for pass your turn\n", F1->name, F2->name);
			v=scanf("%d", &c);
			if(( (*F1).hp==0 && c==1 ) || ( (*F2).hp==0 && c==2 )){
				printf("\nThis target is unavalaible, choose another one\n");
			}
		}
		if(c==1){// 
			d=(P->dam)/2;//the basic attack is the dam stat of the persona/2
			if(*b1==1){
				d=d*2;
				*b1=0;
			}
			(*F1).hp-=d;
			DisplayAttack();
			if(((*F1).hp)<=0){// allow the player to negociate with the ennemy instead of kill him instantly 
				(*F1).hp=1;
				*b1=1;// knocked him out 
				printf("\n%s is knock out !\n", F1->name);
			}
		}
		else if(c==2){
			d=(P->dam)/2;
			if(*b2==1){//double the damage if already knocked out, but awake him
				d=d*2;
				*b2=0;
			}
			(*F2).hp-=d;
			DisplayAttack();
			if(((*F2).hp)<=0){// allow the player to negociate with the ennemy instead of kill him instantly 
				(*F2).hp=1;
				*b2=1;
				printf("%s is knock out !\n", F2->name);
			}
		}
		else if(c==3){
			printf("\nTurn passed\n");
			sleep(1);
			return(0);
		}
	return(0);
	}
	else if(m==2){
		while(a<1 || a>2 || 1!=v || ( a==1 && (*P).act1.mp_cost>0 && (*P).mp==0 )){//reask which action while the choice isn't corect ( if he choice an attack but no longer got mp for use it, reask the choice
			printf("\nWhich Action ?: \n 1 for %s, 2 for %s \n", (*P).act1.name, (*P).act2.name);
			if(a==1 && (*P).act1.mp_cost>0 && (*P).mp==0){
				printf("\nYou don't have any mp, choose another one\n");
			}
			v=scanf("%d", &a);
		}
		while(c<1 || c>2 || 1!=v || ((*F1).hp==0 && c==1) || ((*F2).hp==0 && c==2)){//ask who is the target while the target isnt avalaible, if everybody is unavalaible, he can pass his turn
			printf("Attack who? 1 for %s , 2 for %s \n ", F1->name, F2->name);
			v=scanf("%d", &c);
			if( ((*F1).hp==0 && c==1) || ((*F2).hp==0 && c==2) ){
				printf("This Persona is no longer an enemy, you can't attack him.\n");
			}
		}
		if(c==1){// calcul and took of the hp of the target, calcul and took of the hp cost and mp cost of the action to the launcher
		
			if(a==1){
				d=((*P).act1.dmg);
				if(*b1==1){//double damage but awaken the target
					d=d*2;
					*b1=0;
				}
				if(0==strcmp(((*P).act1.type.name),((*F1).type.name))){//same type so damage/3
					d=d/3;
				}
				else if(0==strcmp(((*P).act1.type.name),((*F1).type.weakness))){//good type so damage*2
					d=d*2;
					*b1=1;
				}
		
				(*F1).hp-=d;
				DisplayAttack();
				if(((*F1).hp)<=0){// allow the player to negociate with the ennemy instead of kill him instantly 
					(*F1).hp=1;
					*b1=1;
					printf("%s is knock out !\n", F1->name);
				}
				else if(*b1==1){
					printf("%s is knock out !\n", F1->name);
				}
				(*P).hp-=((*P).act1.hp_cost);
				if(((*P).hp)<0){
					(*P).hp=0;
				}
				(*P).mp-=((*P).act1.mp_cost);
				if(((*P).mp)<0){
					(*P).mp=0;
				}
			}
			if(a==2){
				d=((*P).act2.dmg);
				if(*b1==1){//double damage but awakened
					d=d*2;
					*b1=0;
				}
				if(0==strcmp(((*P).act2.type.name),((*F1).type.name))){//same type so damage/3
					d=d/3;
				}		
				else if(0==strcmp(((*P).act2.type.name),((*F1).type.weakness))){//good type so damage*2
					d=d*2;
					*b1=1;
				}	
				(*F1).hp-=d;
				DisplayAttack();
				if(*b1==1){
					printf("%s is knock out !\n", F1->name);
				}
				if(((*F1).hp)<=0){// allow the player to negociate with the ennemy instead of kill him instantly 
					(*F1).hp=1;
					*b1=1;
					printf("%s is knock out !\n", F1->name);
				}
				else if(*b1==1){
					printf("%s is knock out !\n", F1->name);
				}
				(*P).hp-=((*P).act2.hp_cost);
				if(((*P).hp)<0){
					(*P).hp=0;
				}
				(*P).mp-=((*P).act2.mp_cost);
				if(((*P).mp)<0){
					(*P).mp=0;
				}
			} 
		}
		if(c==2){// calcul and took of the hp of the target, calcul and took of the hp cost and mp cost of the action to the launcher
		
			if(a==1){
				d=((*P).act1.dmg);
				if(*b2==1){//double damage but awaken the target
					d=d*2;
					*b2=0;
				}
				if(0==strcmp(((*P).act1.type.name),((*F2).type.name))){//same type so damage/3
					d=d/3;
				}
				else if(0==strcmp(((*P).act1.type.name),((*F2).type.weakness))){//good type so damage*2
					d=d*2;
					*b2=1;
				}
				(*F2).hp-=d;
				DisplayAttack();
				if(((*F2).hp)<=0){// allow the player to negociate with the ennemy instead of kill him instantly 
					(*F2).hp=1;
					*b2=1;
					printf("%s is knock out !\n", F2->name);
				}
				else if(*b2==1){
					printf("%s is knock out !\n", F2->name);
				}
				(*P).hp-=((*P).act1.hp_cost);
				if(((*P).hp)<0){
					(*P).hp=0;
				}
				(*P).mp-=((*P).act1.mp_cost);
				if(((*P).mp)<0){
					(*P).mp=0;
				}
			}
			if(a==2){
				d=((*P).act2.dmg);
				if(*b2==1){//double damage but awaken the target
					d=d*2;
					*b2=0;
				}
				if(0==strcmp(((*P).act2.type.name),((*F2).type.name))){//same type so damage/3
					d=d/3;
				}		
				else if(0==strcmp(((*P).act2.type.name),((*F2).type.weakness))){//good type so damage*2
					d=d*2;
					*b2=1;
				}		
				(*F2).hp-=d;
				DisplayAttack();
				if(*b2==1){
					printf("%s is knock out !\n", F2->name);
				}
				if(((*F2).hp)<=0){// allow the player to negociate with the ennemy instead of kill him instantly 
					(*F2).hp=1;
					*b2=1;
					printf("%s is knock out !\n", F2->name);
				}
				else if(*b2==1){
					printf("%s is knock out !\n", F2->name);
				}
				(*P).hp-=((*P).act2.hp_cost);
				if(((*P).hp)<0){
					(*P).hp=0;
				}
				(*P).mp-=((*P).act2.mp_cost);
				if(((*P).mp)<0){
					(*P).mp=0;
				}
			}
		}
	return(0);
	}
	else if(m==3){
		while((o<1 || o>2 || v!=1) || ((*di==4) && o==2)){//ask which objet, reask if incorrect answer or if he choose an healing potion in hard mode
			printf("Which objet do you want to use? 1 for an elemental bomb, 2 for a healing potion:\n");
			v=scanf("%d", &o);
			if(o==2 && *di==4){
				printf("You can't use healing potion in hard mode.");
			}
		}
		if(o==1){//ask who is the target, can't choose a dead target
			while(c<1 || c>2 || 1!=v || ( c==1 && (*F1).hp==0 ) || ( c==2 && (*F2).hp==0 ) ){
				printf("\nToss the bomb on who? 1 for %s , 2 for %s \n ", F1->name, F2->name);
				v=scanf("%d", &c);
				if( c==1 && (*F1).hp==0 ){
					printf("%s is dead so you can't target him. Choose the other Persona", (*F1).name);
				}
				else if( c==2 && (*F2).hp==0 ){
					printf("\n%s is dead so you can't target him. Choose the other Persona\n", (*F2).name);
					sleep(2);
				}
			}
			if(c==1){//knock out the target
				*b1=1;
				printf("\n%s is now knock out!\n", (*F1).name);
				(*F1).hp-=25;
				if(((*F1).hp)<0){
					(*F1).hp=0;
				}
			}
			if(c==2){//knock out the target
				*b2=1;
				printf("\n%s is now knock out!\n", (*F2).name);
				(*F2).hp-=25;
				if(((*F2).hp)<0){
					(*F2).hp=0;
				}
			}
		}
		if(o==2){
			while(c<1 || c>2 || 1!=v){//ask heal who?
				printf("\nUse the potion on who? 1 for use on %s, 2 for use on %s\n", (*P).name, (*P2).name);
				v=scanf("%d", &c);
			}
			if(c==1){//heal the target
				(*P).hp+=150;
				printf("\n%s is now at %d pv\n", (*P).name, (*P).hp);
			}
			if(c==2){// heal the target
				(*P2).hp+=150;
				printf("\n%s is now at %d pv\n", (*P2).name, (*P2).hp);
			}
		}
	return(0);
	}
	else if(m==4){
		c=0;
		while(c<1 || c>2 || v!=1){//ask change the persona with which persona
			printf("Which Persona do you want to change?\n1 for %s , 2 for %s\n", (*P).name, (*P2).name);
			v=scanf("%d", &c);
		}
		if(c==1){//interchange the personas
			Temp=*Other;
			*Other=*P;
			*P=Temp;
			printf("Personas changed.\n");
		}
		if(c==2){
			Temp=*Other;
			*Other=*P2;
			*P2=Temp;
			printf("Personas changed.\n");
		}
	return(0);
	}
	else if(m==5){
		printf("\nTurn passed\n");
		sleep(1);
		return(0);
	}
}


int MoveAgainstBoss(PersonaFinal* P, PersonaFinal* P2, BossFinal* BAF, PersonaFinal* Other, char* NamePl, int* b1, int* bP, int* bP2, int* di){//same as against a normal ennemy, no object in hard mode ( difficulty 4 )
	int m, d, a, c, v, o;
	PersonaFinal Temp;
	v=1;
	m=6;
	a=5;
	c=6;
	if( ( (*P).hp==0 && (*P2).hp==0 ) || (*BAF).hp==0){
		printf("\nEverybody is dead, %s can't attack.", (*P).name);
		return(0);
	}
	if( (*P).hp==0 ){
		printf("\n%s is dead, you can't attack.\n", (*P).name);
		return(0);
	}
	if(*bP==1){
		printf("You're knocked out so you can't act!");
		return(0);
	}
	while(m<1 || m>5 || 1!=v || ( (*Other).hp==0 && m==4 ) || ( *di==4 && m==3)){
		printf("What do you want to do ? ( 1 for attack with %s, 2 for attack with %s, 3 for use an object, 4 for change your Persona, 5 for pass your turn)\n", NamePl, P->name);
		v=scanf("%d",&m);
		if( (*Other).hp==0 && m==4 ){
			printf("You don't have a valid Persona to change, choose another action.\n");
		}
		if( *di==4 && m==3 ){
			printf("You can't use object in hard mode against the final boss\n");
		}
		//clearScanf();/// i tried but it doesn't work
	}
	if(m==1){
		d=(P->dam)/2;
		if(*b1==1){
			d=d*2;
			*b1=0;
		}
		(*BAF).hp-=d;
		DisplayAttack();
		if(((*BAF).hp)<0){
			(*BAF).hp=0;
		}
	return(0);
	}
	else if(m==2){
		while(a<1 || a>2 || 1!=v){
			printf("Which Action ?: \n 1 for %s, 2 for %s \n", (*P).act1.name, (*P).act2.name);
			v=scanf("%d", &a);
		}
		if(a==1){
			d=((*P).act1.dmg);
			if(*b1==1){
				d=d*2;
				*b1=0;
			}
			if(0==strcmp(((*P).act1.type.name),((*BAF).type.name))){
				d=d/3;
			}
			else if(0==strcmp(((*P).act1.type.name),((*BAF).type.weakness))){
				d=d*2;
				*b1=1;
			}
		
			(*BAF).hp-=d;
			DisplayAttack();
			if(((*BAF).hp)<0){
				(*BAF).hp=0;
			}
			else if(*b1==1){
				printf("%s is knock out !\n", BAF->name);
			}
			(*P).hp-=((*P).act1.hp_cost);
			if(((*P).hp)<0){
				(*P).hp=0;
			}
			(*P).mp-=((*P).act1.mp_cost);
			if(((*P).mp)<0){
				(*P).mp=0;
			}
		}
		if(a==2){
			d=((*P).act2.dmg);
			if(*b1==1){
				d=d*2;
				*b1=0;
			}
			if(0==strcmp(((*P).act2.type.name),((*BAF).type.name))){
				d=d/3;
			}		
			else if(0==strcmp(((*P).act2.type.name),((*BAF).type.weakness))){
				d=d*2;
				*b1=1;
			}	
			(*BAF).hp-=d;
			DisplayAttack();
			if(((*BAF).hp)<0){
				(*BAF).hp=0;
			}
			else if(*b1==1){
				printf("%s is knock out !\n", BAF->name);
			}
			(*P).hp-=((*P).act2.hp_cost);
			if(((*P).hp)<0){
				(*P).hp=0;
			}
			(*P).mp-=((*P).act2.mp_cost);
			if(((*P).mp)<0){
				(*P).mp=0;
			}
		}
	return(0);
	}
	else if(m==3){
		while(o<1 || o>2 || v!=1 ){
			printf("\nWhich objet do you want to use? 1 for an elemental bomb, 2 for a healing potion, 3 for pass you turn:\n");
			v=scanf("%d", &o);
		}
		if(o==1){
			*b1=1;
			printf("\n%s is now knock out!\n", (*BAF).name);
			(*BAF).hp-=25;
			if(((*BAF).hp)<0){
				(*BAF).hp=0;
			}
		}
		if(o==2){
			while(c<1 || c>2 || 1!=v){
				printf("\nUse the potion on who? 1 for use on %s, 2 for use on %s\n", (*P).name, (*P2).name);
				v=scanf("%d", &c);
			}
			if(c==1){
				(*P).hp+=150;
				printf("\n%s is now at %d pv\n", (*P).name, (*P).hp);
			}
			if(c==2){
				(*P2).hp+=150;
				printf("\n%s is now at %d pv\n", (*P2).name, (*P2).hp);
			}
		}
	return(0);
	}
	else if(m==4){
		c=0;
		while(c<1 || c>2 || v!=1){
			printf("Which Persona do you want to change?\n1 for %s , 2 for %s\n", (*P).name, (*P2).name);
			v=scanf("%d", &c);
		}
		if(c==1){
			Temp=*Other;
			*Other=*P;
			*P=Temp;
			printf("Personas changed.\n");
		}
		if(c==2){
			Temp=*Other;
			*Other=*P2;
			*P2=Temp;
			printf("Personas changed.\n");
		}
	return(0);
	}
	else if(m==5){
		printf("\nTurn passed\n");
		sleep(1);
		return(0);
	}
}

int MoveFoe(PersonaFinal* P1, PersonaFinal* P2, PersonaFinal* F1, PersonaFinal* FP, int* b1, int* b2 , int* b3, int* bFP, int* d){//Turn of an annemy, change the target in function of the difficulty, same way of calculating the damage as for the player turn
	int lower, dmg;
	int who=0;
	int att;
	if(*bFP==1){//Don't act if knocked out
		printf("\n%s is knock out and cannot move !\n", (*FP).name);
		return(0);
	}
	if(((*FP).hp)==0 ){//If dead can't act
		printf(" %s is Dead and cannot move !", (*FP).name);
		return(0);
	}
	if( ( (*P1).hp==0 && (*P2).hp==0 ) || (*F1).hp==0 && (*FP).hp==0){//if the player's team is dead, don't act
		printf("\nEverybody is dead, %s can't attack.", (*FP).name);
		return(0);
	}
	if(*d==1){// very stupid, attack everybody randomly with the lowest damage the basic attack)
		do{
			who=rand()%3+1;
		} while((who==1 && ((*P1).hp)==0) || (who==2 && ((*P2).hp)==0) || (who==3 && ((*F1).hp)==0));
		dmg=(*FP).dam;
		dmg=dmg/2;
		DisplayAttack();
		if(who==1){
			(*P1).hp-=dmg;
			if(((*P1).hp)<0){
				(*P1).hp=0;
			}
			printf("%s attack %s!", (*FP).name, (*P1).name);
		}
		else if(who==2){
			(*P2).hp-=dmg;
			if(((*P2).hp)<0){
				(*P2).hp=0;
			}
			printf("%s attack %s!", (*FP).name, (*P2).name);
		}
		else if(who==3){
			(*F1).hp-=dmg;
			if(((*F1).hp)<0){
				(*F1).hp=0;
			}
			printf("%s attack his own ally %s!", (*FP).name, (*F1).name);
		}
	}
	else if(*d==2){//use the basic attack on the personas with the lowest hp, even his ally
		dmg=(*FP).dam;
		dmg=dmg/2;
		if(((*P1).hp)==0 && ((*P2).hp)==0 ){
			printf("\nEverybody is dead, %s can't attack.", (*FP).name);
			return(0);
		}
		DisplayAttack();
		if((((*P1).hp)<((*F1).hp)) && (((*P1).hp)<((*P2).hp)) && ((*P1).hp)!=0){
			(*P1).hp-=dmg;
			if(((*P1).hp)<0){
				(*P1).hp=0;
			}
			printf("%s attack %s!", (*FP).name, (*P1).name);
		}
		else if((((*P2).hp)<((*F1).hp)) && (((*P2).hp)<((*P1).hp)) && ((*P2).hp)!=0){
			(*P2).hp-=dmg;
			if(((*P2).hp)<0){
				(*P2).hp=0;
			}
			printf("%s attack %s!", (*FP).name, (*P2).name);
		}
		if((((*F1).hp)<((*P1).hp)) && (((*F1).hp)<((*P2).hp)) && ((*F1).hp)!=0){
			(*F1).hp-=dmg;
			if(((*F1).hp)<0){
				(*F1).hp=0;
			}
			printf("%s attack his own ally %s!", (*FP).name, (*F1).name);
		}
	}
	else if(*d==3){//use a random action against the persona with the lowest hp, even his ally
		if(((*P1).hp)==0 && ((*P2).hp)==0 ){
			printf("\nEverybody is dead, %s can't attack.", (*FP).name);
			return(0);
		}
		do{
			att=rand()%2;
		} while( (att==0 && (*FP).act1.mp_cost>0 && (*FP).mp==0) || (att==1 && (*FP).act2.mp_cost>0 && (*FP).mp==0));

		if(0==strcmp((*FP).name,"Mojo") && (*FP).mp>0){
			att=0;
		}
		if(0==strcmp((*FP).name,"Mojo") && (*FP).mp==0){
			printf("Mojo have 0 mp, he can't attack");
			return(0);
		}
		if(att==0){
		dmg=(*FP).act1.dmg;
		}
		else if(att==1){
		dmg=(*FP).act2.dmg;
		}
		if( (*P1).hp<(*F1).hp && (*P1).hp<(*P2).hp && (*P1).hp!=0 ){//calcul of who got the lowest hp
			lower=1;
		}
		else if( (*P2).hp<=(*F1).hp && (*P2).hp<=(*P1).hp && (*P2).hp!=0 ){//same
			lower=2;
		}
		else if( (*F1).hp<=(*P1).hp && (*F1).hp<=(*P2).hp && (*F1).hp!=0 ){//same
			lower=3;
		}
		if(lower==1){
			if(att==0){
				if(0==strcmp(((*FP).act1.type.name),((*P1).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act1.type.name),((*P1).type.weakness))){
					dmg=dmg*2;
					*b1=1;
				}
				(*P1).hp-=dmg;
				if(((*P1).hp)<0){
					(*P1).hp=0;
				}
				(*FP).hp-=(*FP).act1.hp_cost;
				if(((*P1).hp)<0){
					(*P1).hp=0;
				}
				(*FP).mp-=(*FP).act1.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on %s!\n", (*FP).name, (*FP).act1.name, (*P1).name);
				sleep(2);
				DisplayAttack();
				if(*b1==1){
					printf("%s is knock out !\n", (*P1).name);
				}
			}
			if(att==1){
				if(0==strcmp(((*FP).act2.type.name),((*P1).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act2.type.name),((*P1).type.weakness))){
					dmg=dmg*2;
					*b1=1;
				}
				(*P1).hp-=dmg;
				if(((*P1).hp)<0){
					(*P1).hp=0;
				}
				(*FP).hp-=(*FP).act2.hp_cost;
				if(((*FP).hp)<0){
					(*FP).hp=0;
				}
				(*FP).mp-=(*FP).act2.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on %s!\n", (*FP).name, (*FP).act2.name, (*P1).name);
				sleep(2);
				DisplayAttack();
				if(*b1==1){
					printf("%s is knock out !\n", (*P1).name);
				}
			}
		}
		if(lower==2){
			if(att==0){
				if(0==strcmp(((*FP).act1.type.name),((*P2).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act1.type.name),((*P2).type.weakness))){
					dmg=dmg*2;
					*b2=1;
				}
				(*P2).hp-=dmg;
				if(((*P2).hp)<0){
					(*P2).hp=0;
				}
				(*FP).hp-=(*FP).act1.hp_cost;
				if(((*FP).hp)<0){
					(*FP).hp=0;
				}
				(*FP).mp-=(*FP).act1.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on %s!\n", (*FP).name, (*FP).act1.name, (*P2).name);
				sleep(2);
				DisplayAttack();
				if(*b2==1){
					printf("%s is knock out !\n", (*P2).name);
				}
			}
			if(att==1){
				if(0==strcmp(((*FP).act2.type.name),((*P2).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act2.type.name),((*P2).type.weakness))){
					dmg=dmg*2;
					*b2=1;
				}
				(*P2).hp-=dmg;
				if(((*P2).hp)<0){
					(*P2).hp=0;
				}
				(*FP).hp-=(*FP).act2.hp_cost;
				if(((*FP).hp)<0){
					(*FP).hp=0;
				}
				(*FP).mp-=(*FP).act2.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on %s!\n", (*FP).name, (*FP).act2.name, (*P2).name);
				sleep(2);
				DisplayAttack();
				if(*b2==1){
					printf("%s is knock out !\n", (*P2).name);
				}
			}
		}
		if(lower==3){
			if(att==0){
				if(0==strcmp(((*FP).act1.type.name),((*F1).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act1.type.name),((*F1).type.weakness))){
					dmg=dmg*2;
					*b3=1;
				}
				(*F1).hp-=dmg;
				if(((*F1).hp)<0){
					(*F1).hp=0;
				}
				(*FP).hp-=(*FP).act1.hp_cost;
				if(((*FP).hp)<0){
					(*FP).hp=0;
				}
				(*FP).mp-=(*FP).act1.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on his own ally %s!\n", (*FP).name, (*FP).act1.name, (*F1).name);
				sleep(2);
				DisplayAttack();
				if(*b3==1){
					printf("%s is knock out !\n", (*F1).name);
				}
			}
			if(att==1){
				if(0==strcmp(((*FP).act2.type.name),((*F1).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act2.type.name),((*F1).type.weakness))){
					dmg=dmg*2;
					*b3=1;
				}
				(*F1).hp-=dmg;
				if(((*F1).hp)<0){
					(*F1).hp=0;
				}
				(*FP).hp-=(*FP).act2.hp_cost;
				if(((*FP).hp)<0){
					(*FP).hp=0;
				}
				(*FP).mp-=(*FP).act2.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on his own ally %s!\n", (*FP).name, (*FP).act2.name, (*F1).name);
				sleep(2);
				DisplayAttack();
				if(*b3==1){
					printf("%s is knock out !\n", (*F1).name);
				}
			}
		}
	}
	else if(*d==4){//use random action only against the player team ( the less stupid of the 4 difficulty )
		if(((*P1).hp)==0 && ((*P2).hp)==0 ){
			printf("\nEverybody is dead, %s can't attack.", (*FP).name);
			return(0);
		}
		do{
			att=rand()%2;
		} while( (att==0 && (*FP).act1.mp_cost>0 && (*FP).mp==0) || (att==1 && (*FP).act2.mp_cost>0 && (*FP).mp==0));
		if(0==strcmp((*FP).name,"Mojo") && (*FP).mp>0){
			att=0;
		}
		if(0==strcmp((*FP).name,"Mojo") && (*FP).mp==0){
			printf("Mojo have 0 mp, he can't attack");
			return(0);
		}
		if( (*P1).hp<(*P2).hp && (*P1).hp!=0 ){
			lower=1;
		}
		else if( (*P2).hp<=(*P1).hp && (*P2).hp!=0 ){
			lower=2;
		}
		if(att==0){
			dmg=(*FP).act1.dmg;
		}
		else if(att==1){
			dmg=(*FP).act2.dmg;
		}
		if(lower==1){
			if(att==0){
				if(*b1==1){
					dmg=dmg*1.5;
					*b1=0;// Because you'll receive damage, you're no longer knock out
				}
				if(0==strcmp(((*FP).act1.type.name),((*P1).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act1.type.name),((*P1).type.weakness))){
					dmg=dmg*2;
					*b1=1;
				}
				(*P1).hp-=dmg;
				if(((*P1).hp)<0){
					(*P1).hp=0;
				}
				(*FP).hp-=(*FP).act1.hp_cost;
				if(((*P1).hp)<0){
					(*P1).hp=0;
				}
				(*FP).mp-=(*FP).act1.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on %s!\n", (*FP).name, (*FP).act1.name, (*P1).name);
				sleep(2);
				DisplayAttack();
				if(*b1==1){
					printf("%s is knock out !\n", (*P1).name);
				}
			}
			if(att==1){
				if(*b1==1){
					dmg=dmg*1.5;
					*b1=0;// Because you'll receive damage, you're no longer knock out
				}
				if(0==strcmp(((*FP).act2.type.name),((*P1).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act2.type.name),((*P1).type.weakness))){
					dmg=dmg*2;
					*b1=1;
				}
				(*P1).hp-=dmg;
				if(((*P1).hp)<0){
					(*P1).hp=0;
				}
				(*FP).hp-=(*FP).act2.hp_cost;
				if(((*FP).hp)<0){
					(*FP).hp=0;
				}
				(*FP).mp-=(*FP).act2.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on %s!\n", (*FP).name, (*FP).act2.name, (*P1).name);
				sleep(2);
				DisplayAttack();
				if(*b1==1){
					printf("%s is knock out !\n", (*P1).name);
				}
			}
		}
		else if(lower==2){
			if(att==0){
				if(*b2==1){
					dmg=dmg*1.5;
					*b2=0;// Because you'll receive damage, you're no longer knock out
				}
				if(0==strcmp(((*FP).act1.type.name),((*P2).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act1.type.name),((*P2).type.weakness))){
					dmg=dmg*2;
					*b2=1;
				}
				(*P2).hp-=dmg;
				if(((*P2).hp)<0){
					(*P2).hp=0;
				}
				(*FP).hp-=(*FP).act1.hp_cost;
				if(((*FP).hp)<0){
					(*FP).hp=0;
				}
				(*FP).mp-=(*FP).act1.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on %s!\n", (*FP).name, (*FP).act1.name, (*P2).name);
				sleep(2);
				DisplayAttack();
				if(*b2==1){
					printf("%s is knock out !\n", (*P2).name);
				}
			}
			if(att==1){
				if(*b2==1){
					dmg=dmg*1.5;
					*b2=0;// Because you'll receive damage, you're no longer knock out
				}
				if(0==strcmp(((*FP).act2.type.name),((*P2).type.name))){
					dmg=dmg/3;
				}
				else if(0==strcmp(((*FP).act2.type.name),((*P2).type.weakness))){
					dmg=dmg*2;
					*b2=1;
				}
				(*P2).hp-=dmg;
				if(((*P2).hp)<0){
					(*P2).hp=0;
				}
				(*FP).hp-=(*FP).act2.hp_cost;
				if(((*FP).hp)<0){
					(*FP).hp=0;
				}
				(*FP).mp-=(*FP).act2.mp_cost;
				if(((*FP).mp)<0){
					(*FP).mp=0;
				}
				printf("\n%s use %s on %s!\n", (*FP).name, (*FP).act2.name, (*P2).name);
				sleep(2);
				DisplayAttack();
				if(*b2==1){
					printf("%s is knock out !\n", (*P2).name);
				}
			}
		}
	}
	return(0);
}


int MoveofBoss(PersonaFinal* P1, PersonaFinal* P2, BossFinal* BAF, int* b1, int* b2, int* bB, int* d){//Turn of the final boss, same as for the ennemies, but because he appears only in normal or hard mode, he in both of case attack with actions the player's team ( in normal mode he don't have ally so he can't attack them )
	int lower, dmg;
	int who=0;
	int att;
	lower=10;
	if(*bB==1){
		printf("\n%s is knock out and cannot move !\n", (*BAF).name);
		*b1=0;
		*b2=0;
		return(0);
	}
	if(((*BAF).hp)==0 ){
		printf("\n%s is Dead and cannot move !\n", (*BAF).name);
		return(0);
	}
	if( ( (*P1).hp==0 && (*P2).hp==0 ) || (*BAF).hp==0){
		printf("\nEverybody is dead, %s can't attack.\n", (*BAF).name);
		return(0);
	}
	att=rand()%2;
	if(att==0){
	dmg=(*BAF).act1.dmg;
	}
	else if(att==1){
	dmg=(*BAF).act2.dmg;
	}
	if( ( (*P1).hp<(*P2).hp && (*P1).hp!=0 ) || (*P2).hp==0 ){
		lower=1;
	}
	else if( ( (*P2).hp<=(*P1).hp && (*P2).hp!=0) || (*P1).hp==0){
		lower=2;
	}
	if(lower==1){
		if(*b1==1){
			dmg=dmg*1.5;
		}
		*b1=0;
		*b2=0;
		if(att==0){
			if(0==strcmp(((*BAF).act1.type.name),((*P1).type.name))){
				dmg=dmg/3;
			}
			
			else if(0==strcmp(((*BAF).act1.type.name),((*P1).type.weakness))){
				dmg=dmg*2;
				*b1=1;
			}
			(*P1).hp-=dmg;
			if(((*P1).hp)<0){
				(*P1).hp=0;
			}
			(*BAF).hp-=(*BAF).act1.hp_cost;
			if(((*BAF).hp)<0){
				(*BAF).hp=0;
			}
			(*BAF).mp-=(*BAF).act1.mp_cost;
			printf("\nAshura use %s on %s!\n", (*BAF).act1.name, (*P1).name);
			sleep(2);
			DisplayAttack();
			if(*b1==1){
				printf("\n%s is knock out !\n", (*P1).name);
			}
			
		}
		if(att==1){
			if(0==strcmp(((*BAF).act2.type.name),((*P1).type.name))){
				dmg=dmg/3;
			}
			else if(0==strcmp(((*BAF).act2.type.name),((*P1).type.weakness))){
				dmg=dmg*2;
				*b1=1;
			}
			(*P1).hp-=dmg;
			if(((*P1).hp)<0){
				(*P1).hp=0;
			}
			(*BAF).hp-=(*BAF).act2.hp_cost;
			if(((*BAF).hp)<0){
				(*BAF).hp=0;
			}
			(*BAF).mp-=(*BAF).act2.mp_cost;
			sleep(1);
			printf("\nAshura use %s on %s!\n", (*BAF).act2.name, (*P1).name);
			sleep(3);
			DisplayAttack();
			if(*b1==1){
				printf("\n%s is knock out !\n", (*P1).name);
			}
		}
	}
	if(lower==2){
		if(*b2==1){
			dmg=dmg*1.5;
		}
		*b1=0;
		*b2=0;
		if(att==0){
			if(0==strcmp(((*BAF).act1.type.name),((*P2).type.name))){
				dmg=dmg/3;
			}
			else if(0==strcmp(((*BAF).act1.type.name),((*P2).type.weakness))){
				dmg=dmg*2;
				*b2=1;
			}
			(*P2).hp-=dmg;
			if(((*P2).hp)<0){
				(*P2).hp=0;
			}
			(*BAF).hp-=(*BAF).act1.hp_cost;
			if(((*BAF).hp)<0){
				(*P2).hp=0;
			}
			(*BAF).mp-=(*BAF).act1.mp_cost;
			sleep(1);
			printf("\nAshura use %s on %s!\n", (*BAF).act1.name, (*P2).name);
			sleep(3);
			DisplayAttack();
			if(*b1==1){
				printf("\n%s is knock out !\n", (*P2).name);
			}
		}
		if(att==1){
			if(0==strcmp(((*BAF).act2.type.name),((*P2).type.name))){
				dmg=dmg/3;
			}
			else if(0==strcmp(((*BAF).act2.type.name),((*P2).type.weakness))){
				dmg=dmg*2;
				*b2=1;
			}
			(*P2).hp-=dmg;
			if(((*P2).hp)<0){
				(*P2).hp=0;
			}
			(*BAF).hp-=(*BAF).act2.hp_cost;
			if(((*BAF).hp)<0){
				(*BAF).hp=0;
			}
			(*BAF).mp-=(*BAF).act2.mp_cost;
			sleep(1);
			printf("\nAshura use %s on %s!\n", (*BAF).act2.name, (*P2).name);
			sleep(3);
			DisplayAttack();
			if(*b1==1){
				printf("\n%s is knock out !\n", (*P2).name);
			}
		}
	}
	return(0);
}



int Negotiation(PersonaFinal* F1, int* n1, int* n2, int* n3, PersonaFinal* tab, PersonaFinal* New){//Phase of negociation or all-out attack, if the negotiation succeed ( if the player answers well ), the persona ennemy became an ally, the all-out attack deals massive damage but awake the enemy
	int c, v, i, dmg;
	int ca1, ca2;
	ca1=rand()%2+1;// random temper, fearful or fearless

	if(*n1==1 && *n2==1){// can't act if both ko
		printf("\nYou're knock out and cannot move!\n");
		return(0);
	}
	if(*n3==1){//choice of what to do
		*n3=0;
		while(c<1 || c>2 || v!=1){
			printf("\n%s is knock out! What do you want to do?\n 1 for an all-out attack, 2 for start the negotiation.\n", (*F1).name);
			v=scanf("%d", &c);	
		}
		if(c==1){// all-out attack, deals massive damage
			c=0;
			dmg=180;
			printf("\n%s: No wai-!\n", (*F1).name);
			sleep(1.5);
			DisplayAttack();
			sleep(1);
			(*F1).hp-=dmg;
			if(((*F1).hp)<0){
				(*F1).hp=0;
				printf("\n%s is dead!\n", (*F1).name);
			}
		}
		if(c==2){// negotiation, the player has to answer correctly to make of the ennemy an ally, if he don't answer correctly, failure of the negotiation, ennemy awakened and exit of the function
			printf("\nStart of the negotiation.\n");
			sleep(2);
			if(ca1==1){// fearful temper
				c=0;
				while(c<1 || c>3 || v!=1){//Offers different choice of answers until either the negotiation succeed or fail
				printf("\n%s looks fearful.\nWhat to say?: 1 for 'Calm down buddy, i don't want you any harm.', 2 for 'i don't want any unnecessary death, join my team.', 3 for 'Join my team or I kill you right now.'\n", (*F1).name);
				v=scanf("%d", &c);
				}
				sleep(1);
				if(c==1){
					c=0;
					printf("\n%s looks more calm.\n%s: 'And what tells me you're not tricking me?'\n", (*F1).name, (*F1).name);
						sleep(2);
					while(c<1 || c>3 || v!=1){
						printf("\nWhat's your answer?:\n1 for 'I am not, join my team and I promise you safety', 2 for 'What is the point of trick a weakling like you ?', 3 for 'Shut up and join my team or I kill you right now.'\n");
						v=scanf("%d", &c);
					}
					if(c==1){
						sleep(2);
						printf("\n%s: 'Alright i'll believe you, let me join your team.'\n", (*F1).name);
						sleep(1);
						for(i=0;i<NUMBEROFPERSONA;i++){
							if(0==strcmp((*F1).name,tab[i].name)){
								*New=tab[i];
							}
						}
						(*F1).hp=0;
						(*F1).mp=0;
						printf("\n%s joined you team! You can change your Persona during a battle round.\n", (*F1).name);
					}
					if(c==2){
						c=0;
						sleep(2);				
						printf("\n%s looks troubled\n%s: 'A weakling? I knew you were looking down on me!'\n", (*F1).name, (*F1).name);
						sleep(2);
						while(c<1 || c>2 || v!=1){
							printf("\nWhat's your answer?:\n1 for 'Sorry, what i meant is that under my protection, you'll be safe.', 2 for 'I'm losing my cool, join my team right now'\n");
						v=scanf("%d", &c);
						}
						if(c==1){
							c=0;
							sleep(2);
							printf("\n%s: 'Alright i'll believe you, let me join your team.'\n", (*F1).name);
							sleep(1);
							for(i=0;i<NUMBEROFPERSONA;i++){
								if(0==strcmp((*F1).name,tab[i].name)){
									*New=tab[i];
								}
							}
							(*F1).hp=0;
							(*F1).mp=0;
							printf("\n%s joined you team! You can change your Persona during a battle round.\n", (*F1).name);
						}
						if(c==2){
							sleep(2);
							printf("\n%s looks really angry\n%s: I knew you humans were just liars, get lost.\nNegotiation failed.\n", (*F1).name, (*F1).name);
						}
					}
				}
				else if(c==2){
					c=0;
					sleep(2);
					printf("\n%s looks troubled.\n%s: 'Unnecessary death? So you'll kill me if you're not satisfied?'\n", (*F1).name, (*F1).name);
					sleep(2);
					while(c<1 || c>3 || v!=1){
						printf("\nWhat's your answer?:\n1 for 'I'll not, i'll just let you go', 2 for 'That's a possibility, so what do you want to do?', 3 for 'You're losing my time, hurry up and join my team'\n");
						v=scanf("%d", &c);
					}
					if(c==1){
						sleep(2);
						printf("\n%s: 'Alright i'll believe you, let me join your team.'\n", (*F1).name);
						for(i=0;i<NUMBEROFPERSONA;i++){
							if(0==strcmp((*F1).name,tab[i].name)){
								*New=tab[i];
							}
						}
						(*F1).hp=0;
						(*F1).mp=0;
						sleep(1);
						printf("%s joined you team! You can change your Persona during a battle round.\n", (*F1).name);
					}
					if(c==2){
						c=0;
						sleep(2);
						printf("\n%s looks still troubled.\n%s: Alright then I refuse, now what'll you do?\n", (*F1).name, (*F1).name);
						sleep(2);
						while(c<1 || c>2 || v!=1){
							printf("\nWhat's your answer?:\n1 for 'As you wish, goodbye', 2 for 'What a shame, die you fool'\n");
							v=scanf("%d", &c);
						}
						if(c==1){
							sleep(2);
							printf("%s: 'Sorry i was testing you, now i believe you, let me join your team.'\n", (*F1).name);
							for(i=0;i<NUMBEROFPERSONA;i++){
								if(0==strcmp((*F1).name,tab[i].name)){
									*New=tab[i];
								}
							}
							(*F1).hp=0;
							(*F1).mp=0;
							sleep(1);
							printf("\n%s joined you team! You can change your Persona during a battle round.\n", (*F1).name);
						}
						if(c==2){
							sleep(2);
							printf("\n%s looks really angry\n%s: I knew you humans were just liars, get lost.\nNegotiation failed.\n", (*F1).name, (*F1).name);
						}
					}
					if(c==3){
						sleep(2);
						printf("\n%s: 'I knew it, foolish human, get lost!\nNegotiation failed.'\n", (*F1).name);
					}
					
				}
				else if(c==3){
					sleep(2);
					printf("\n%s: 'As if i'll listen to a greedy human, get lost!\nNegotiation failed.'\n", (*F1).name);
				}
			}
			else if(ca1==2){//fearless temper
				c=0;
				while(c<1 || c>3 || v!=1){//Offers different choice of answers until either the negotiation succeed or fail
				printf("\n%s looks fearless.\nWhat to say?: 1 for 'Calm down buddy, i don't want you any harm.', 2 for 'i don't want any unnecessary death, join my team.', 3 for 'Join my team or I kill you right now.'\n", (*F1).name);
				v=scanf("%d", &c);
				}
				if(c==1){
					sleep(2);
					c=0;
					printf("\n%s looks disappointed.\n%s: 'Boring, I shouldn't even listen to somebody like you'\nNegotiation failed\n", (*F1).name, (*F1).name);
				}
				if(c==2){
					sleep(2);
					c=0;
					printf("\n%s looks interested.\n%s:'Oh? Is this a threat?'\n", (*F1).name, (*F1).name);
					sleep(2);
					while(c<1 || c>3 || v!=1){
						printf("\nWhat's your answer?:\n1 for 'No I wouldn't dare, sorry', 2 for 'It depends of your attitude', 3 for 'It is, join my team quickly or I'll kill you'\n");
						v=scanf("%d", &c);
					}
					if(c==1){
						sleep(2);
						printf("\n%s looks disappointed.\n%s: 'Boring, I shouldn't even talk with somebody like you'\nNegotiation failed\n", (*F1).name, (*F1).name);
					}
					if(c==2){
						c=0;
						sleep(2);				
						printf("\n%s looks interested\n%s: 'Is that so? So if I say no what'll you do'\n", (*F1).name, (*F1).name);
						sleep(2);
						while(c<1 || c>2 || v!=1){
							printf("\nWhat's your answer?:\n1 for 'I would kill you right here and now, why?', 2 for 'I would just let you go'\n");
						v=scanf("%d", &c);
						}
						if(c==1){
							c=0;
							sleep(2);
							printf("\n%s: 'Ahah how amusing, alright i'll join your team, it'll be fun'\n", (*F1).name);
							for(i=0;i<NUMBEROFPERSONA;i++){
								if(0==strcmp((*F1).name,tab[i].name)){
									*New=tab[i];
								}
							}
							(*F1).hp=0;
							(*F1).mp=0;
							sleep(1);
							printf("\n%s joined you team! You can change your Persona during a battle round.\n", (*F1).name);
						}
						if(c==2){
							sleep(2);
							printf("\n%s looks extremely annoyed\n%s: 'How boring, don't waste my time, get lost.'\nNegotiation failed.\n", (*F1).name, (*F1).name);
						}
					}
				}
				else if(c==3){
					c=0;
					sleep(2);
					printf("\n%s looks amazed.\n%s: 'Is that so? and what if I attack you instead ?'\n", (*F1).name, (*F1).name);
					sleep(2);
					while(c<1 || c>3 || v!=1){
						printf("\nWhat's your answer?:\n1 for 'You can try if you don't value your life', 2 for 'Then i'll slaughter you', 3 for 'Don't say such things, I'm sure we can find a room for negotiation.'\n");
						v=scanf("%d", &c);
					}
					if(c==2){
						sleep(2);
						printf("\n%s: 'Ahah, alright you're fun, let me join your team.'\n", (*F1).name);
						for(i=0;i<NUMBEROFPERSONA;i++){
							if(0==strcmp((*F1).name,tab[i].name)){
								*New=tab[i];
							}
						}
						(*F1).hp=0;
						(*F1).mp=0;
						sleep(1);
						printf("\n%s joined you team! You can change your Persona during a battle round.\n", (*F1).name);
					}
					if(c==1){
						c=0;
						sleep(2);
						printf("\n%s looks tempted.\n%s: 'Alright don't ask for forgiveness human!'\n", (*F1).name, (*F1).name);
						sleep(2);
						while(c<1 || c>2 || v!=1){
							printf("\nWhat's your answer?:\n1 for 'No wait!', 2 for 'What a shame, die you fool'\n");
							v=scanf("%d", &c);
						}
						if(c==2){
							sleep(2);
							printf("\n%s: 'Sorry i was testing you, I accept your offer, let me join your team.'\n", (*F1).name);
							for(i=0;i<NUMBEROFPERSONA;i++){
								if(0==strcmp((*F1).name,tab[i].name)){
									*New=tab[i];
								}
							}
							(*F1).hp=0;
							(*F1).mp=0;
							sleep(1);
							printf("\n%s joined you team! You can change your Persona during a battle round.\n", (*F1).name);
						}
						if(c==2){
							sleep(2);
							printf("\n%s looks really bored\n%s: 'I knew you humans were just big mouth, get lost.'\nNegotiation failed.\n", (*F1).name, (*F1).name);
						}
					}
					if(c==3){
						sleep(2);
						printf("\n%s: 'I knew it, foolish human, get lost!\nNegotiation failed.'\n", (*F1).name);
					}
					
				}
			}

		}
		c=0;
		return(0);
	}
	return(0);
}

int NegotiationBoss(BossFinal* BAF, int* n1, int* n2, int* nB, PersonaFinal* P1, PersonaFinal* P2){//Negotiation and all-out attack vs the final boss
	int c, v, dmg;
	dmg=rand()%41+490;//calcul of the damage deals by the all-out attack
	if( *n1==1 && *n2==1 ){//if ko, can't act and exit the function
		printf("\nYou're KO and cannot act.\n");
		return(0);
	}
	if( (*P1).hp==0 && (*P2).hp==0 ){//if dead too
		printf("\nYou're dead and cannot act...\n");
		return(0);
	}
	if((*BAF).hp==0){//if the boss is dead, exit the function
		printf("\nAshura is dead.\n");
		return(0);
	}
	if(*nB==1){//the boss is ko
		*nB=0;
		while( c<1 || c>2 || v!=1 ){
			printf("Ashura is KO, what do you want to do? 1 for an all-out attack, 2 for negotiate\n");
			v=scanf("%d", &c);
		}
		if(c==1){//deals massive damage, awake the boss and exit the function
			printf("\nAshura looks mad\n");
			(*BAF).hp-=dmg;
			if((*BAF).hp<0){
				(*BAF).hp=0;
			}
			sleep(2);
			DisplayAttack();
			return(0);
		}
		else if(c==2){//negotiation impossible with the boss, exit the function
			printf("Ashura looks mad...\n");
			sleep(2);
			printf("Impossible to talk with Ashura\n");
			sleep(2);
			printf("Negotiation failed\n");
			sleep(2);
			return(0);
		}
	}
}

int UltimateMove(PersonaFinal* P1, PersonaFinal* P2, BossFinal* BAF, int* b1, int* b2, int* bB){// only in hard mode, the boss can do an ultimate move every 4 turn, deals massive damage to the persona with the most lowest hp
	int dmg;
	if(*bB==1){
		printf("\nAshura is KO and cannot move.\n");
		sleep(1);
		return(0);
	}
	dmg=(*BAF).act3.dmg;
	if( (*P1).hp<(*P2).hp && (*P1).hp!=0 ){//if the persona of the player got the lowest hp, he is the target
		if(*b1==1){
			dmg=245;//extremely massive damage if already knock out 
		}
		*b1=0;//awake the target
		(*P1).hp-=dmg;
		printf("\nAshura use %s on %s!", (*BAF).act3.name, (*P1).name);
		sleep(2);
		DisplayAttackF();
		if( (*P1).hp<0 ){
			(*P1).hp=0;
		}
		return(0);
	}
	else if( (*P2).hp<=(*P1).hp && (*P2).hp!=0 ){//if the persona of the ally got the lowest hp, he is the target
		if(*b2==1){
			dmg=245;//same
		}
		*b2=0;//same
		(*P2).hp-=dmg;
		printf("\nAshura use %s on %s!", (*BAF).act3.name, (*P2).name);
		sleep(2);
		DisplayAttackF();
		if( (*P2).hp<0 ){
			(*P2).hp=0;
		}
		return(0);
	}
}


PersonaFinal TakeOther(PersonaFinal* tab){//attribute the persona 'None' to the second persona, only here for being change later if a negotiation succeed
	PersonaFinal Other;
	Other=tab[7];
	return(Other);
}

int Battle(PersonaFinal* P1, PersonaFinal* P2, PersonaFinal* F1, PersonaFinal* F2, PersonaFinal* Other, PersonaFinal* tab, int* bF1, int* bF2, int* bP, int* bP2, int* di, char* NamePl1, char* NamePl2, BossFinal* BAF, int* BB){//function of the battle, do every move, display of the battle and negociation in the good order until one duo is at 0hp, if the play's duo wins and the difficulty is normal or hard, start the fight with the final boss. Announce the winners in every case.
		int Timer=4;//timer of turn until the final boss use his ultimate move. Decrease every turn and launch the attack at 0
		int Temp=0;
		printf("\nStart of the Battle!\n");
		sleep(1);
		while( ( (*P1).hp!=0 || (*P2).hp!=0 ) && ( (*F1).hp!=0 || (*F2).hp!=0 ) ){// Do a turn of battle, display of battle and negotiation until one duo isn't at 0hp
			*bP2=0;
			*bP=0;
			DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
			if( (*P1).ag>(*P2).ag && (*P1).ag>=(*F1).ag && (*P1).ag>=(*F2).ag ){// the player attack first if his agilty his the highest, then the ally attack
				sleep(2);
				printf("\n Turn of %s:\n", NamePl1);
				sleep(2);
				Move(P1, P2, F1, F2, Other, NamePl1, bF1, bF2, bP, bP2, di);
				sleep(2);
				printf("\n %s's turn is over\n", NamePl1);
				sleep(2);
				DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

				sleep(2);
				printf("\n Turn of %s:\n", NamePl2);
				sleep(2);
				Move(P2, P1, F1, F2, Other, NamePl2, bF1, bF2, bP2, bP, di);
				sleep(2);
				printf("\n %s's turn is over\n", NamePl2);
				sleep(2);
				DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
				
				if( (*F1).ag>(*F2).ag ){//Then the enemy with the highest agility attack, then the last
					sleep(2);
					printf("\n Turn of %s:\n", (*F1).name);
					sleep(2);
					MoveFoe(P1, P2, F2, F1, bP, bP2 , bF2, bF1, di);
					printf("\n %s's turn is over\n", (*F1).name);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

					sleep(2);
					printf("\n Turn of %s:\n", (*F2).name);
					sleep(2);
					MoveFoe(P1, P2, F1, F2, bP, bP2 , bF1, bF2, di);
					printf("\n %s's turn is over\n", (*F2).name);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
				}

				else if( (*F2).ag>=(*F1).ag ){//Then the enemy with the highest agility attack, then the last ennemy
					sleep(2);
					printf("\n Turn of %s:\n", (*F2).name);
					sleep(2);
					MoveFoe(P1, P2, F1, F2, bP, bP2 , bF1, bF2, di);
					printf("\n %s's turn is over\n", (*F2).name);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);


					sleep(2);
					printf("\n Turn of %s:\n", (*F1).name);
					sleep(2);
					MoveFoe(P1, P2, F2, F1, bP, bP2 , bF2, bF1, di);
					printf("\n %s's turn is over\n", (*F1).name);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
				}
				if(*bF1==1 || *bF2==1){//if one of the enemy is ko, enter in negotiation phase
					Negotiation(F1, bP, bP2, bF1, tab, Other);
					Negotiation(F2, bP, bP2, bF2, tab, Other);
				}
			}
			else if( (*P2).ag>=(*P1).ag && (*P2).ag>=(*F1).ag && (*P2).ag>=(*F2).ag ){// the ally attack first if his agilty his the highest, then the player attack
				sleep(2);
				printf("\n Turn of %s:\n", NamePl2);
				sleep(2);
				Move(P2, P1, F1, F2, Other, NamePl2, bF1, bF2, bP2, bP, di);
				printf("\n %s's turn is over\n", NamePl2);
				sleep(2);
				DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

				sleep(2);
				printf("\n Turn of %s:\n", NamePl1);
				sleep(2);
				Move(P1, P2, F1, F2, Other, NamePl1, bF1, bF2, bP, bP2, di);
				printf("\n %s's turn is over\n", NamePl1);
				sleep(2);
				DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
	
				
				if( (*F1).ag>(*F2).ag ){//Then the enemy with the highest agility attack, then the last ennemy
					sleep(2);
					printf("\n Turn of %s:\n", (*F1).name);
					sleep(2);
					MoveFoe(P1, P2, F2, F1, bP, bP2 , bF2, bF1, di);
					printf("\n %s's turn is over\n", (*F1).name);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);		

					sleep(2);
					printf("\n Turn of %s:\n", (*F2).name);
					sleep(2);
					MoveFoe(P1, P2, F1, F2, bP, bP2 , bF1, bF2, di);
					printf("\n %s's turn is over\n", (*F2).name);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
				}

				else if( (*F2).ag>=(*F1).ag ){//Then the enemy with the highest agility attack, then the last ennemy
					sleep(2);
					printf("\n Turn of %s:\n", (*F2).name);
					sleep(2);
					MoveFoe(P1, P2, F1, F2, bP, bP2 , bF1, bF2, di);
					printf("\n %s's turn is over\n", (*F2).name);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

					sleep(2);
					printf("\n Turn of %s:\n", (*F1).name);
					sleep(2);
					MoveFoe(P1, P2, F2, F1, bP, bP2 , bF2, bF1, di);
					printf("\n %s's turn is over\n", (*F1).name);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
				}
				if(*bF1==1 || *bF2==1){//if one of the enemy is ko, enter in negotiation phase
					Negotiation(F1, bP, bP2, bF1, tab, Other);
					sleep(4);
					Negotiation(F2, bP, bP2, bF2, tab, Other);
					sleep(2);
				}
			}
			else if( (*F1).ag>(*P1).ag && (*F1).ag>(*P2).ag && (*F1).ag>(*F2).ag ){// the ennemy attack first if his agilty his the highest, then the other ennemy attack

				sleep(2);
				printf("\n Turn of %s:\n", (*F1).name);
				sleep(2);
				MoveFoe(P1, P2, F2, F1, bP, bP2 , bF2, bF1, di);
				printf("\n %s's turn is over\n", (*F1).name);
				sleep(2);
				DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

				sleep(2);
				printf("\n Turn of %s:\n", (*F2).name);
				sleep(2);
				MoveFoe(P1, P2, F1, F2, bP, bP2 , bF1, bF2, di);
				printf("\n %s's turn is over\n", (*F2).name);
				sleep(2);
				DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
				if( (*P1).ag>(*P2).ag ){//Then the member of the player's team with the highest agility attack, then the last attack


					sleep(2);
					printf("\n Turn of %s:\n", NamePl1);
					sleep(2);
					Move(P1, P2, F1, F2, Other, NamePl1, bF1, bF2, bP, bP2, di);
					sleep(2);
					printf("\n %s's turn is over\n", NamePl1);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

					sleep(2);	
					printf("\n Turn of %s:\n", NamePl2);
					sleep(2);
					Move(P2, P1, F1, F2, Other, NamePl2, bF1, bF2, bP2, bP, di);
					sleep(2);
					printf("\n %s's turn is over\n", NamePl2);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
				}
				else if( (*P2).ag>=(*P1).ag ){//Then the member of the player's team with the highest agility attack, then the last attack

					sleep(2);
					printf("\n Turn of %s:\n", NamePl2);
					sleep(2);
					Move(P2, P1, F1, F2, Other, NamePl2, bF1, bF2, bP2, bP, di);
					sleep(2);
					printf("\n %s's turn is over\n", NamePl2);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

					sleep(2);
					printf("\n Turn of %s:\n", NamePl1);
					sleep(2);
					Move(P1, P2, F1, F2, Other, NamePl1, bF1, bF2, bP, bP2, di);
					sleep(2);
					printf("\n %s's turn is over\n", NamePl1);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
	
				}
				if(*bF1==1 || *bF2==1){//if one of the enemy is ko, enter in negotiation phase
					Negotiation(F1, bP, bP2, bF1, tab, Other);
					sleep(4);
					Negotiation(F2, bP, bP2, bF2, tab, Other);
					sleep(2);
				}
			}
			else if( (*F2).ag>(*P1).ag && (*F2).ag>(*P2).ag && (*F2).ag>=(*F1).ag ){// the ennemy attack first if his agilty his the highest, then the other ennemy attack

				sleep(2);
				printf("\n Turn of %s:\n", (*F2).name);
				sleep(2);
				MoveFoe(P1, P2, F1, F2, bP, bP2 , bF1, bF2, di);
				printf("\n %s's turn is over\n", (*F2).name);
				sleep(2);
				DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

				sleep(2);
				printf("\n Turn of %s:\n", (*F1).name);
				sleep(2);
				MoveFoe(P1, P2, F2, F1, bP, bP2 , bF2, bF1, di);
				printf("\n %s's turn is over\n", (*F1).name);
				sleep(2);
				DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

				if( (*P1).ag>(*P2).ag ){//Then the member of the player's team with the highest agility attack, then the last attack

					sleep(2);
					printf("\n Turn of %s:\n", NamePl1);
					sleep(2);
					Move(P1, P2, F1, F2, Other, NamePl1, bF1, bF2, bP, bP2, di);
					printf("\n %s's turn is over\n", NamePl1);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

					sleep(2);
					printf("\n Turn of %s:\n", NamePl2);
					sleep(2);
					Move(P2, P1, F1, F2, Other, NamePl2, bF1, bF2, bP2, bP, di);
					printf("\n %s's turn is over\n", NamePl2);
					sleep(2);
				}
				else if( (*P2).ag>=(*P1).ag ){//Then the member of the player's team with the highest agility attack, then the last attack

					sleep(2);
					printf("\n Turn of %s:\n", NamePl2);
					sleep(2);
					Move(P2, P1, F1, F2, Other, NamePl2, bF1, bF2, bP2, bP, di);
					printf("\n %s's turn is over\n", NamePl2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);

					sleep(2);
					printf("\n Turn of %s:\n", NamePl1);
					sleep(2);
					Move(P1, P2, F1, F2, Other, NamePl1, bF1, bF2, bP, bP2, di);
					printf("\n %s's turn is over", NamePl1);
					sleep(2);
					DisplayInterface(P1, P2, F1, F2, Other, NamePl1, NamePl2, bF1, bF2, bP, bP2);
				}
				if(*bF1==1 || *bF2==1){//if one of the enemy is ko, enter in negotiation phase
					Negotiation(F1, bP, bP2, bF1, tab, Other);
					sleep(4);
					Negotiation(F2, bP, bP2, bF2, tab, Other);
					sleep(2);
				}
			}
		}
		if(  (*P1).hp==0 && (*P2).hp==0 ){//the player's team lose 
			printf("\nYou lose! Maybe you should try with a lower difficulty or with a different team...\n");
			return(0);
		}
		else if( (*F1).hp==0 && (*F2).hp==0 && *di<3){// the player's team wins in noob or easy mode
			printf("\nCongratulations! Now you should try in normal or hard mode for fight the Final Boss Ashura...");
			return(0);
		}
		else if( (*F1).hp==0 && (*F2).hp==0 && *di>2){//start the fight with the final boss if the difficulty is normal or hard
			*bP=0;
			*bP2=0;
			sleep(2);
			printf("\nGood job! You w-");
			sleep(3);
			printf("\nAshura: Wait. What do you think you've done? I'll make you pay for this, inferior beings.\n");
			sleep(4);
			printf("\nFinal Boss: Ashura engage the battle!\n");
			sleep(2);
			while( (*BAF).hp!=0 && ( (*P1).hp!=0 || (*P2).hp!=0 ) ){//Do the move, display of interface and negotiation until either the boss is dead or the player's team is dead
				DisplayInterfaceBoss(P1, P2, BAF, Other, NamePl1, NamePl2, BB, bP, bP2);
				sleep(3);
				printf("\nTurn of Ashura;\n");
				sleep(2);
				if(Timer==3 && *di==4){//inform when the ujltimate attack is coming 
					printf("\nAshura collects a lot of energy...\n");
					sleep(2);
				}
				if(Timer==2 && *di==4){//inform when the ujltimate attack is coming 
					printf("\nAshura attacks look extremely powerful...\n");
					sleep(2);
				}
				if(Timer==1 && *di==4){//inform when the ujltimate attack is coming 
					printf("\nAshura almost finished is attack...\n");
					sleep(2);
				}
				if(Timer==0 && *di==4){//if in hard mode, launch his ultimate attacks when the timer is at 0
					UltimateMove(P1, P2, BAF, bP, bP2, BB);
					Timer=5;
					sleep(1);
					printf("\nAshura start to charge energy again...\n");
					sleep(2);
					Temp=1;
				}
				if(*di==3 || Temp!=1){//The boss don't attack if he just use his ultimate move, else he attack
					MoveofBoss(P1, P2, BAF, bP, bP2, BB, di);
				}
				Temp=0;
				sleep(2);
				printf("\nEnd of Ashura's turn\n");
				Timer--;
				sleep(2);
				DisplayInterfaceBoss(P1, P2, BAF, Other, NamePl1, NamePl2, BB, bP, bP2);
				if( (*P1).ag>(*P2).ag ){// The player act first if his agility is higher

					sleep(2);
					printf("\nTurn of %s\n", NamePl1);
					MoveAgainstBoss(P1, P2, BAF, Other, NamePl1, BB, bP, bP2, di);
					sleep(2);
					printf("\nEnd of %s's turn\n", NamePl1);
					sleep(2);
					DisplayInterfaceBoss(P1, P2, BAF, Other, NamePl1, NamePl2, BB, bP, bP2);

					sleep(2);
					printf("\nTurn of %s\n", NamePl2);
					MoveAgainstBoss(P2, P1, BAF, Other, NamePl2, BB, bP2, bP, di);
					sleep(2);
					printf("\nEnd of %s's turn\n", NamePl2);
					sleep(1);
					DisplayInterfaceBoss(P1, P2, BAF, Other, NamePl1, NamePl2, BB, bP, bP2);
				}
				else if( (*P2).ag>=(*P1).ag ){// The ally act first if his agility is higher

					sleep(2);
					printf("\nTurn of %s\n", NamePl2);
					MoveAgainstBoss(P2, P1, BAF, Other, NamePl2, BB, bP2, bP, di);
					sleep(2);
					printf("\nEnd of %s's turn\n", NamePl2);
					sleep(2);
					DisplayInterfaceBoss(P1, P2, BAF, Other, NamePl1, NamePl2, BB, bP, bP2);

					sleep(2);
					printf("\nTurn of %s\n", NamePl1);
					MoveAgainstBoss(P1, P2, BAF, Other, NamePl1, BB, bP, bP2, di);
					sleep(2);
					printf("\nEnd of %s's turn\n", NamePl1);
					sleep(2);
					DisplayInterfaceBoss(P1, P2, BAF, Other, NamePl1, NamePl2, BB, bP, bP2);
				}
				sleep(2);
				if(*BB==1){//if the boss is ko, enter in the negotiation phase
					NegotiationBoss(BAF, bP, bP2, BB, P1, P2);
					DisplayInterfaceBoss(P1, P2, BAF, Other, NamePl1, NamePl2, BB, bP, bP2);
					sleep(2);
				}
			}
			if( (*BAF).hp==0 && ( (*P1).hp!=0 || (*P2).hp!=0 ) && *di==3){//wins against the final boss at the normal difficulty
				printf("\nAshura is dead!\nCongratulations! You won against the final boss, if you want a harder trial, try in hard mode\n Thanks for playing!\n");
				return(0);
			}
			if( (*BAF).hp==0 && ( (*P1).hp!=0 || (*P2).hp!=0 ) && *di==4){//wins against the final boss at the higher difficulty
				printf("\nAshura is dead!\nCongratulations! You won against the final boss\n Thanks for playing!\n");
				return(0);
			}
			if( (*BAF).hp==0 && (*P1).hp==0 && (*P2).hp==0 ){//Tie with the final boss
				printf("Tie! Almost done...\n Maybe you should try with a different team or a lower difficulty?\n Anyways, thanks for playing!");
				return(0);
			}
			if( (*BAF).hp!=0 && (*P1).hp==0 && (*P2).hp==0 ){//Lose against the final boss
				printf("You're dead, Game over...\n Maybe you should try with a different team or a lower difficulty?\n Anyways, thanks for playing!");
				return(0);
			}
		}
}

