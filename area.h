
/* --------------------------------------------------- areas specific ----- */

/*
 * these functions just calls the user-defined function load()
 */

void			bptarea_areas_load(t_bpt(ash)		*bpt,
					   t_bpt_imm(ash)	*node,
					   t_bpt_node(ash)	paddr)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  node->addr = paddr;
  bptarea->load(bptarea, node->addr, &node->buf);
}

void			bptarea_names_load(t_bpt(ish)		*bpt,
					   t_bpt_imm(ish)	*node,
					   t_bpt_node(ish)	paddr)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;
  
  node->addr = paddr;
  bptarea->load(bptarea, node->addr, &node->buf);
}

void			bptarea_ranges_load(t_bpt(rsh)		*bpt,
					    t_bpt_imm(rsh)	*node,
					    t_bpt_node(rsh)	paddr)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;
  
  node->addr = paddr;
  bptarea->load(bptarea, node->addr, &node->buf);
}

/*
 * these functions just calls the user-defined function unload()
 */

void			bptarea_areas_unload(t_bpt(ash)		*bpt,
					     t_bpt_imm(ash)	*node)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  bptarea->unload(bptarea, node->addr);
}

void			bptarea_names_unload(t_bpt(ish)		*bpt,
					     t_bpt_imm(ish)	*node)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  bptarea->unload(bptarea, node->addr);
}

void			bptarea_ranges_unload(t_bpt(rsh)	*bpt,
					      t_bpt_imm(rsh)	*node)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  bptarea->unload(bptarea, node->addr);
}

/*
 * these functions just calls the user-defined function to compare
 * two devices addresses (physical addresses)
 */

int			bptarea_areas_paddrcmp(t_bpt(ash)	*bpt,
					       t_bpt_addr(ash)	paddr1,
					       t_bpt_addr(ash)	paddr2)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  return (bptarea->paddrcmp(bptarea, paddr1, paddr2));
}

int			bptarea_names_paddrcmp(t_bpt(ish)	*bpt,
					       t_bpt_addr(ish)	paddr1,
					       t_bpt_addr(ish)	paddr2)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  return (bptarea->paddrcmp(bptarea, paddr1, paddr2));
}

int			bptarea_ranges_paddrcmp(t_bpt(rsh)		*bpt,
						t_bpt_addr(rsh)		paddr1,
						t_bpt_addr(rsh)		paddr2)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  return (bptarea->paddrcmp(bptarea, paddr1, paddr2));
}

/*
 * these functions just calls the user-defined function to compare
 * two keys (area / virtual addresses)
 */

int			bptarea_areas_vaddrcmp(t_bpt(ash)	*bpt,
					       t_bpt_key(ash)	vaddr1,
					       t_bpt_key(ash)	vaddr2)
{
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  return (bptarea->vaddrcmp(bptarea, vaddr1, vaddr2));
}

int			bptarea_names_vaddrcmp(t_bpt(ish)	*bpt,
					       t_bpt_value(ish)	vaddr1,
					       t_bpt_value(ish)	vaddr2)
{ 
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  return (bptarea->vaddrcmp(bptarea, vaddr1, vaddr2));
}

int			bptarea_ranges_vaddrcmp(t_bpt(rsh)		*bpt,
						t_bpt_value(rsh)	vaddr1,
						t_bpt_value(rsh)	vaddr2)
{ 
  t_bptarea(T)		*bptarea = (t_bptarea(T)*)bpt->data;

  return (bptarea->vaddrcmp(bptarea, vaddr1, vaddr2));
}

/*
 * this function just calls the user-defined function to compares two names
 */

int			bptarea_idcmp(t_bpt(ish)		*bpt,
				      t_bptarea_id(T)		id1,
				      t_bptarea_id(T)		id2)
{
  t_bptarea(T)		*bptarea = bpt->data;

  return (bptarea->idcmp(bptarea, id1, id2));
}

/*
 * this function just calls the user-defined funtion to check coalescing
 * property of two area
 */

int			bptarea_coalesce(t_bpt(ash)		*bpt,
					 t_bptarea_area(ash)	*area1,
					 t_bptarea_area(ash)	*area2)
{
  if ((area1->end == area2->addr) && (area1->id == area2->id))
    return (0);
  return (-1);
}

/*
 * this function just calls the user-defined function wich fills the given
 * range variable.
 */

void			bptarea_rangeset(t_bpt(ash)		*bpt,
					 t_bptarea_vaddr(ash)	addr1,
					 t_bptarea_vaddr(ash)	addr2,
					 t_bptarea_size(ash)	*range)
{
  t_bptarea(T)		*bptarea = bpt->data;

  bptarea->rangeset(bptarea, addr1, addr2, range);
}

/*
 * this function just calls the user-defined function to compare two range
 */

int			bptarea_rangecmp(t_bpt(rsh)		*bpt,
					 t_bptarea_size(rsh)	range1,
					 t_bptarea_size(rsh)	range2)
{
  t_bptarea(T)		*bptarea = bpt->data;

  return (bptarea->rangecmp(bptarea, range1, range2));
}

void			bptarea_unused(t_bptarea(ash)		*bptarea,
				       t_bptarea_uni(sh)	alloc,
				       t_bptarea_uni(sh)	size)
{
  bptarea->unused_fn(bptarea, alloc, size);
}

/*
 * this function always returns the highest key of the node.
 *
 * indeed, with every fit algorithms: first, best and worst, we
 * have to keep in the internal nodes the highest key. with it we
 * are going to quickly find the first potential node having
 * a large enough range.
 */


t_bptarea_size(T)	bptarea_node_range(t_bptarea(T)		*bptarea,
					   t_bpt_imm(ash)	*node)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_ndi(ash)	nkeys = BPT_NKEYS(ash, bpt, node);
  t_bptarea_size(T)	range;
  t_bpt_ndi(ash)	i;

  for (i = 0; (i < nkeys) &&
	 (bptarea_areas_vaddrcmp(bpt, BPT_GET_ENTRY(ash, node, i, area.addr),
				 bptarea->areas.ukey) == 1);
       i++)
    {
      if (i == 0)
	range = BPT_GET_ENTRY(ash, node, i, range);

      if (bptarea_rangecmp(&bptarea->ranges, range,
			   BPT_GET_ENTRY(ash, node, i, range)) < 0)
        range = BPT_GET_ENTRY(ash, node, i, range);
    }

  return (range);
}

/*
 * this function recursively updates the nodes in the tree
 */

void			bptarea_update_node(t_bptarea(T)	*bptarea,
					    t_bpt_imm(ash)	*node,
					    t_bpt_addr(ash)	paddr,
					    t_bptarea_size(T)	range)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_imm(ash)	parent;
  t_bpt_ndi(ash)	ndi;

  if (bpt_ndi(ash, bpt, node, paddr, &ndi) != 0)
    return ;

  if (bptarea_rangecmp(&bptarea->ranges, range,
		       BPT_GET_ENTRY(ash, node, ndi, range)) == 0)
    return ;

  BPT_SET_ENTRY(ash, node, ndi, range, range);

  if (BPT_GET_HEAD(ash, node, parent) == bptarea->areas.uaddr)
    return ;

  if ((range = bptarea_node_range(bptarea, node)) == -1)
    return ;

  BPT_LOAD(bpt, &parent, BPT_GET_HEAD(ash, node, parent));
  bptarea_update_node(bptarea, &parent, node->addr, range);
  BPT_UNLOAD(bpt, &parent);
}

