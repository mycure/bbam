/*
 * bptarea
 * 
 * bptarea.h
 * 
 * path          /home/mycure/lse/bptarea
 * 
 * made by mycure
 *         quintard julien   [quinta_j@epita.fr]
 * 
 * started on    Wed Dec 15 13:01:18 2004   mycure
 * last update   Wed Dec 21 21:08:39 2005   lessyv
 */

#ifndef BPTAREA_H
#define BPTAREA_H

/*
 * general defines
 */

#define BPTAREA_VERSION		"0.2"

/*
 * default types
 */

#define BPTAREA_BLKSZ_T		BPT_NODESZ_T

/*
 * bptarea fits
 */

#define BPTAREA_FIT_FIRST	0x1
#define BPTAREA_FIT_BEST	0x2
#define BPTAREA_FIT_WORST	0x3

/*
 * bptarea coalesce option
 */

#define BPTAREA_FLAG_ZERO	0x0
#define BPTAREA_FLAG_COALESCE	0x1

/*
 * default types
 */

#define BPTAREA_TYPE_FIT	unsigned char

/*
 * general types
 */

typedef BPTAREA_TYPE_FIT	t_bptarea_fit;

/*
 * macros which indicates the number of unused blocks to provide to the
 * bpt library to perform the desired operations
 */

#define		BPTAREA_INIT_ALLOC()                                          \
  (BPT_INIT_ALLOC() + BPT_INIT_ALLOC())

#define		BPTAREA_ADD_ALLOC(_bptarea_)                                  \
  (BPT_MODIFY_ALLOC(&(_bptarea_)->areas) +                                    \
   BPT_ADD_ALLOC(&(_bptarea_)->areas))

#define		BPTAREA_MODIFY_ALLOC(_bptarea_)                               \
  (BPT_ADD_ALLOC(&(_bptarea_)->areas) +                                       \
   BPT_REMOVE_ALLOC(&(_bptarea_)->areas))

#define		BPTAREA_REMOVE_ALLOC(_bptarea_)                               \
  (BPT_MODIFY_ALLOC(&(_bptarea_)->areas) +                                    \
   BPT_REMOVE_ALLOC(&(_bptarea_)->areas))

#define         BPTAREA_CLEAN_ALLOC(_bptarea_)                                \
  (BPT_CLEAN_ALLOC(&(_bptarea_)->areas) +                                     \
   BPT_CLEAN_ALLOC(&(_bptarea_)->areas))

/*
 * macros that specify the size of the array the bpt library need as
 * parameter
 */

#define		BPTAREA_INIT_SIZE()                                           \
  (BPT_INIT_SIZE() + BPT_INIT_SIZE())

#define		BPTAREA_ADD_SIZE(_bptarea_)                                   \
  (BPT_MODIFY_SIZE(&(_bptarea_)->areas) +                                     \
   BPT_ADD_SIZE(&(_bptarea_)->areas))

#define		BPTAREA_MODIFY_SIZE(_bptarea_)                                \
  (BPT_ADD_SIZE(&(_bptarea_)->areas) +                                        \
   BPT_ADD_SIZE(&(_bptarea_)->areas))

#define		BPTAREA_REMOVE_SIZE(_bptarea_)                                \
  (BPT_MODIFY_SIZE(&(_bptarea_)->areas) +                                     \
   BPT_REMOVE_SIZE(&(_bptarea_)->areas))

#define		BPTAREA_CLEAN_SIZE(_bptarea_)                                 \
  (BPT_CLEAN_SIZE(&(_bptarea_)->areas) +                                      \
   BPT_CLEAN_SIZE(&(_bptarea_)->areas))

/*
 * debug macro
 */

#ifdef BPTAREA_DEBUG
# define	bptarea_debug(fmt...)                                         \
  {                                                                           \
    fprintf(stderr, "[%s:%u] ", __FILE__, __LINE__);                          \
    fprintf(stderr, fmt);                                                     \
  }
#else
# define	bptarea_debug(fmt...)
#endif

/*
 * user friendly macros
 */

#define		t_bptarea(T)                                                  \
  t_bptarea_sh

#define		t_bptarea_blksz(T)                                            \
  t_bptarea_blksz_sh

#define		t_bptarea_ndi(T)                                              \
  t_bptarea_ndi_sh

#define		t_bptarea_uni(T)                                              \
  t_bptarea_uni_sh

#define		t_bptarea_nodes(T)                                            \
  t_bptarea_nodes_sh

#define		t_bptarea_areas(T)                                            \
  t_bptarea_areas_sh

#define		t_bptarea_height(T)                                           \
  t_bptarea_height_sh

/* #define		t_bptarea_addr(T)                                            \ */
/*   t_bptarea_addr_sh */

