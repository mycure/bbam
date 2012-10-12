/*
 * bptarea.h
 * 
 * sh.c
 * 
 * path          /home/mycure/lse/bptarea
 * 
 * made by mycure
 *         quintard julien   [quinta_j@epita.fr]
 * 
 * started on    Fri Oct 15 16:22:23 2004   mycure
 * last update   Fri Apr 29 00:06:43 2005   mycure
 */

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * debug
 */

#undef SH_DEBUG
#define BPTAREA_DEBUG
#define BPTAREA_DUMP

/*
 * types
 */

#define SH_ADDR_T		u_int32_t
#define SH_KEY_T		u_int32_t
#define SH_SIZE_T		u_int32_t

#define SH_ID_T			u_int16_t

typedef struct			s_sh_area
{
  SH_KEY_T			addr;
  SH_SIZE_T			nblocks;

  int				id;
}				t_sh_area;

/*
 * defines
 */

#define SH_BLKSZ		89

#define SH_UADDR		-1
#define SH_UKEY			-1
#define SH_USIZE		-1
#define SH_UID			-1

/*
 * make the bpt tree
 */

#include "../bpt.h"
#include "../bptarea.h"

bptarea_make(sh, BPTAREA_BLKSZ_T, BPT_NDI_T, BPT_UNI_T, BPT_NODES_T,
	     BPT_HEIGHT_T, SH_ADDR_T, SH_KEY_T, SH_SIZE_T, SH_ID_T,
	     t_sh_area, addr, nblocks);

/* XXX */
#include "../area.h"
/* XXX */

/*
 * command defines
 */

#define SH_ADD			"add"
#define SH_MOD			"mod"
#define SH_REM			"rem"
#define SH_RANGE		"range"
#define SH_LIST			"list"
#define SH_DUMP			"dump"
#define SH_INFO			"info"
#define SH_REINIT		"reinit"
#define SH_QUIT			"quit"
#define SH_HELP			"help"

/*
 * global variables
 */

unsigned int    ___loaded = 0;
unsigned int    ___allocated = 0;

/*
 * prototypes
 */

void			sh_load(t_bptarea(sh)			*bptarea,
				t_bptarea_addr(sh)		addr,
				void**				buf);

void			sh_unload(t_bptarea(sh)			*bptarea,
				  t_bptarea_addr(sh)		addr);

int			sh_idcmp(t_bptarea(sh)			*bptarea,
				 t_bptarea_id(sh)		id1,
				 t_bptarea_id(sh)		id2);

int			sh_coalesce(t_bptarea(sh)		*bptarea,
				    t_bptarea_area(sh)		*area1,
				    t_bptarea_area(sh)		*area2);
/*
void			sh_dump_inentry(t_bpt(sh)		*bpt,
					t_bpt_imm(sh)		*node,
					t_bpt_ndi(sh)		ndi);

void			sh_dump_lfentry(t_bpt(sh)		*bpt,
					t_bpt_imm(sh)		*node,
					t_bpt_ndi(sh)		ndi);

void			sh_dump_node(t_bpt(sh)			*bpt,
				     t_bpt_imm(sh)		*node,
				     t_bpt_height(sh)		level);

int			sh_dump_tree(t_bpt(sh)			*bpt);

void			sh_make_unused(t_bpt_unused(sh)		*unused,
				       t_bpt_addr(sh)		*array,
				       t_bpt_uni(sh)		size,
				       t_bpt_uni(sh)		alloc);

void			sh_clean_unused(t_bpt_unused(sh)	*unused,
					t_bpt_uni(sh)		size);

int			sh_init(t_bptarea(sh)			*bptarea,
				SH_ADDR_T			_start,
				SH_SIZE_T			_size);

int			sh_clean(t_bptarea(sh)			*bptarea);

unsigned int		sh_nargs(char				**cmds);

char			**sh_cut(char				*line,
				 char				*sep);

void			sh_add(t_bptarea(sh)			*bptarea,
			       char				**cmds);

void			sh_mod(t_bptarea(sh)			*bptarea,
			       char				**cmds);

void			sh_rem(t_bptarea(sh)			*bptarea,
			       char				**cmds);

void			sh_range(t_bptarea(sh)			*bptarea,
				 char				**cmds);

void			sh_list(t_bptarea(sh)			*bptarea,
				char				**cmds);

void			sh_dump(t_bptarea(sh)			*bptarea,
				char				**cmds);

void			sh_help(t_bptarea(sh)			*bptarea,
				char				**cmds);

void			sh_info(t_bptarea(sh)			*bptarea,
				char				**cmds);

void			sh_reinit(t_bptarea(sh)			*bptarea,
				  char				**cmds);

void			sh_quit(t_bptarea(sh)			*bptarea,
				char				**cmds);
*/

