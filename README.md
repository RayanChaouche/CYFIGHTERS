# CYFIGHTERS
Rayan Chaouche Grp 7 / Yssam Bairouki Grp 5

makefile: make pour compiler, make clean pour clean, exec pour executer le programme.

Règles: Combat en tour par tour avec 4 niveaux de difficultés, format 2v2 JcE( noob, easy, normal, hard) ( Combat d'un Boss suplémentaire si difficulté 3 ou 4 choisis, format 2v1 JcE( normal ou hard ))
  
  Victoire lorsque l'équipe adverse à été vaincu ( + Boss vaincu en difficulté normal et hard ), défaite si vous etez vaincu.
  La difficulté change la façon de se comporter des adversaires ( En easy les adversaires visent tout le monde aléatoirement, en hard ils visent le plus faible.
  Le Boss Final possède une attaque utlime en difficulté hard qu'il peut faire tout les 4 tour.
  Si vous avez déjà joué à un jeu de type tour par tour, il est conseillé de prendre la difficulté normal.
  Si vous êtez un habitué des jeux tour par tour ou de CYFIGHTER, essayez la difficulté hard.

  Le Joueur et l'allié possède chacun un Persona( une sorte de Pokémon ), vous controlez les actions des deux et les ennemies sont aussi des Personas, chaque Personas a ses stats uniques.
  
    Système de types et d'étourdissement: 7 types différents, tous forts contre eux mêmes, avec une faiblesse et neutre à tout le reste. Feu faible à l'Eau qui est faible à la Plante qui est faible face au Feu. Type Maudis (Curse) faible au type Bénis (Bless) et inversement. Type Sol (Ground) faible au type Electrique et inversement. Type Aucun (None) n'a aucune forces ni faiblesses.
    Une attaque super efficace inflige bien plus de dégats que si elle était neutre. Et pas trés efficace bien moins de dégats que si elle était neutre
    C'est le type de l'attaque et le type du Persona qui est comparé.
  
  
  Pendant un tour, le Joueur peut soit attaquer lui-même ( attaque basique basé sur la stat de degats basique, peu de dégats mais aucun contrecoup ni de coût en mp ), soit attaquer avec son Persona ( attaque bien plus puissante avec des types, qui soit on un coût en mp soit un contrecoup infligeant des dégats à soi-même )
  Pendant un tour le Joueur peut aussi utiliser un objet de son choix (indisponible en difficulté hard), soit une potion de soin qui restaure 150 pv ( même sur un Persona mort ), soit une bombe élémentaire infligeant 25 de dégats et étourdissant automatiquement la cible.
  
  Si une attaque d'un type super efficace touche la cibe, elle est étourdit (Knock Out). Si elle est étourdit elle ne peut agir, les prochains dégats qu'elle reçoit sont doublés et elle ne peut sort de l'état étourdit que si elle est touché par une attaque.
  
  
  Un Persona étourdit peut entrer en phase de négociation: pendant cette phase, soit vous pouvez déclencher une attaque général ( all-out attack ) infligeant de lourds dégats. Soit commencer à négocier avec le Persona ennemie, une négociation réussis entraine l'arrivée du Persona ennemie dans votre équipe et une négociation échoué la fin des négociations et de l'état étourdit. Il est parfois préférables d'essayer de faire rentrer un Persona dans notre équipe plutôt que l'affronter.
  
  La négociation est une suite de choix de réponse, si vos choix plaisent au Persona, il rejoindra votre équipe et inversement, si vous répondez mal, il mettra fin aux négociation.
  
  Chaque Persona a son caractères qui influe sur la négociation. Un Persona peut être peureux ( fearful ) ou téméraire ( fearless ), le premier doit être rassuré pour mener la négociation à bien tandis que l'autre doit être menacé.
  
  
  
  Pendant le tour de combat si un Persona a rejoind votre équipe grace à la phase de négociation, vous pouvez le changer avec le Persona de votre choix ( du Joueur comme de l'allié ) autant de fois que vous voulez du moment que le persona de secour n'est pas mort ( pv>0 ).
  
  Pendant le tour de combat le Joueur peut aussi passer son tour ( trés utile si l'adversaire est étourdit mais que vous ne voulez pas le faire sortir de son état en l'attaquant, permettant ainsi de rentrer dans la phase négociation ).
  
  Il est trés fortement conseillé de prendre 1 Hélios dans son équipe, car il est de type Bénis ( inverse du type du boss final si vous êtez en difficulté normal ou hard ) et peut se soigner.
  Inversement, il est trés fortement conseillé de ne pas prendre Mojo, ses stats sont mauvaise et sa seul attaque consiste à se soigner.
  
  Si vous compter utliliser une attaque de soin ( Healing_light de Hélios, Photosynthesis de Mojo ou Steal de Arsene ), visez un ennemie comme si vous attaquez normalement.
  
  Si vous comptez vaincre le boss final, il est conseillé de garder en vie Hélios ou au moins d'avoir un Persona de rechange.
  
  Le duo avec le Persona ayant la plus grande vitesse commence, puis l'autre duo attaque, ainsi de suite.
  La stat de défense existe et est affiché lors du choix, mais n'a aucun impact lors du combat.
  
  Je n'ai pas reussi à forcer l'utilisateur à ecrire un entier lorsqu'on lui demande, donc si on entre un caractere ou une chaine de cractere alors qu'on demande un entier, le programme crachera.
  
Listes des Personas:
      Arsene: 470 PV / 21 MP / 120 de dégats basique / 14 de vitesse / Type Maudis / Attaque 1: Bane / Attaque 2 :Steal 
      Thor: 500 PV / 16 Mp / 120 de dégats basique / 15 de vitesse / Type Electrique / Attaque 1: Thunder /Attaque 2: Mjolnir
      Hélios: 300 PV / 20 MP / 140 dégats basique / 17 de vitesse / Type Bénis / Attaque 1: Sun_Ray / Attaque 2: Healing_light
      Mojo: 250 PV / 25 Mp / 80 dégats basique / 3 de vitesse / Type Plante / Attaque 1 : Photosynthesis / Attaque 2 : None ( Aucune )
      Atlas: 450 PV/ 15 MP / 130 dégats basique / 6 de vitesse / Type Sol / Attaque 1: Earthquake / Attaque 2: Heavenly_Vault
      Cerbere: 400 PV/ 16 MP / 100 dégats basique / 12 de vitesse / Type Feu / Attaque 1: Bite / Attaque 2: Flame_throw
      Captain_Kid: 400 PV / 17 MP / 130 dégats basique / 11 de vitesse / Type Eau / Attaque 1: Maelstorm / Attaque 2: Ramming
      
Listes des attaques: ( les stats ci-dessous sont pour une attaque neutre )
      Bite: Aucun type / 40 pv de contrecoup / 0 en Mp / 100 pv infligés 
      Flame-throw:  Feu / 0 / 4 / 80
      Thunder: Electrique / 0 / 5 / 90
      Mjolnir: Aucun / 50 / 0 / 120
      Sun_Ray:Bénis / 0 / 6 / 120
      Earthquake: Sol / 0 / 4 / 95
      Heavenly_Vault: Aucun / 55 / 0 / 135
      Bane: Maudis / 0 / 4 / 80
      Maelstrom: Eau / 0 / 6 / 95
      Ramming: Aucun / 60 / 0 / 130
      Healing_light: / -300 ( donc 300 pv soigné ) / 5 / 0
      Photosynthesis: Aucun / -100 ( donc 100 pv soigné ) / 4 / 0 
      Steal: Aucun / -50 ( donc 50 pv soigné ) / 3 / 100