/*
 * this function updates the ranges in the tree giving the fit algorithm
 */

void			bptarea_update(t_bptarea(T)		*bptarea,
				       t_bpt_imm(ash)		*node)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_imm(ash)	parent;
  t_bptarea_size(T)	range;

  if (BPT_GET_HEAD(ash, node, parent) == bptarea->areas.uaddr)
    return ;

  if ((range = bptarea_node_range(bptarea, node)) == -1)
    return ;

  BPT_LOAD(bpt, &parent, BPT_GET_HEAD(ash, node, parent));
  bptarea_update_node(bptarea, &parent, node->addr, range);
  BPT_UNLOAD(bpt, &parent);
}

/*
 * this function compute the range between two areas
 */

void			bptarea_set_range(t_bptarea(T)		*bptarea,
					  t_bpt_imm(ash)	*node1,
					  t_bpt_ndi(ash)	ndi)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_entry(ash)	current = { node1->addr, ndi };
  t_bptarea_size(T)	range;
  t_bpt_imm(ash)	node2;
  t_bpt_entry(ash)	next;

  if (bpt_next_entry(ash, bpt, current, &next, BPT_OPT_TREE) == 0)
    {
      BPT_LOAD(bpt, &node2, next.node);

      if (BPT_GET_HEAD(ash, node1, type) == BPT_TYPE_INTERNAL)
	{
	  bptarea_debug("[bptaread] collision detected\n");
	  BPT_UNLOAD(bpt, &node2);
	  return ;
	}
      else
	bptarea_rangeset(bpt,
			 BPT_GET_ENTRY(ash, &node2, next.ndi, area.addr),
			 BPT_GET_LFENTRY(ash, node1, current.ndi, area.end),
			 &range);

      BPT_SET_ENTRY(ash, node1, current.ndi, range, range);

      BPT_UNLOAD(bpt, &node2);
    }
  else
    BPT_SET_ENTRY(ash, node1, current.ndi, range, 0);
}

/*
 * this is the bpt insert callback function
 */

void			bptarea_cb_insert_ash(t_bptarea(T)	*bptarea,
					     t_bpt_cbctx(ash)	*cbctx)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_imm(ash)	update;
  t_bpt_imm(ash)	node1;
  t_bpt_entry(ash)	prev;
  t_bptarea_area(ash)	area;

  BPT_LOAD(bpt, &node1, cbctx->current.node);
  bptarea_set_range(bptarea, &node1, cbctx->current.ndi);

  area = BPT_GET_LFENTRY(ash, &node1, cbctx->current.ndi, area);
  //printf("area: %u->%u #%u\n", area.addr, area.end, area.id);
  //printf("check_id: %u\n", bptarea_set_id_ish(bptarea, &area));

  BPT_UNLOAD(bpt, &node1);

  if (bpt_prev_entry(ash, bpt, cbctx->current, &prev, BPT_OPT_TREE) == 0)
    {
      t_bpt_imm(ash)	node2;

      BPT_LOAD(bpt, &node2, prev.node);
      bptarea_set_range(bptarea, &node2, prev.ndi);
      bptarea_update(bptarea, &node2);
      BPT_UNLOAD(bpt, &node2);
    }

  BPT_LOAD(bpt, &update, cbctx->node);
  bptarea_update(bptarea, &update);
  BPT_UNLOAD(bpt, &update);
}

/*
 * this is the bpt split callback function
 */

void			bptarea_cb_split_ash(t_bptarea(T)	*bptarea,
					    t_bpt_cbctx(ash)	*cbctx)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_imm(ash)	update;
  t_bpt_imm(ash)	node1;
  t_bpt_entry(ash)	prev;

  BPT_LOAD(bpt, &node1, cbctx->current.node);
  bptarea_set_range(bptarea, &node1, cbctx->current.ndi);
  BPT_UNLOAD(bpt, &node1);

  if (bpt_prev_entry(ash, bpt, cbctx->current, &prev, BPT_OPT_TREE) == 0)
    {
      t_bpt_imm(ash)	node2;

      BPT_LOAD(bpt, &node2, prev.node);
      bptarea_set_range(bptarea, &node2, prev.ndi);
      bptarea_update(bptarea, &node2);
      BPT_UNLOAD(bpt, &node2);
    }

  BPT_LOAD(bpt, &update, cbctx->node1);
  bptarea_update(bptarea, &update);
  BPT_UNLOAD(bpt, &update);

  BPT_LOAD(bpt, &update, cbctx->node2);
  bptarea_update(bptarea, &update);
  BPT_UNLOAD(bpt, &update);
}

/*
 * this is the bpt modify callback function
 */

void			bptarea_cb_modify_ash(t_bptarea(T)	*bptarea,
					     t_bpt_cbctx(ash)	*cbctx)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_imm(ash)	update;
  t_bpt_imm(ash)	node;

  BPT_LOAD(bpt, &node, cbctx->current.node);
  bptarea_set_range(bptarea, &node, cbctx->current.ndi);
  BPT_UNLOAD(bpt, &node);

  BPT_LOAD(bpt, &update, cbctx->node);
  bptarea_update(bptarea, &update);
  BPT_UNLOAD(bpt, &update);
}

/*
 * this is the bpt delete callback function
 */

void			bptarea_cb_delete_ash(t_bptarea(T)	*bptarea,
					      t_bpt_cbctx(ash)	*cbctx)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_imm(ash)	update;
  t_bpt_imm(ash)	node;

  if (cbctx->previous.node != bptarea->areas.uaddr)
    {
      BPT_LOAD(bpt, &node, cbctx->previous.node);
      bptarea_set_range(bptarea, &node, cbctx->previous.ndi);
      BPT_UNLOAD(bpt, &node);
    }

  BPT_LOAD(bpt, &update, cbctx->node);
  bptarea_update(bptarea, &update);
  BPT_UNLOAD(bpt, &update);
}

/*
 * this is the bpt migrate callback function
 */

void			bptarea_cb_migrate_ash(t_bptarea(T)	*bptarea,
					       t_bpt_cbctx(ash) *cbctx)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_imm(ash)	update;
  t_bpt_imm(ash)	node;

  if (cbctx->previous.node != bptarea->areas.uaddr)
    {
      BPT_LOAD(bpt, &node, cbctx->previous.node);
      bptarea_set_range(bptarea, &node, cbctx->previous.ndi);
      BPT_UNLOAD(bpt, &node);
    }

  BPT_LOAD(bpt, &update, cbctx->node);
  bptarea_update(bptarea, &update);
  BPT_UNLOAD(bpt, &update);
}

/*
 * this is the bpt balance callback function
 */