/*
 * functions in relation with bptarea
 */

void			sh_load(t_bptarea(sh)			*bptarea,
				t_bptarea_addr(sh)		addr,
				void**				buf)
{
  *buf = (void *)((unsigned int)addr);
}

void			sh_unload(t_bptarea(sh)			*bpt,
				  t_bptarea_addr(sh)		addr)
{
  /*
   * nothing
   */
}

int			sh_idcmp(t_bptarea(sh)			*bptarea,
				 t_bptarea_id(sh)		id1,
				 t_bptarea_id(sh)		id2)
{
  return (id1 - id2);
}

int			sh_coalesce(t_bptarea(sh)		*bptarea,
				    t_bptarea_area(sh)		*area1,
				    t_bptarea_area(sh)		*area2)
{

#if 1
  fprintf(stderr, "[sh] coalesce\n");
#endif

  if (area1->id == area2->id)
    return (0);

  return (-1);
}

/*
 * functions
 */

void			sh_dump_inentry(t_bpt(ash)		*bpt,
					t_bpt_imm(ash)		*node,
					t_bpt_ndi(ash)		ndi)
{
  t_bpt_inentry(ash)	*inentry = BPT_INENTRY(ash, node, ndi);

  printf("[%u]     addr:%d     nblocks:%d     range:%d\n",
	 ndi,
	 inentry->area.addr,
	 inentry->area.nblocks,
	 inentry->range);
}

void			sh_dump_lfentry(t_bpt(ash)		*bpt,
					t_bpt_imm(ash)		*node,
					t_bpt_ndi(ash)		ndi)
{
  t_bpt_lfentry(ash)	*lfentry = BPT_LFENTRY(ash, node, ndi);

  printf("[%u]     addr:%d     nblocks:%d     range:%d     id:%d\n",
	 ndi,
	 lfentry->area.addr,
	 lfentry->area.nblocks,
	 lfentry->range,
	 lfentry->area.id);
}

void			sh_dump_node(t_bpt(ash)			*bpt,
				     t_bpt_imm(ash)		*node,
				     t_bpt_height(ash)		level)
{
  /* XXX
  t_bpt_ndi(ash)	nkeys = BPT_NKEYS(ash, bpt, node);
  t_bpt_ndi(ash)	i;
  t_bpt_ndi(ash)	j;

  for (j = 0; j < level; j++)
    printf(" ");

  printf("[head] %s 0x%x, parent:0x%x prv:0x%x nxt:0x%x\n",
	 BPT_GET_HEAD(ash, node, type) == BPT_TYPE_LEAF ? "leaf" : "internal",
	 node->addr,
	 BPT_GET_HEAD(ash, node, parent),
	 BPT_GET_HEAD(ash, node, prv),
	 BPT_GET_HEAD(ash, node, nxt));

  for (i = 0; i < nkeys; i++)
    {

#ifndef BPTAREA_DUMP
      if (BPT_GET_ENTRY(ash, node, i, area.nblocks) ==
	  BPT_UNUSED(sh, bpt, node))
	continue;
#endif

      for (j = 0; j < level; j++)
	printf(" ");

#if 0
      printf("[%d] %d %d %d\n",
	     i,
	     BPT_GET_ENTRY(sh, node, i, area.addr),
	     BPT_GET_ENTRY(sh, node, i, area.nblocks),
	     BPT_GET_ENTRY(sh, node, i, range));
#endif

      if (BPT_GET_HEAD(sh, node, type) == BPT_TYPE_INTERNAL)
	sh_dump_inentry(bpt, node, i);
      else
	sh_dump_lfentry(bpt, node, i);

      if ((BPT_GET_HEAD(sh, node, type) == BPT_TYPE_INTERNAL) &&
          (BPT_GET_ENTRY(sh, node, i, area.nblocks) !=
	   BPT_UNUSED(sh, bpt, node)))
	{
          t_bpt_imm(sh)	child;

          BPT_LOAD(bpt, &child, BPT_GET_ENTRY(sh, node, i, area.nblocks));

          sh_dump_node(bpt, &child, level + 1);

          BPT_UNLOAD(bpt, &child);
	}
    }
  */
}