#define		t_bptarea_paddr(T)                                            \
  t_bptarea_paddr_sh

/* #define		t_bptarea_key(T)                                            \ */
/*   t_bptarea_key_sh */

#define		t_bptarea_vaddr(T)                                            \
  t_bptarea_vaddr_sh

#define		t_bptarea_size(T)                                             \
  t_bptarea_size_sh

#define		t_bptarea_id(T)                                               \
  t_bptarea_id_sh

#define		t_bptarea_area(T)                                             \
  t_bptarea_area_sh

#define		t_bptarea_unused(T)                                           \
  t_bptarea_unused_sh

#define		t_bptarea_uarea(T)                                            \
  t_bptarea_uarea_sh

#define		t_bptarea_loc(T)                                              \
  t_bptarea_loc_sh

#define		t_bptarea_load_fn(T)                                          \
  t_bptarea_load_fn_sh

#define		t_bptarea_unload_fn(T)                                        \
  t_bptarea_unload_fn_sh

#define		t_bptarea_paddrcmp_fn(T)                                      \
  t_bptarea_paddrcmp_fn_sh

#define		t_bptarea_vaddrcmp_fn(T)                                      \
  t_bptarea_vaddrcmp_fn_sh

#define		t_bptarea_idcmp_fn(T)                                         \
  t_bptarea_idcmp_fn_sh

#define		t_bptarea_coalesce_fn(T)                                      \
  t_bptarea_coalesce_fn_sh

#define		t_bptarea_collide_fn(T)                                       \
  t_bptarea_collide_fn_sh

#define		t_bptarea_rgset_fn(T)                                         \
  t_bptarea_rgset_fn_sh

#define		t_bptarea_rgcmp_fn(T)                                         \
  t_bptarea_rgcmp_fn_sh

#define		t_bptarea_unused_fn(T)                                        \
  t_bptarea_unused_fn_sh

/*
 * bptarea traps
 */

/*
 * XXX
 */

/*
 * template independent macros
 */

#define BPTAREA_INIT_ENTRY(_bptarea_, _entry_)                                \
  {                                                                           \
    (_entry_)->node = ((_bptarea_)->uaddr);                                   \
    (_entry_)->ndi = 0;                                                       \
  }

#define BPTAREA_COALESCE(_bptarea_, _area1_, _area2_)                         \
  (_bptarea_)->coalesce(_bptarea_, _area1_, _area2_)

#define BPTAREA_LOAD(T, _bptarea_, _entry_, _area_)                           \
  {                                                                           \
    t_bpt_imm(T)	_node_;                                               \
                                                                              \
    BPT_LOAD(&(_bptarea_)->areas, &_node_, (_entry_)->node);                  \
    BPT_EXPORT_ENTRY(T, &_node_, (_entry_)->ndi, (_area_));                   \
    BPT_UNLOAD(&(_bptarea_)->areas, &_node_);                                 \
  }

#define BPTAREA_INIT_LEAF(T, _leaf_)                                          \
  memset((_leaf_), 0x0, sizeof(t_bpt_lfentry(T)))

#define BPTAREA_IMPORT_AREA(T, _leaf_, _area_)                                \
  memcpy(&(_leaf_)->area, (_area_), sizeof(t_bptarea_area(T)))

/*
 * the core macro which build types
 */

#define		bptarea_make_types(T, _t_bptarea_blksz_,                      \
                                   _t_bptarea_ndi_, _t_bptarea_uni_,          \
                                   _t_bptarea_nodes_, _t_bptarea_height_,     \
                                   _t_bptarea_paddr_, _t_bptarea_vaddr_,      \
                                   _t_bptarea_size_, _t_bptarea_id_,          \
                                   _t_bptarea_area_, _vaddr_, _vend_)         \
                                                                              \
typedef struct			s_bptarea_inentry_a##T                        \
{                                                                             \
  struct                                                                      \
    {                                                                         \
      _t_bptarea_vaddr_		_vaddr_;                                      \
      _t_bptarea_paddr_		_vend_;                                       \
    }				area;                                         \
  _t_bptarea_size_		range;                                        \
}				t_bptarea_inentry_a##T;                       \
                                                                              \