void			bptarea_cb_balance_ash(t_bptarea(T)	*bptarea,
					       t_bpt_cbctx(ash)	*cbctx)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_imm(ash)	update;
  t_bpt_imm(ash)	node;

  if (cbctx->previous.node != bptarea->areas.uaddr)
    {
      BPT_LOAD(bpt, &node, cbctx->previous.node);
      bptarea_set_range(bptarea, &node, cbctx->previous.ndi);
      BPT_UNLOAD(bpt, &node);
    }

  BPT_LOAD(bpt, &update, cbctx->node1);
  bptarea_update(bptarea, &update);
  BPT_UNLOAD(bpt, &update);

  BPT_LOAD(bpt, &update, cbctx->node2);
  bptarea_update(bptarea, &update);
  BPT_UNLOAD(bpt, &update);
}

/*
 * this function is the bpt callback. it is used to update the tree
 */

void			bptarea_cb_ash(t_bpt(ash)		*bpt,
				       t_bpt_cbctx(ash)		*cbctx)
{
  t_bptarea(T)		*bptarea = bpt->data;

#ifdef BPTAREA_DEBUG
  printf("---[callback][0x%x] [prev] %d:%d [current] %d:%d [node] %d "
         "[node1] %d [node2] %d\n",
         cbctx->cb,
         cbctx->previous.node,
         cbctx->previous.ndi,
         cbctx->current.node,
         cbctx->current.ndi,
         cbctx->node,
         cbctx->node1,
         cbctx->node2);
#endif

  switch (cbctx->cb)
    {
    case BPT_CB_INSERT:
      bptarea_cb_insert_ash(bptarea, cbctx);
      break;
    case BPT_CB_SPLIT:
      bptarea_cb_split_ash(bptarea, cbctx);
      break;
    case BPT_CB_MODIFY:
      bptarea_cb_modify_ash(bptarea, cbctx);
      break;
    case BPT_CB_DELETE:
      bptarea_cb_delete_ash(bptarea, cbctx);
      break;
    case BPT_CB_MIGRATE:
      bptarea_cb_migrate_ash(bptarea, cbctx);
      break;
    case BPT_CB_BALANCE:
      bptarea_cb_balance_ash(bptarea, cbctx);
      break;
    }
}

/*
 * this function performs the first fit algorithm
 */

int			bptarea_first_fit_ash(t_bptarea(T)	*bptarea,
					      t_bptarea_area(T)	*area)
{

  /*
   * XXX
   */

  return (0);
}

/*
 * this function performs the best fit algorithm
 */

int			bptarea_best_fit_ash(t_bptarea(T)	*bptarea,
					     t_bptarea_area(T)	*area)
{

  /*
   * XXX
   */

  return (0);
}

/*
 * this function performs the worst fit algorithm
 */

int			bptarea_worst_fit_ash(t_bptarea(T)	*bptarea,
					      t_bptarea_area(T)	*area)
{

  /*
   * XXX
   */

  return (0);
}

/*
 * this function tries to find a large enough range
 */

int			bptarea_range_ash_old(t_bptarea(T)	*bptarea,
					      t_bptarea_area(T)	*area)
{
  switch(bptarea->fit)
    {
    case BPTAREA_FIT_FIRST:
      return (bptarea_first_fit_ash(bptarea, area));
    case BPTAREA_FIT_BEST:
      return (bptarea_best_fit_ash(bptarea, area));
    case BPTAREA_FIT_WORST:
      return (bptarea_worst_fit_ash(bptarea, area));
    default:
      bptarea_debug("[bptaread] no fit specified\n");
      return (-1);
    }

  return (-1);
}

/*
 * this function tries to find an enclosing area in the tree.
 * if this area is found, the function may also find the previous
 * and next entries.
 */

int			bptarea_get_area_ash(t_bptarea(T)	*bptarea,
					     t_bptarea_area(T)	*area,
					     t_bpt_entry(ash)	*prv,
					     t_bpt_entry(ash)	*cur,
					     t_bpt_entry(ash)	*nxt)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_ndi(ash)	first;
  t_bpt_entry(ash)	entry;
  t_bpt_imm(ash)	node1;
  t_bpt_imm(ash)	node2;
  t_bpt_imm(ash)	node3;
  t_bpt_addr(ash)	paddr;

  if (prv != NULL)
    BPTAREA_INIT_ENTRY(bpt, prv);
  if (cur != NULL)
    BPTAREA_INIT_ENTRY(bpt, cur);
  if (nxt != NULL)
    BPTAREA_INIT_ENTRY(bpt, nxt);

  BPT_LOAD(bpt, &node1, BPT_GET_ROOT(bpt));

  if (bpt_search_leaf(ash, bpt, &node1, &paddr, area->addr) != 0)
    {
      BPT_UNLOAD(bpt, &node1);
      return (-1);
    }

  BPT_UNLOAD(bpt, &node1);
  BPT_LOAD(bpt, &node1, paddr);

  if (bpt_first_entry(ash, bpt, &node1, &first) != 0)
    {
      if (BPT_GET_ROOT(bpt) == node1.addr)
	{
	  BPT_UNLOAD(bpt, &node1);
	  return (0);
	}

      BPT_UNLOAD(bpt, &node1);
      return (-1);
    }
  entry.node = node1.addr;
  entry.ndi = first;

  BPT_UNLOAD(bpt, &node1);

  do
    {
      BPT_LOAD(bpt, &node1, entry.node);

      if ((bptarea_areas_vaddrcmp(bpt,
      				  BPT_GET_LFENTRY(ash, &node1,
						  entry.ndi, area.addr),
      				  area->addr)) > 0)
      	{
      	  if ((bptarea_areas_vaddrcmp(bpt,
      				      area->end,
      				      BPT_GET_LFENTRY(ash, &node1,
						      entry.ndi,
						      area.addr))) > 0)
	    {
	      bptarea_debug("[bptaread] collision detected\n");
	      BPT_UNLOAD(bpt, &node1);
	      return (-1);
	    }

	  if (nxt != NULL)
	    {
	      nxt->node = entry.node;
	      nxt->ndi = entry.ndi;
	    }

	  if (bpt_prev_entry(ash, bpt, entry, &entry, BPT_OPT_TREE) == 0)
	    {
	      BPT_LOAD(bpt, &node2, entry.node);

	      if (((bptarea_areas_vaddrcmp(bpt,
					   BPT_GET_LFENTRY(ash, &node2,
							   entry.ndi,
							   area.addr),
					   area->addr)) <= 0) &&
		  ((bptarea_areas_vaddrcmp(bpt,
					   BPT_GET_LFENTRY(ash, &node2,
							   entry.ndi,
							   area.end),
					   area->end)) >= 0))
		{
		  if (cur != NULL)
		    {
		      cur->node = entry.node;
		      cur->ndi = entry.ndi;
		    }

		  if (bpt_prev_entry(ash, bpt, entry, &entry,
				     BPT_OPT_TREE) == 0)
		    {
		      if (prv != NULL)
			{
			  prv->node = entry.node;
			  prv->ndi = entry.ndi;
			}
		    }
		}
	      else
		{
		  BPT_LOAD(bpt, &node3, entry.node);

		  if ((bptarea_areas_vaddrcmp(bpt,
					      BPT_GET_LFENTRY(ash, &node3,
							      entry.ndi,
							      area.end),
					      area->addr)) > 0)
		    {
		      bptarea_debug("[bptaread] collision detected\n");
		      BPT_UNLOAD(bpt, &node3);
		      BPT_UNLOAD(bpt, &node2);
		      BPT_UNLOAD(bpt, &node1);
		      return (-1);
		    }

		  BPT_UNLOAD(bpt, &node3);

		  if (prv != NULL)
		    {
		      prv->node = entry.node;
		      prv->ndi = entry.ndi;
		    }
		}

	      BPT_UNLOAD(bpt, &node2);
	    }

	  BPT_UNLOAD(bpt, &node1);

	  return (0);
	}

      BPT_UNLOAD(bpt, &node1);
    }
  while (bpt_next_entry(ash, bpt, entry, &entry, BPT_OPT_TREE) == 0);

  BPT_LOAD(bpt, &node1, BPT_GET_ROOT(bpt));

  if (bpt_list(ash, bpt, &node1, &entry, BPT_OPT_TAIL) != 0)
    {
      BPT_UNLOAD(bpt, &node1);
      return (-1);
    }

  BPT_UNLOAD(bpt, &node1);
  BPT_LOAD(bpt, &node1, entry.node);

  if (((bptarea_areas_vaddrcmp(bpt,
  			       BPT_GET_LFENTRY(ash, &node1, entry.ndi,
					       area.addr),
			       area->addr)) <= 0) &&
      ((bptarea_areas_vaddrcmp(bpt,
  			       BPT_GET_LFENTRY(ash, &node1, entry.ndi,
					       area.end),
  			       area->end)) >= 0))
    {
      if (cur != NULL)
	{
	  cur->node = entry.node;
	  cur->ndi = entry.ndi;
	}

      if ((bpt_prev_entry(ash, bpt, entry, &entry, BPT_OPT_TREE) == 0) &&
	  prv != NULL)
	{
	  prv->node = entry.node;
	  prv->ndi = entry.ndi;
	}
    }
  else
    {
      BPT_LOAD(bpt, &node3, entry.node);

      if ((bptarea_areas_vaddrcmp(bpt,
				  BPT_GET_LFENTRY(ash, &node3, entry.ndi,
						  area.end), area->addr)) > 0)
	{
	  bptarea_debug("[bptaread] collision detected\n");
	  BPT_UNLOAD(bpt, &node3);
	  BPT_UNLOAD(bpt, &node1);
	  return (-1);
	}

      BPT_UNLOAD(bpt, &node3);

      if (prv != NULL)
	{
	  prv->node = entry.node;
	  prv->ndi = entry.ndi;
	}
    }

  BPT_UNLOAD(bpt, &node1);

  return (0);
}