int			sh_dump_tree(t_bpt(ash)			*bpt)
{
  t_bpt_imm(ash)	root;

  printf("\n");

  BPT_LOAD(bpt, &root, BPT_GET_ROOT(bpt));
  sh_dump_node(bpt, &root, 0);
  BPT_UNLOAD(bpt, &root);

  printf("\n");
  printf("[bptarea] nodes:%u height:%u blksz:%u nikeys:%u "
	 "nlkeys:%u root:0x%x\n",
	 bpt->nodes, bpt->height, bpt->nodesz,
	 bpt->nikeys, bpt->nlkeys, bpt->root);
  printf("\n");

  return (0);
}

void			sh_make_unused(t_bptarea_unused(sh)	*unused,
				       t_bptarea_addr(sh)	*array,
				       t_bptarea_uni(sh)	size,
				       t_bptarea_uni(sh)	alloc)
{
  t_bptarea_uni(sh)	i;

  unused->array = array;
  unused->index = alloc - 1;

  for (i = 0; i < size; i++)
    unused->array[i] = (t_bptarea_addr(sh))SH_UADDR;

  for (i = 0; i < alloc; i++)
    {
      unused->array[i] = (t_bptarea_addr(sh))((unsigned int)malloc(SH_BLKSZ));
      ___allocated++;

      printf("[%d] allocating 0x%x\n", i, unused->array[i]);
    }
}

void			sh_clean_unused(t_bptarea_unused(sh)	*unused,
					t_bptarea_uni(sh)	size)
{
  t_bptarea_uni(sh)	i;

  for (i = 0; i < size; i++)
    if (unused->array[i] != SH_UADDR)
      {

	printf("[%d] freeing 0x%x\n", i, unused->array[i]);

	free((void *)((unsigned int)unused->array[i]));
	___allocated--;
      }
}

int			sh_init(t_bptarea(sh)			*bptarea,
				SH_ADDR_T			_start,
				SH_SIZE_T			_size)
{
  t_bptarea_uni(sh)	alloc = BPTAREA_INIT_ALLOC();
  t_bptarea_uni(sh)	size = BPTAREA_INIT_SIZE();
  t_bptarea_addr(sh)	array[size];
  t_bptarea_unused(sh)	unused;

  sh_make_unused(&unused, array, size, alloc);

  if (bptarea_init_ash(bptarea, SH_BLKSZ, SH_UADDR, SH_UKEY, SH_USIZE,
		       SH_UID, sh_load, sh_unload, sh_idcmp, sh_coalesce,
		       BPTAREA_FIT_WORST, _start, _size, &unused) != 0)
    {
      sh_clean_unused(&unused, size);
      return (-1);
    }

  sh_clean_unused(&unused, size);

  return (0);
}

int			sh_clean(t_bptarea(sh)			*bptarea)
{
  t_bptarea_uni(sh)	alloc = BPTAREA_CLEAN_ALLOC(bptarea);
  t_bptarea_uni(sh)	size = BPTAREA_CLEAN_SIZE(bptarea);
  t_bptarea_addr(sh)	array[size];
  t_bptarea_unused(sh)	unused;

  sh_make_unused(&unused, array, size, alloc);

  if (bptarea_clean_ash(bptarea, &unused) != 0)
    {
      sh_clean_unused(&unused, size);
      return (-1);
    }

  sh_clean_unused(&unused, size);

  return (0);
}

unsigned int		sh_nargs(char				**cmds)
{
  unsigned int		i;

  for (i = 0; cmds[i]; i++)
    ;

  return (i);
}