typedef struct			s_bptarea_lfentry_a##T                        \
{                                                                             \
  _t_bptarea_area_		area;                                         \
  _t_bptarea_size_		range;                                        \
  _t_bptarea_vaddr_		prv;                                          \
  _t_bptarea_vaddr_		nxt;                                          \
  _t_bptarea_vaddr_		id_prv;                                       \
  _t_bptarea_vaddr_		id_nxt;                                       \
}				t_bptarea_lfentry_a##T;                       \
                                                                              \
  bpt_make_types(a##T, _t_bptarea_blksz_, _t_bptarea_ndi_,                    \
                 _t_bptarea_uni_, _t_bptarea_nodes_, _t_bptarea_height_,      \
                 _t_bptarea_paddr_, _t_bptarea_vaddr_, _t_bptarea_vaddr_,     \
                 t_bptarea_inentry_a##T, t_bptarea_lfentry_a##T)              \
                                                                              \
typedef struct			s_bptarea_inentry_i##T                        \
{                                                                             \
  _t_bptarea_id_		id;                                           \
  _t_bptarea_paddr_		addr;                                         \
}				t_bptarea_inentry_i##T;                       \
                                                                              \
typedef struct			s_bptarea_lfentry_i##T                        \
{                                                                             \
  _t_bptarea_id_		id;                                           \
  _t_bptarea_vaddr_		addr;                                         \
}				t_bptarea_lfentry_i##T;                       \
                                                                              \
  bpt_make_types(i##T, _t_bptarea_blksz_, _t_bptarea_ndi_,                    \
                 _t_bptarea_uni_, _t_bptarea_nodes_, _t_bptarea_height_,      \
                 _t_bptarea_paddr_, _t_bptarea_id_, _t_bptarea_vaddr_,        \
                 t_bptarea_inentry_i##T, t_bptarea_lfentry_i##T);             \
                                                                              \
typedef struct                  s_bptarea_inentry_r##T                        \
{                                                                             \
  _t_bptarea_size_              range;                                        \
  _t_bptarea_paddr_             addr;                                         \
}                               t_bptarea_inentry_r##T;                       \
                                                                              \
typedef struct                  s_bptarea_lfentry_r##T                        \
{                                                                             \
  _t_bptarea_size_              range;                                        \
  _t_bptarea_vaddr_             addr;                                         \
}                               t_bptarea_lfentry_r##T;                       \
                                                                              \
  bpt_make_types(r##T, _t_bptarea_blksz_, _t_bptarea_ndi_,                    \
                 _t_bptarea_uni_, _t_bptarea_nodes_, _t_bptarea_height_,      \
                 _t_bptarea_paddr_, _t_bptarea_size_, _t_bptarea_vaddr_,      \
                 t_bptarea_inentry_r##T, t_bptarea_lfentry_r##T);             \
                                                                              \
/*                                                                            \
 * now create specific bptarea types, functions and structures                \
 */                                                                           \
                                                                              \
typedef _t_bptarea_blksz_	t_bptarea_blksz_##T;                          \
typedef _t_bptarea_ndi_		t_bptarea_ndi_##T;                            \
typedef _t_bptarea_uni_		t_bptarea_uni_##T;                            \
typedef _t_bptarea_nodes_	t_bptarea_nodes_##T;                          \
typedef t_bptarea_nodes_##T	t_bptarea_areas_##T;                          \
typedef _t_bptarea_height_	t_bptarea_height_##T;                         \
typedef _t_bptarea_paddr_	t_bptarea_paddr_##T;                          \
typedef _t_bptarea_vaddr_	t_bptarea_vaddr_##T;                          \
typedef _t_bptarea_size_	t_bptarea_size_##T;                           \
typedef _t_bptarea_id_		t_bptarea_id_##T;                             \
typedef _t_bptarea_area_	t_bptarea_area_##T;                           \
                                                                              \
typedef struct			s_bptarea_unused_##T                          \
{                                                                             \
  t_bptarea_paddr(T)		*array;                                       \
  t_bptarea_uni(T)		index;                                        \
}				t_bptarea_unused_##T;                         \
                                                                              \
typedef struct			s_bptarea_uarea_##T                           \
{                                                                             \
  t_bptarea_uni(T)              size;                                         \
  t_bptarea_unused_##T	        *unused;                                      \
}                               t_bptarea_uarea_##T;                          \
                                                                              \
typedef struct			s_bptarea_loc_##T                             \
{                                                                             \
  t_bpt_entry(a##T)		prv;                                          \
  t_bpt_entry(a##T)		cur;                                          \
  t_bpt_entry(a##T)		nxt;                                          \
}				t_bptarea_loc_##T;                            \
                                                                              \
typedef struct s_bptarea_##T	t_bptarea_##T;                                \
                                                                              \
typedef void	(*t_bptarea_load_fn_##T)(t_bptarea(T)		*bptarea,     \
                                         t_bptarea_paddr(T)	addr,         \
                                         void**			buf);         \
                                                                              \
typedef void	(*t_bptarea_unload_fn_##T)(t_bptarea(T)		*bptarea,     \
                                           t_bptarea_paddr(T)	addr);        \
                                                                              \
typedef int	(*t_bptarea_paddrcmp_fn_##T)(t_bptarea(T)	*bptarea,     \
					     t_bptarea_paddr(T)	paddr1,       \
					     t_bptarea_paddr(T)	paddr2);      \
                                                                              \
typedef int	(*t_bptarea_vaddrcmp_fn_##T)(t_bptarea(T)	*bptarea,     \
					     t_bptarea_vaddr(T)	vaddr1,       \
					     t_bptarea_vaddr(T)	vaddr2);      \
                                                                              \
typedef int	(*t_bptarea_idcmp_fn_##T)(t_bptarea(T)		*bptarea,     \
                                          t_bptarea_id(T)	id1,          \
                                          t_bptarea_id(T)	id2);         \
                                                                              \
typedef int	(*t_bptarea_coalesce_fn_##T)(t_bptarea(T)	*bptarea,     \
                                             t_bptarea_area(T)	*area1,       \
                                             t_bptarea_area(T)	*area2);      \
                                                                              \
typedef int	(*t_bptarea_collide_fn_##T)(t_bptarea(T)	*bptarea,     \
                                            t_bptarea_area(T)	*area1,       \
                                            t_bptarea_area(T)	*area2);      \
                                                                              \
typedef void	(*t_bptarea_rgset_fn_##T)(t_bptarea(T)		*bptarea,     \
					  t_bptarea_vaddr(T)	addr1,        \
					  t_bptarea_vaddr(T)	addr2,        \
					  t_bptarea_size(T)	*range);      \
                                                                              \
typedef int	(*t_bptarea_rgcmp_fn_##T)(t_bptarea(T)		*bptarea,     \
					  t_bptarea_size(T)	range1,       \
					  t_bptarea_size(T)	range2);      \
                                                                              \
typedef void	(*t_bptarea_unused_fn_##T)(t_bptarea(T)		*bptarea,     \
                                           t_bptarea_uni(sh)    alloc,        \
                                           t_bptarea_uni(sh)    size);        \
                                                                              \
struct				s_bptarea_##T                                 \
{                                                                             \
  t_bpt(a##T)			areas;                                        \
  t_bpt(i##T)			id;                                           \
  t_bpt(r##T)                   ranges;                                       \
                                                                              \
  t_bptarea_fit			fit;                                          \
  t_bptarea_vaddr(T)		start;                                        \
  t_bptarea_vaddr(T)		end;                                          \
                                                                              \
  t_bptarea_load_fn(T)		load;                                         \
  t_bptarea_unload_fn(T)	unload;                                       \
  t_bptarea_paddrcmp_fn(T)	paddrcmp;                                     \
  t_bptarea_vaddrcmp_fn(T)	vaddrcmp;                                     \
  t_bptarea_idcmp_fn(T)		idcmp;                                        \
  t_bptarea_coalesce_fn(T)	coalesce;                                     \
  t_bptarea_collide_fn(T)	collide;                                      \
  t_bptarea_rgset_fn(T)		rangeset;                                     \
  t_bptarea_rgcmp_fn(T)		rangecmp;                                     \
  t_bptarea_unused_fn(T)        unused_fn;                                    \
  t_bptarea_uarea(sh)           *uarea;                                       \
  void                          *data;                                        \
};

/*
 * this macro will build the bptarea functions
 */

/* XXX #define ... */

/*
 * bptarea prototypes
 */

#define		bptarea_make_protos(T)                                        \
  bpt_make_protos(a##T)                                                       \
  bpt_make_protos(i##T)                                                       \
  bpt_make_protos(r##T)

/*
 * bptarea functions
 */

#define		bptarea_make_functions(T, _vaddr_, _vend_)                    \
  bpt_make_functions(a##T, area._vaddr_, area._vend_)                         \
  bpt_make_functions(i##T, id, addr)                                          \
  bpt_make_functions(r##T, range, addr)

/*
 * the core macro which build a bptarea context
 */

#define		bptarea_make(T, _t_bptarea_blksz_, _t_bptarea_ndi_,           \
                             _t_bptarea_uni_, _t_bptarea_nodes_,              \
                             _t_bptarea_height_, _t_bptarea_paddr_,           \
                             _t_bptarea_vaddr_, _t_bptarea_size_,             \
			     _t_bptarea_id_, _t_bptarea_area_,                \
                             _vaddr_, _vend_)                                 \
                                                                              \
  bptarea_make_types(T, _t_bptarea_blksz_, _t_bptarea_ndi_,                   \
                     _t_bptarea_uni_, _t_bptarea_nodes_,                      \
                     _t_bptarea_height_, _t_bptarea_paddr_,                   \
                     _t_bptarea_vaddr_, _t_bptarea_size_,                     \
                     _t_bptarea_id_, _t_bptarea_area_,                        \
                     _vaddr_, _vend_)                                         \
  bptarea_make_protos(T)                                                      \
  bptarea_make_functions(T, _vaddr_, _vend_)

#endif