/*
 * this function checks whether the area is correct
 */

int			bptarea_check(t_bptarea(T)		*bptarea,
				      t_bptarea_area(T)		*area)
{
  t_bpt(ash)		*bpt = &bptarea->areas;

  if ((bptarea_areas_vaddrcmp(bpt, area->addr, bptarea->start) < 0) ||
      bptarea_areas_vaddrcmp(bpt, area->end, bptarea->end) > 0)
    {
      bptarea_debug("[bptaread] area out of bounds\n");
      return (-1);
    }

  if ((bptarea_areas_vaddrcmp(bpt, area->end, area->addr) == 0) ||
      (bptarea_areas_vaddrcmp(bpt, area->end, bptarea->areas.ukey) == 0) ||
      (bptarea_areas_vaddrcmp(bpt, area->addr, bptarea->areas.uval) == 0))
    {
      bptarea_debug("[bptaread] zero sized area\n");
      return (-1);
    }
  return (0);
}

/*
 * this function removes an area
 * 
 * there are many cases, listed below:
 *
 * [*] means that the operation performed on the bpt needs no unused
 *     block.
 *
 * 1) the area exactly matches with an existing area, so just remove the
 *    area.
 *      . remove
 *
 * 2) the area matches the beginning of an existing area, so just resize
 *    the existing area.
 *      . modify
 *
 * 3) the area matches the end of an existing area, so just resize
 *    the existing area.
 *      . [*]modify
 *
 * 4) the area is located in the middle of an existing area, so we
 *    have to split it into two parts.
 *      . [*] modify + add
 */