char			**sh_cut(char				*line,
				 char				*sep)
{
  char			**data;
  unsigned long		cnt;
  unsigned long		i;
  unsigned long		p;

  for (p = 0, i = 0, cnt = 0; line[i]; cnt++)
    {
      while (line[i] && (strncmp(line + i, sep, strlen(sep)) == 0))
        i += strlen(sep);
      p = i;
      while (line[i] && (strncmp(line + i, sep, strlen(sep)) != 0))
        i += strlen(sep);
    }

  data = malloc((cnt + 1) * sizeof(char *));

  for (p = 0, i = 0, cnt = 0; line[i]; )
    {
      while (line[i] && (strncmp(line + i, sep, strlen(sep)) == 0))
        i += strlen(sep);
      p = i;
      while (line[i] && (strncmp(line + i, sep, strlen(sep)) != 0))
        i += strlen(sep);

      if (p != i)
        {
          data[cnt] = malloc((i - p + 1) * sizeof(char));
          strncpy(data[cnt], line + p, i - p);
          data[cnt++][i - p] = 0;
        }
    }
  data[cnt] = NULL;

  return (data);
}

void			sh_add(t_bptarea(sh)			*bptarea,
			       char				**cmds)
{
  t_bptarea_uni(sh)	alloc = BPTAREA_ADD_ALLOC(bptarea);
  t_bptarea_uni(sh)	size = BPTAREA_ADD_SIZE(bptarea);
  t_bptarea_addr(sh)	array[size];
  t_bptarea_unused(sh)	unused;
  t_bptarea_area(sh)	area;
  t_bptarea_id(sh)	id;

  printf("alloc:%d size:%d\n", alloc, size);

  if (sh_nargs(cmds) != 4)
    {
      fprintf(stderr, "[sh] syntax: add [addr] [nblocks] [id]\n");
      return ;
    }

  area.addr = strtoull(cmds[1], NULL, 0);
  area.nblocks = strtoull(cmds[2], NULL, 0);
  area.id = strtoull(cmds[3], NULL, 0);

  sh_make_unused(&unused, array, size, alloc);

  if (bptarea_add_ash(bptarea, area.id, &area, &unused) != 0)
    {
      sh_clean_unused(&unused, size);
      fprintf(stderr, "[sh] cannot add an area\n");
      return ;
    }

  sh_clean_unused(&unused, size);
}

void			sh_mod(t_bptarea(sh)			*bptarea,
			       char				**cmds)
{
  t_bptarea_uni(sh)	alloc = BPTAREA_MODIFY_ALLOC(bptarea);
  t_bptarea_uni(sh)	size = BPTAREA_MODIFY_SIZE(bptarea);
  t_bptarea_addr(sh)	array[size];
  t_bptarea_unused(sh)	unused;
  t_bptarea_key(sh)	key;
  t_bptarea_area(sh)	area;

  if (sh_nargs(cmds) != 4)
    {
      fprintf(stderr, "[sh] syntax: mod [addr] [nblocks] [id]\n");
      return ;
    }

  area.addr = strtoull(cmds[1], NULL, 0);
  area.nblocks = strtoull(cmds[2], NULL, 0);
  area.id = strtoull(cmds[3], NULL, 0);

  sh_make_unused(&unused, array, size, alloc);

  if (bptarea_modify_ash(bptarea, &area, &unused) != 0)
    {
      sh_clean_unused(&unused, size);
      fprintf(stderr, "[sh] cannot modify an area\n");
      return ;
    }

  sh_clean_unused(&unused, size);
}

void			sh_rem(t_bptarea(sh)			*bptarea,
			       char				**cmds)
{
  t_bptarea_uni(sh)	alloc = BPTAREA_REMOVE_ALLOC(bptarea);
  t_bptarea_uni(sh)	size = BPTAREA_REMOVE_SIZE(bptarea);
  t_bptarea_addr(sh)	array[size];
  t_bptarea_unused(sh)	unused;
  t_bptarea_area(sh)	area;

  if (sh_nargs(cmds) != 4)
    {
      fprintf(stderr, "[sh] syntax: rem [addr] [nblocks]\n");
      return ;
    }

  area.addr = strtoull(cmds[1], NULL, 0);
  area.nblocks = strtoull(cmds[2], NULL, 0);
  area.id = -42;

  sh_make_unused(&unused, array, size, alloc);

  if (bptarea_remove_ash(bptarea, &area, &unused) != 0)
    {
      sh_clean_unused(&unused, size);
      fprintf(stderr, "[sh] cannot remove an area\n");
      return ;
    }

  sh_clean_unused(&unused, size);
}

