
bptarea_init();		/* init */

bptarea_locate();	/* find free space */
bptarea_search();	/* find an area*/

bptarea_add();		/* add an area */
bptarea_modify();	/* modify an area */
bptarea_remove();	/* remove an area */

int		klc_make_unused(...)
{
  int		i;

  for (i = 0; i < alloc; i++)
    if (bptarea_locate(...) != 0)
      return (-1);

  ...
}

int		klc_add(...)
{
  if (klc_make_unused(...) != 0)
    return (-1);

  if (bptarea_add(...) != 0)
    {
      klc_clean_unused(...);
      return (-1);
    }

  return (0);
}

/*

. structure templatee car on utilise la structure de l arbre.

. question: pourquoi ne pas permettre soit de mettre directement la structure
  dans l arbre ou juste une sorte de pointeur vers cette structure.
  reponse: parceque dans les deux cas la structure va etre allouee, ou encore
  pire un block va etre alloue puis decoupe en N structure. donc autant
  fournir a l arbre le block et lui le decoupe et l'utilise au mieux, ce
  qui revient au meme. il est possible dans de rares cas qu on ait besoin
  d avoir la structure a un endroit precis (bien que je ne vois pas de
  cas comme ca), ces cas la ne pourront etre traites ou alors avec une
  bidouille de l'utilisateur c'est a dire en manageant un arbre d'adresses
  sur les structures, ce qui est tout a fait possible.

. prevoir differents algorighmes: first fit, best fit, worst fit ...
  ce qui implique un arbre different a chaque fois car il faut un interval
  qui represente quelque chose de particulier dans chaque cas. enfin l arbre
  sera identique mais le callback sera different.

. pour que la structure soit templatee, il faut soit comme bpt impose un
  certain nombres de champs predefinis soit faire de l'inclusion de struct
  dans notre struct avec nos champs ce qui me semble contraire au templates
  et allourdi la structure sans aucun interet bref je dis ca rapidement car
  ca n'a clairement aucun fondement.
  plus intelligemment, on a besoin de certains champs pour definir une area:
    - block (key)
    - nblocks (value)
    - user-defined fields to describe an area: type, permissions, ...

. a l'init il faut specifier a la libarea la taille de l'espace a gerer
  pour construire la premiere area quoique non en fait juste pour la
  garder dans sa structure de management car la premiere area sera free
  donc pas construite. de toute facon il faut avoir l'esprit ouvert pour
  que la personne puisse meme constuire une arbre d'areas free ... rien
  ne doit l'en empecher.

. peut etre pas besoin de faire de bpt_make() mais juste bptarea_make()

. le truc bien avec ca c'est que primo on utilise bpt.h donc on va trouver
  des bugs et deuxio ce sera directement utilisable par mon filesystem et meme
  on pourra l'implementer dans la gestion de la memoire d'un kernel pour avoir
  une gestion exceptionnellement complete et tres simple et rapide.

. enfin clairement le but de bpt et bptarea c'est de rassembler la gestion
  des elements algorithmiques compliques dans un meme source saint et
  exempt de bugs. de ce fait les couches superieures l'utiliser sans danger
  et le code de haut niveau est extrement simple et lisible ce qui est
  parfait pour la relecture donc pour la pedagogie, le suivi, la maintenance.

*/