int			bptarea_remove_ash(t_bptarea(T)		*bptarea,
					   t_bptarea_area(T)	*area)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_lfentry(ash)	current;
  t_bpt_lfentry(ash)	next;
  t_bpt_lfentry(ash)	new;
  t_bpt_entry(ash)	cur;

  if (bptarea_check(bptarea, area) != 0)
    return (-1);

  if (bptarea_get_area_ash(bptarea, area, NULL, &cur, NULL) != 0)
    {
      bptarea_debug("[bptaread] cannot find the area looked for\n");
      return (-1);
    }

  if (cur.node == bptarea->areas.uaddr)
    {
      bptarea_debug("[bptaread] nothing to remove\n");
      return (-1);
    }

  if (cur.node != bptarea->areas.uaddr)
    BPTAREA_LOAD(ash, bptarea, &cur, &current);

  BPTAREA_INIT_LEAF(ash, &new);
  /*
   * 1)
   */
  if ((bptarea_areas_vaddrcmp(bpt, area->addr,
			      current.area.addr) == 0) &&
      (bptarea_areas_vaddrcmp(bpt, area->end, current.area.end) == 0))
    {
      bptarea_unused(bptarea, BPT_REMOVE_ALLOC(bpt), BPT_REMOVE_SIZE(bpt));
      
      if (bpt_remove(ash, bpt, current.area.addr,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot remove the area\n");
	  return (-1);
	}

      return (0);
    }
  /*
   * 2)
   */
  if ((bptarea_areas_vaddrcmp(bpt, area->addr, current.area.addr) == 0) &&
      (bptarea_areas_vaddrcmp(bpt, area->end, current.area.end) < 0))
    {
      bptarea_unused(bptarea, BPT_MODIFY_ALLOC(bpt), BPT_MODIFY_SIZE(bpt));

      BPTAREA_IMPORT_AREA(ash, &new, area);

      new.area.addr = area->end;
      new.area.end = current.area.end;
      new.area.id = current.area.id;

      if (bpt_modify(ash, bpt, current.area.addr, &new,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot remove the area\n");
	  return (-1);
	}

      return (0);
    }
  /*
   * 3)
   */
  if ((bptarea_areas_vaddrcmp(bpt, area->addr, current.area.addr) > 0) &&
      (bptarea_areas_vaddrcmp(bpt, area->end, current.area.end) == 0))
    {

      /* warning, par necessaire */
      bptarea_unused(bptarea, BPT_MODIFY_ALLOC(bpt), BPT_MODIFY_SIZE(bpt));
      /******/
  
      BPTAREA_IMPORT_AREA(ash, &new, area);

      new.area.addr = current.area.addr;
      new.area.end = area->addr;
      new.area.id = current.area.id;

      if (bpt_modify(ash, bpt, current.area.addr, &new,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot modify the area\n");
	  return (-1);
	}

      return (0);
    }
  /*
   * 4)
   */
  bptarea_unused(bptarea, BPT_ADD_ALLOC(bpt), BPT_ADD_SIZE(bpt));

  BPTAREA_IMPORT_AREA(ash, &new, area);

  new.area.addr = area->end;
  new.area.end = current.area.end;
  new.area.id = current.area.id;

  current.area.addr = current.area.addr;
  current.area.end = area->addr;

  if (bpt_modify(ash, bpt, current.area.addr, &current,
		 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
    {
      bptarea_debug("[bptaread] cannot modify the area\n");
      return (-1);
    }

  if (bpt_add(ash, bpt, &new, (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
    {
      bptarea_debug("[bptaread] cannot add the area\n");
      return (-1);
    }

  return (0);
}

/*
 * this function modifies an area
 *
 * there are many cases, giving the coalescing feature:
 *
 * [*] means that the operation performed on the bpt needs no unused
 *     block.
 *
 * 1) the area matches an existing area.
 *
 *    a) the area coalesces with the previous and the next ones, so we just
 *       remove the current and the next and modify the previous to become
 *       the current, enclosing the tree.
 *         . remove + remove + [*]modify
 *
 *    b) the area coalesces with the previous area, so we just have to
 *       remove the current and modify the previous to become the current.
 *         . remove + [*]modify
 *
 *    c) the area coalesces with the next area, so we just have to
 *       remove the next and modify the current to resize it.
 *         . remove + [*]modify
 *
 *    d) the area does not coalesce, so we only have to modify the current area
 *         . [*]modify
 *
 * 2) the area matches the beginning of an existing area.
 *
 *    a) the area coalesces with the previous one, so we just modify the
 *       previous and the current.
 *         . [*]modify + modify
 *
 *    b) the area does not coalesce with the previous area, so we
 *       have to modify the current area and to add an new one.
 *         . modify + add
 *
 * 3) the area matches the end of an existing area.
 *
 *    a) the area coalesces with the next one, so we just modify the
 *       current and the next.
 *         . [*]modify + modify
 *
 *    b) the area does not coalesce with the next area, so we
 *       have to modify the current area and to add the new one.
 *         . [*]modify + add
 *
 * 4) the area is located in the middle of an existing area, so we
 *    have to split the current area into three areas: to modify
 *    the current to become the first one and to add two new areas.
 *      . [*]modify + add + add
 */

int			bptarea_modify_ash(t_bptarea(T)		*bptarea,
					   t_bptarea_area(T)	*area)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_lfentry(ash)	previous;
  t_bpt_lfentry(ash)	current;
  t_bpt_lfentry(ash)	next;
  t_bpt_lfentry(ash)	new1;
  t_bpt_lfentry(ash)	new2;
  t_bpt_entry(ash)	prv;
  t_bpt_entry(ash)	cur;
  t_bpt_entry(ash)	nxt;

  if (bptarea_check(bptarea, area) != 0)
    return (-1);

  if (bptarea_get_area_ash(bptarea, area, &prv, &cur, &nxt) != 0)
    {
      bptarea_debug("[bptaread] cannot find the area looked for\n");
      return (-1);
    }

  if (cur.node == bptarea->areas.uaddr)
    {
      bptarea_debug("[bptaread] the area to modify does not exist\n");
      return (-1);
    }

  if (BPTAREA_COALESCE(bptarea, &current.area, area) == 0)
    {
      bptarea_debug("[bptaread] nothing to modify\n");
      return (0);
    }

  if (prv.node != bptarea->areas.uaddr)
    BPTAREA_LOAD(ash, bptarea, &prv, &previous);

  if (cur.node != bptarea->areas.uaddr)
    BPTAREA_LOAD(ash, bptarea, &cur, &current);

  if (nxt.node != bptarea->areas.uaddr)
    BPTAREA_LOAD(ash, bptarea, &nxt, &next);

  BPTAREA_INIT_LEAF(ash, &new1);
  BPTAREA_INIT_LEAF(ash, &new2);
  /*
   * 1)
   */
  if ((bptarea_areas_vaddrcmp(bpt, area->addr, current.area.addr) == 0) &&
      (bptarea_areas_vaddrcmp(bpt, area->end, current.area.end) == 0))
    {
      /*
       * a)
       */
      if ((prv.node != bptarea->areas.uaddr) &&
	  (bptarea_areas_vaddrcmp(bpt, previous.area.end, area->addr) == 0) &&
	  (BPTAREA_COALESCE(bptarea, &previous.area, area) == 0) &&
	  (nxt.node != bptarea->areas.uaddr) &&
	  (bptarea_areas_vaddrcmp(bpt, area->end, next.area.addr) == 0) &&
	  (BPTAREA_COALESCE(bptarea, area, &next.area) == 0))
	{
	  bptarea_unused(bptarea, 2 * (BPT_REMOVE_ALLOC(bpt)),
			 2 * (BPT_REMOVE_SIZE(bpt)));

	  BPTAREA_IMPORT_AREA(ash, &new1, area);

	  new1.area.addr = previous.area.addr;
	  new1.area.end = next.area.end;

	  if (bpt_remove(ash, bpt, current.area.addr,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot remove the area\n");
	      return (-1);
	    }

	  if (bpt_remove(ash, bpt, next.area.addr,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot remove the area\n");
	      return (-1);
	    }

	  if (bpt_modify(ash, bpt, previous.area.addr, &new1,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot modify the area\n");
	      return (-1);
	    }

	  return (0);
	}
      /*
       * b)
       */
      if ((prv.node != bptarea->areas.uaddr) &&
	  (bptarea_areas_vaddrcmp(bpt, previous.area.end, area->addr) == 0) &&
	  (BPTAREA_COALESCE(bptarea, &previous.area, area) == 0))
	{
	  bptarea_unused(bptarea, BPT_REMOVE_ALLOC(bpt), BPT_REMOVE_SIZE(bpt));

	  BPTAREA_IMPORT_AREA(ash, &new1, area);

	  new1.area.addr = previous.area.addr;
	  new1.area.end = current.area.end;

	  if (bpt_remove(ash, bpt, current.area.addr,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot remove the area\n");
	      return (-1);
	    }

	  if (bpt_modify(ash, bpt, previous.area.addr, &new1,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot modify the area\n");
	      return (-1);
	    }

	  return (0);
	}
      /*
       * c)
       */
      if ((nxt.node != bptarea->areas.uaddr) &&
	  (bptarea_areas_vaddrcmp(bpt, area->end, next.area.addr) == 0) &&
	  (BPTAREA_COALESCE(bptarea, area, &next.area) == 0))
	{
	  bptarea_unused(bptarea, BPT_REMOVE_ALLOC(bpt), BPT_REMOVE_SIZE(bpt));

	  BPTAREA_IMPORT_AREA(ash, &new1, area);

	  new1.area.addr = current.area.addr;
	  new1.area.end = next.area.end;

	  if (bpt_remove(ash, bpt, next.area.addr,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot remove the area\n");
	      return (-1);
	    }

	  if (bpt_modify(ash, bpt, current.area.addr, &new1,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot modify the area\n");
	      return (-1);
	    }

	  return (0);
	}
      /*
       * d)
       */
      BPTAREA_IMPORT_AREA(ash, &new1, area);

      new1.area.addr = current.area.addr;
      new1.area.end = current.area.end;

      if (bpt_modify(ash, bpt, current.area.addr, &new1,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot modify the area\n");
	  return (-1);
	}

      return (0);
    }
  /*
   * 2)
   */
  if ((bptarea_areas_vaddrcmp(bpt, area->addr, current.area.addr) == 0) &&
      (bptarea_areas_vaddrcmp(bpt, area->end, current.area.end) < 0))
    {
      /*
       * a)
       */
      if ((prv.node != bptarea->areas.uaddr) &&
	  (bptarea_areas_vaddrcmp(bpt, previous.area.end, area->addr) == 0) &&
	  (BPTAREA_COALESCE(bptarea, &previous.area, area) == 0))
	{
	  bptarea_unused(bptarea, BPT_MODIFY_ALLOC(bpt), BPT_MODIFY_SIZE(bpt));

	  BPTAREA_IMPORT_AREA(ash, &new1, area);
	  BPTAREA_IMPORT_AREA(ash, &new2, &current.area);

	  new1.area.addr = previous.area.addr;
	  new1.area.end = area->end;

	  new2.area.addr = area->end;
	  new2.area.end = current.area.end;

	  if (bpt_modify(ash, bpt, previous.area.addr, &new1,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot modify the area\n");
	      return (-1);
	    }

	  if (bpt_modify(ash, bpt, current.area.addr, &new2,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot modify the area\n");
	      return (-1);
	    }

	  return (0);
	}
      /*
       * b)
       */
      /*
       * to check attention
       */
      bptarea_unused(bptarea, BPT_ADD_ALLOC(bpt) + BPT_MODIFY_ALLOC(bpt),
		     BPT_ADD_SIZE(bpt) + BPT_MODIFY_SIZE(bpt));

      BPTAREA_IMPORT_AREA(ash, &new1, area);

      new1.area.addr = area->addr;
      new1.area.end = area->end;

      current.area.addr = area->end;
      current.area.end = current.area.end;

      if (bpt_modify(ash, bpt, new1.area.addr, &new1,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot modify the area\n");
	  return (-1);
	}

      if (bpt_add(ash, bpt, &current, (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot modify the area\n");
	  return (-1);
	}

      return (0);
    }
  /*
   * 3)
   */
  if ((bptarea_areas_vaddrcmp(bpt, area->addr, current.area.addr) > 0) &&
      (bptarea_areas_vaddrcmp(bpt, area->end, current.area.end) == 0))
    {
      /*
       * a)
       */
      if ((nxt.node != bptarea->areas.uaddr) &&
	  (bptarea_areas_vaddrcmp(bpt, area->end, next.area.addr) == 0) &&
	  (BPTAREA_COALESCE(bptarea, area, &next.area) == 0))
	{
	  bptarea_unused(bptarea, BPT_MODIFY_ALLOC(bpt), BPT_MODIFY_SIZE(bpt));

	  BPTAREA_IMPORT_AREA(ash, &new1, area);

	  current.area.addr = current.area.addr;
	  current.area.end = area->addr;

	  new1.area.addr = area->addr;
	  new1.area.end = next.area.end;

	  if (bpt_modify(ash, bpt, current.area.addr, &current,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot modify the area\n");
	      return (-1);
	    }

	  if (bpt_modify(ash, bpt, next.area.addr, &new1,
			 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	    {
	      bptarea_debug("[bptaread] cannot modify the area\n");
	      return (-1);
	    }

	  return (0);
	}
      /*
       * b)
       */
      bptarea_unused(bptarea, BPT_ADD_ALLOC(bpt), BPT_ADD_SIZE(bpt));

      BPTAREA_IMPORT_AREA(ash, &new1, area);

      current.area.addr = current.area.addr;
      current.area.end = area->addr;

      new1.area.addr = area->addr;
      new1.area.end = area->end;

      if (bpt_modify(ash, bpt, current.area.addr, &current,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot modify the area\n");
	  return (-1);
	}

      if (bpt_add(ash, bpt, &new1, (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot modify the area\n");
	  return (-1);
	}

      return (0);
    }
  /*
   * 4)
   */

  bptarea_unused(bptarea, BPT_ADD_ALLOC(bpt), BPT_ADD_SIZE(bpt));

  BPTAREA_IMPORT_AREA(ash, &new1, area);
  BPTAREA_IMPORT_AREA(ash, &new2, &current.area);

  new1.area.addr = area->addr;
  new1.area.end = area->end;

  new2.area.addr = new1.area.end;
  new2.area.end = current.area.end;

  current.area.addr = current.area.addr;
  current.area.end = area->addr;

  if (bpt_modify(ash, bpt, current.area.addr, &current,
		 (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
    {
      bptarea_debug("[bptaread] cannot modify the area\n");
      return (-1);
    }

  if (bpt_add(ash, bpt, &new1, (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
    {
      bptarea_debug("[bptaread] cannot modify the area\n");
      return (-1);
    }

  /*
   * Tree size may be upgraded above, so second unused call here
   */

  bptarea_unused(bptarea, BPT_ADD_ALLOC(bpt), BPT_ADD_SIZE(bpt));

  if (bpt_add(ash, bpt, &new2, (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
    {
      bptarea_debug("[bptaread] cannot modify the area\n");
      return (-1);
    }

  printf("unused->index: %i\n", bptarea->uarea->unused->index);
  return (0);
}

/*
 * this function adds an area
 *
 * there are many cases, giving the coalescing feature:
 *
 * [*] means that the operation performed on the bpt needs no unused
 *     block.
 *
 * 1) the area coalesces with the previous and the next areas, so we
 *    remove the next area and modify the previous to become the area
 *    enclosing the three.
 *      . remove + [*]modify
 *
 * 2) the area coalesces with the previous area, so we just resize the previous
 *    area.
 *      . [*]modify
 *
 * 3) the area coalesces with the next area so we just resize the next area.
 *      . modify
 *
 * 4) the area does not coalesce with its neighbours, so we just add the
 *    new area.
 *      . add
 */

int			bptarea_add_ash(t_bptarea(T)		*bptarea,
					t_bptarea_id(T)		id,
					t_bptarea_area(T)	*area)
{
  t_bpt(ash)		*bpt = &bptarea->areas;
  t_bpt_lfentry(ash)	previous;
  t_bpt_lfentry(ash)	next;
  t_bpt_lfentry(ash)	new;
  t_bpt_entry(ash)	prv;
  t_bpt_entry(ash)	cur;
  t_bpt_entry(ash)	nxt;

  if (bptarea_check(bptarea, area) != 0)
    return (-1);

  if (bptarea_get_area_ash(bptarea, area, &prv, &cur, &nxt) != 0)
    {
      bptarea_debug("[bptaread] cannot find the area looked for\n");
      return (-1);
    }

  if (cur.node != bptarea->areas.uaddr)
    {
      bptarea_debug("[bptaread] collision detected\n");
      return (-1);
    }

  if (prv.node != bptarea->areas.uaddr)
    BPTAREA_LOAD(ash, bptarea, &prv, &previous);

  if (nxt.node != bptarea->areas.uaddr)
    BPTAREA_LOAD(ash, bptarea, &nxt, &next);

  BPTAREA_INIT_LEAF(ash, &new);
  /*
   * 1)
   */

  if ((prv.node != bptarea->areas.uaddr) &&
      (BPTAREA_COALESCE(bptarea, &previous.area, area) == 0) &&
      (nxt.node != bptarea->areas.uaddr) &&
      (BPTAREA_COALESCE(bptarea, area, &next.area) == 0))
    {
      bptarea_unused(bptarea, BPT_REMOVE_ALLOC(bpt),
		     BPT_REMOVE_SIZE(bpt));

      BPTAREA_IMPORT_AREA(ash, &new, area);
      
      new.area.addr = previous.area.addr;
      new.area.end = next.area.end;

      if (bpt_remove(ash, bpt, next.area.addr,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot remove the area\n");
	  return (-1);
	}

      if (bpt_modify(ash, bpt, previous.area.addr, &new,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot modify the area\n");
	  return (-1);
	}

      return (0);
    }
  /*
   * 2)
   */

  if ((prv.node != bpt->uaddr) &&
      (BPTAREA_COALESCE(bptarea, &previous.area, area) == 0))
    {
      BPTAREA_IMPORT_AREA(ash, &new, area);

      new.area.addr = previous.area.addr;
      new.area.end = area->end;

      if (bpt_modify(ash, bpt, previous.area.addr, &new,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot modify the area\n");
	  return (-1);
	}

      return (0);
    }
  /*
   * 3)
   */

  if ((nxt.node != bpt->uaddr) &&
      (BPTAREA_COALESCE(bptarea, area, &next.area) == 0))
    {
      bptarea_unused(bptarea, BPT_MODIFY_ALLOC(bpt) + 1,
		     BPT_MODIFY_SIZE(bpt));

      BPTAREA_IMPORT_AREA(ash, &new, area);

      new.area.addr = area->addr;
      new.area.end = next.area.end;

      if (bpt_modify(ash, bpt, next.area.addr, &new,
		     (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot modify the area\n");
	  return (-1);
	}

      return (0);
    }
  /*
   * 4)
   */

  bptarea_unused(bptarea, BPT_ADD_ALLOC(bpt),
		 BPT_ADD_SIZE(bpt));

  BPTAREA_IMPORT_AREA(ash, &new, area);

  new.area.addr = area->addr;
  new.area.end = area->end;

  if (bpt_add(ash, bpt, &new, (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
    {
      bptarea_debug("[bptaread] cannot add the area into the tree\n");
      return (-1);
    }
  return (0);
}

/*
 * this function initializes the bptarea core structure and build the
 * tree using bpt library
 */

void	bptarea_init_user_funcs(t_bptarea(T)			*bptarea,
				t_bptarea_fit			fit,
				t_bptarea_load_fn(T)		load,
				t_bptarea_unload_fn(T)		unload,
				t_bptarea_paddrcmp_fn(T)	paddrcmp,
				t_bptarea_vaddrcmp_fn(T)	vaddrcmp,
				t_bptarea_idcmp_fn(T)		idcmp,
				t_bptarea_coalesce_fn(T)	coalesce,
				t_bptarea_collide_fn(T)		collide,
				t_bptarea_rgset_fn(T)		rangeset,
				t_bptarea_rgcmp_fn(T)		rangecmp,
				t_bptarea_unused_fn(T)		unused_fn)
{
  bptarea->fit = fit;
  bptarea->load = load;
  bptarea->unload = unload;
  bptarea->paddrcmp = paddrcmp;
  bptarea->vaddrcmp = vaddrcmp;
  bptarea->idcmp = idcmp;
  bptarea->coalesce = coalesce;
  bptarea->collide = collide;
  bptarea->rangeset = rangeset;
  bptarea->rangecmp = rangecmp;
  bptarea->unused_fn = unused_fn;
}

int		bptarea_init_ash(t_bptarea(T)			*bptarea,
				 t_bptarea_blksz(T)		blksz,
				 t_bptarea_paddr(T)		uaddr,
				 t_bptarea_vaddr(T)		uval)
{
  bptarea_unused(bptarea, BPT_INIT_ALLOC(), BPT_INIT_SIZE());

  if (bpt_init(ash, &bptarea->areas, blksz, uaddr, uval, uval,
	       BPT_FLAG_CALLBACK, bptarea_areas_load, bptarea_areas_unload,
	       bptarea_areas_paddrcmp, bptarea_areas_vaddrcmp,
	       bptarea_areas_vaddrcmp, bptarea_cb_ash, bptarea,
	       (t_bpt_unused(ash)*)bptarea->uarea->unused) != 0)
    {
      bptarea_debug("[bptaread] cannot create the area tree \"areas\"\n");
      return (-1);
    }
 
  return (0);
}

int		bptarea_init_ish(t_bptarea(T)			*bptarea,
				 t_bptarea_blksz(T)		blksz,
				 t_bptarea_paddr(T)		uaddr,
				 t_bptarea_id(T)		uid,
				 t_bptarea_vaddr(T)		uval)
{
  bptarea_unused(bptarea, BPT_INIT_ALLOC(), BPT_INIT_SIZE());

  if (bpt_init(ish, &bptarea->id, blksz, uaddr, uid, uval,
	       BPT_FLAG_ZERO, bptarea_names_load, bptarea_names_unload,
	       bptarea_names_paddrcmp, bptarea_idcmp,
	       bptarea_names_vaddrcmp, NULL, bptarea,
	       (t_bpt_unused(ish)*)bptarea->uarea->unused) != 0)
    {
      bptarea_debug("[bptaread] cannot create the name tree\n");
      return (-1);
    }

  return (0);
}

int		bptarea_init_rsh(t_bptarea(T)			*bptarea,
				 t_bptarea_blksz(T)		blksz,
				 t_bptarea_paddr(T)		uaddr,
				 t_bptarea_size(T)		urange,
				 t_bptarea_vaddr(T)		uval)
{
  bptarea_unused(bptarea, BPT_INIT_ALLOC(), BPT_INIT_SIZE());

  if (bpt_init(rsh, &bptarea->ranges, blksz, uaddr, urange, uval,
	       BPT_FLAG_ZERO, bptarea_ranges_load, bptarea_ranges_unload,
	       bptarea_ranges_paddrcmp, bptarea_rangecmp,
	       bptarea_ranges_vaddrcmp, NULL, bptarea,
	       (t_bpt_unused(rsh)*)bptarea->uarea->unused) != 0)
    {
      bptarea_debug("[bptaread] cannot create the range tree\n");
      return (-1);
    }

  return (0);
}


int		bptarea_init_size(t_bptarea(T)			*bptarea,
				  t_bptarea_vaddr(T)		start,
				  t_bptarea_vaddr(T)		end)
{
  t_bpt(ash)	*bpt = &bptarea->areas;

  if (bptarea_areas_vaddrcmp(bpt, end, start) != 1)
    {
      bptarea_debug("[bptaread] unable to manage a negative size\n");
      return (-1);
    }
  
  bptarea->start = start;
  bptarea->end = end;

  return (0);
}

/*
 * this function clean the area tree
 */

int			bptarea_clean_ash(t_bptarea(T)		*bptarea)
{
  t_bpt(ash)		*bpt = &bptarea->areas;

  bptarea_unused(bptarea, BPT_CLEAN_ALLOC(bpt), BPT_CLEAN_SIZE(bpt));

  if (bpt_clean(ash, bpt, (t_bpt_unused(ash)*)bptarea->uarea->unused))
    {
      bptarea_debug("[bptaread] cannot clean the area tree\n");
      return (-1);
    }

  return (0);
}

/*
 * this function clean the name tree
 */

int			bptarea_clean_ish(t_bptarea(T)		*bptarea)
{
  t_bpt(ish)		*bpt = &bptarea->id;

  bptarea_unused(bptarea, BPT_CLEAN_ALLOC(bpt), BPT_CLEAN_SIZE(bpt));

  if (bpt_clean(ish, bpt, (t_bpt_unused(ish)*)bptarea->uarea->unused))
    {
      bptarea_debug("[bptaread] cannot clean the name tree\n");
      return (-1);
    }

  return (0);
}

/*
 * this function clean the range tree
 */

int			bptarea_clean_rsh(t_bptarea(T)		*bptarea)
{
  t_bpt(rsh)		*bpt = &bptarea->ranges;

  bptarea_unused(bptarea, BPT_CLEAN_ALLOC(bpt), BPT_CLEAN_SIZE(bpt));

  if (bpt_clean(rsh, bpt, (t_bpt_unused(rsh)*)bptarea->uarea->unused))
    {
      bptarea_debug("[bptaread] cannot clean the name tree\n");
      return (-1);
    }

  return (0);
}


int			bptarea_check_opt(t_bptarea(T)		*bptarea,
					  t_bpt_flags		flag,
					  t_bptarea_fit		fit)
{
  return (0);
}

int			bptarea_space_ash(t_bptarea(T)		*bptarea,
					  t_bpt_flags		flag,
					  t_bptarea_fit		fit,
					  t_bptarea_id(T)	group,
					  t_bptarea_size(T)	size,
					  t_bptarea_area(T)	*area)
{
  if (bptarea_check_opt(bptarea, flag, fit) != 0)
    return (-1);


/* BPTAREA_FIT_FIRST */
/* BPTAREA_FIT_BEST */
/* BPTAREA_FIT_WORST */


/* BPTAREA_FLAG_ZERO */
/* BPTAREA_FLAG_COALESCE */



  return (0);
}

t_bptarea_vaddr(ash)	bptarea_check_id_ish(t_bptarea(T)	*bptarea,
					     t_bptarea_area(T)	*area)
{
  t_bpt(ish)		*bpt_id = &bptarea->id;
  t_bpt_imm(ish)	root;
  t_bpt_imm(ish)	leaf;
  t_bpt_node(ish)	paddr;
  t_bpt_ndi(ish)	ndi;

  BPT_LOAD(bpt_id, &root, BPT_GET_ROOT(bpt_id));

  if (bpt_search_leaf(ish, bpt_id, &root, &paddr, area->id) != 0)
    {
      BPT_UNLOAD(bpt_id, &root);
      bptarea_debug("no leaf present in the tree\n");
      return (-1);
    }

  BPT_UNLOAD(bpt_id, &root);
  BPT_LOAD(bpt_id, &leaf, paddr);

  if (bpt_search_entry(ish, bpt_id, &leaf, area->id, &ndi, BPT_OPT_PERFECT) != 0)
    {
      BPT_UNLOAD(bpt_id, &leaf);
      return (SH_UVADDR);
    }

  return (BPT_GET_ENTRY(ish, &leaf, ndi, addr));
}


int			bptarea_set_id_ish(t_bptarea(T)		*bptarea,
					   t_bptarea_area(T)	*area)
{
  t_bpt(ish)		*bpt_id = &bptarea->id;
  t_bpt_imm(ish)	root;
  t_bpt_imm(ish)	leaf;
  t_bpt_node(ish)	paddr;
  t_bpt_lfentry(ish)	new;
  t_bpt_entry(ish)	entry;
  t_bpt_ndi(ish)	ndi;


  BPT_LOAD(bpt_id, &root, BPT_GET_ROOT(bpt_id));

  if (bpt_search_leaf(ish, bpt_id, &root, &paddr, area->id) != 0)
    {
      BPT_UNLOAD(bpt_id, &root);
      bptarea_debug("no leaf present in the tree\n");
      return (-1);
    }

  BPT_UNLOAD(bpt_id, &root);
  BPT_LOAD(bpt_id, &leaf, paddr);

  if (bpt_search_entry(ish, bpt_id, &leaf, area->id, &ndi, BPT_OPT_PERFECT) != 0)
    {
      BPT_UNLOAD(bpt_id, &leaf);

      BPTAREA_INIT_LEAF(ish, &new);
      new.id = area->id;
      new.addr = area->addr;

      bptarea_unused(bptarea, BPT_ADD_ALLOC(bpt_id), BPT_ADD_SIZE(bpt_id));

      if (bpt_add(ish, bpt_id, &new,
		  (t_bpt_unused(ish)*)bptarea->uarea->unused) != 0)
	{
	  bptarea_debug("[bptaread] cannot add new id into the tree\n");
	  return (-1);
	}
      return (0);
    }

  /* same group vaddr less than indexed in id tree, so updating */
  if ((bptarea_names_vaddrcmp(bpt_id, area->addr,
			      BPT_GET_ENTRY(ish, &leaf, ndi, addr))) == -1)
    {
      BPT_SET_ENTRY(ish, &leaf, ndi, addr, area->addr);
      /* printf("%i found, vaddr: %u [updated]\n", BPT_GET_ENTRY(ish, &leaf, ndi, id),
	 BPT_GET_ENTRY(ish, &leaf, ndi, addr)); */
    }
  
  BPT_UNLOAD(bpt_id, &leaf);

  return (0);


/*   if (bpt_search(ish, bpt_id, area->id, &entry) != 0) */
/*     { */
/*       printf("%i not found\n", area->id); */

/*       BPTAREA_INIT_LEAF(ish, &new); */
/*       new.id = area->id; */
/*       new.addr = vaddr; */

/*       bptarea_unused(bptarea, BPT_ADD_ALLOC(bpt_id), BPT_ADD_SIZE(bpt_id)); */

/*       if (bpt_add(ish, bpt_id, &new, */
/* 		  (t_bpt_unused(ish)*)bptarea->uarea->unused) != 0) */
/* 	{ */
/* 	  bptarea_debug("[bptaread] cannot add new id into the tree\n"); */
/* 	  return (-1); */
/* 	} */
/*       printf("%i added\n", area->id); */
/*       return (0); */
/*     } */


/*   BPT_LOAD(bpt_id, &node, entry.node); */

/*   printf("%i found, vaddr: %u\n", BPT_GET_ENTRY(ish, &node, entry.ndi, id), */
/* 	 BPT_GET_ENTRY(ish, &node, entry.ndi, addr)); */
/*   return (0); */
}