void			sh_range(t_bptarea(sh)			*bptarea,
				 char				**cmds)
{
  /*
  t_bptarea_addr(T)	addr;
  t_bptarea_area(T)	ref;

  if ((sh_nargs(cmds) < 2) ||
      (sh_nargs(cmds) > 3))
    {
      fprintf(stderr, "[sh] syntax: range [size]     [id]\n");
      return ;
    }

  if (sh_nargs(cmds) == 3)
    {
      ref.nblocks = strtoul(cmds[1], NULL, 0);
      ref.id = strtoul(cmds[2], NULL, 0);
  */
      /* XXX
      if (bptarea_coal_range_ash(bptarea, &ref, &addr) != 0)
	{
	  fprintf(stderr, "[sh] cannot find a coalescing range\n");
	  return ;
	}
      */
	/*
      printf("[coalescing range] %u\n", addr);

      return ;
    }
	*/
  // XXX
}

void			sh_dump_entry(t_bpt(ash)		*bpt,
                                      t_bpt_imm(ash)		*node,
                                      t_bpt_ndi(ash)		i)
{
  printf("[%u] %u : %u\n",
         i,
         BPT_GET_ENTRY(ash, node, i, area.addr) == bpt->ukey ?
         -1 : BPT_GET_ENTRY(ash, node, i, area.addr),
         BPT_GET_ENTRY(ash, node, i, area.nblocks) == bpt->ukey ?
         -1 : BPT_GET_ENTRY(ash, node, i, area.nblocks));
}

void			sh_list(t_bptarea(sh)			*bptarea,
				char				**cmds)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_entry(ash)	current;
  t_bpt_entry(ash)	entry;
  t_bpt_imm(ash)	node;

  BPT_LOAD(bpt, &node, bpt->root);

  if (bpt_list(ash, bpt, &node, &entry, BPT_OPT_HEAD) != 0)
    {
      BPT_UNLOAD(bpt, &node);
      return ;
    }

  BPT_UNLOAD(bpt, &node);
  BPT_LOAD(bpt, &node, entry.node);

  do
    {
      if (node.addr != entry.node)
	{
	  BPT_UNLOAD(bpt, &node);
	  BPT_LOAD(bpt, &node, entry.node);
	}

      sh_dump_entry(bpt, &node, entry.ndi);

      current.node = node.addr;
      current.ndi = entry.ndi;
    } while (bpt_next_entry(ash, bpt, current, &entry, BPT_OPT_TREE) == 0);

  BPT_UNLOAD(bpt, &node);
}

/* XXX
void			sh_list(t_bptarea(sh)			*bptarea,
				char				**cmds)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_entry(ash)	entry;

  entry.node = bpt->uaddr;

  while (bptarea_foreach(sh, bpt, &entry) == 0)
    {
      t_bptarea_area(T)	area;

      BPTAREA_LOAD(sh, bptarea, &entry, &area);

      printf("[%u:%u] %u %u\n",
	     entry.node, entry.ndi,
	     area.addr, area.nblocks);
    }
}
*/

void			sh_dump(t_bptarea(sh)			*bptarea,
				char				**cmds)
{
  if (sh_dump_tree(&bptarea->areas) != 0)
    {
      bpt_debug("[sh] cannot dump the tree\n");
      return ;
    }
}

void			sh_help(t_bptarea(sh)			*bptarea,
				char				**cmds)
{
  printf("\n---[ help\n");
  printf("add:\t\t\t\t add [addr] [nblocks] [id]\n");
  printf("modify:\t\t\t\t mod [addr] [nblocks] [id]\n");
  printf("remove:\t\t\t\t rem [addr] [nblocks]\n");
  printf("dump:\t\t\t\t dump\n");
  printf("list:\t\t\t\t list\n");
  printf("info:\t\t\t\t info\n");
  printf("reinit:\t\t\t\t reinit\n");
  printf("quit:\t\t\t\t quit\n");
  printf("help:\t\t\t\t help\n");
}

void			sh_info(t_bptarea(sh)			*bptarea,
				char				**cmds)
{
  printf("---[ loaded:\t\t%u\n", ___loaded);
  printf("---[ allocated:\t\t%u\n", ___allocated);
}

void			sh_reinit(t_bptarea(sh)			*bptarea,
				  char				**cmds)
{
  SH_ADDR_T		_start;
  SH_SIZE_T		_size;

  if (sh_nargs(cmds) != 3)
    {
      fprintf(stderr, "[sh] syntax: reinit [start] [size]\n");
      return ;
    }

  _start = strtoul(cmds[1], NULL, 0);
  _size = strtoul(cmds[2], NULL, 0);

  sh_clean(bptarea);

  if (___loaded != 0)
    {
      fprintf(stderr, "[sh] there are blocks loaded\n");
      exit(EXIT_FAILURE);
    }

  if (___allocated != 0)
    {
      fprintf(stderr, "[sh] there are blocks allocated: %u\n", ___allocated);
      exit(EXIT_FAILURE);
    }

  if (sh_init(bptarea, _start, _size) != 0)
    {
      fprintf(stderr, "[sh] cannot reinitialize the tree\n");
      exit(EXIT_FAILURE);
    }
}

void			sh_quit(t_bptarea(sh)			*bptarea,
				char				**cmds)
{
  sh_clean(bptarea);

  if (___loaded != 0)
    {
      fprintf(stderr, "[sh] there are blocks loaded\n");
      exit(EXIT_FAILURE);
    }

  if (___allocated != 0)
    {
      fprintf(stderr, "[sh] there are blocks allocated: %u\n", ___allocated);
      exit(EXIT_FAILURE);
    }

  exit(EXIT_SUCCESS);
}

void			sh_cmd(t_bptarea(sh)			*bptarea,
			       char				**cmds)
{
  if (sh_nargs(cmds) == 0)
    {
      fprintf(stderr, "unknown command\n");
      sh_help(bptarea, cmds);
      return ;
    }

  if (strcmp(cmds[0],  SH_ADD) == 0)
    sh_add(bptarea, cmds);
  else if (strcmp(cmds[0], SH_MOD) == 0)
    sh_mod(bptarea, cmds);
  else if (strcmp(cmds[0], SH_REM) == 0)
    sh_rem(bptarea, cmds);
  else if (strcmp(cmds[0], SH_RANGE) == 0)
    sh_range(bptarea, cmds);
  else if (strcmp(cmds[0], SH_LIST) == 0)
    sh_list(bptarea, cmds);
  else if (strcmp(cmds[0], SH_DUMP) == 0)
    sh_dump(bptarea, cmds);
  else if (strcmp(cmds[0], SH_INFO) == 0)
    sh_info(bptarea, cmds);
  else if (strcmp(cmds[0], SH_REINIT) == 0)
    sh_reinit(bptarea, cmds);
  else if (strcmp(cmds[0], SH_QUIT) == 0)
    sh_quit(bptarea, cmds);
  else if (strcmp(cmds[0], SH_HELP) == 0)
    sh_help(bptarea, cmds);
  else
    {
      fprintf(stderr, "%s: unknown command\n", cmds[0]);
      sh_help(bptarea, cmds);
    }
}

int			main(int				argc,
			     char				**argv)
{
  t_bptarea(sh)		bptarea;
  SH_ADDR_T		_start;
  SH_SIZE_T		_size;

  if (argc != 3)
    {
      fprintf(stderr, "usage: %s [start] [size]\n", argv[0]);
      exit(EXIT_FAILURE);
    }

  _start = strtoul(argv[1], NULL, 0);
  _size = strtoul(argv[2], NULL, 0);

  printf("---[ sh mode\n\n");

  if (sh_init(&bptarea, _start, _size) != 0)
    {
      fprintf(stderr, "[sh] cannot initialize the tree\n");
      exit(EXIT_FAILURE);
    }

  while (1)
    {
      char		buffer[2048];
      char		**data;
      int		length;
      int		i;

      memset(buffer, 0x0, 2048);

      printf("[sh]# ");
      fflush(stdout);
      length = read(0, buffer, 2048);
      buffer[length - 1] = 0;

      data = sh_cut(buffer, " ");

      sh_cmd(&bptarea, data);

      for (i = 0; data[i]; i++)
	free(data[i]);
      free(data);
    }

  sh_quit(&bptarea, NULL);

  return (0);
}
