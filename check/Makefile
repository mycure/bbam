##
## bpt.h
## 
## Makefile
## 
## path          /home/mycure/data/research/projects/bptarea-0.1/check
## 
## made by mycure
##         quintard julien   [quinta_j@epita.fr]
## 
## started on    Mon Oct 25 11:26:33 2004   mycure
## last update   Sat Apr 16 23:38:01 2005   mycure
##

CHECK_INPUT		=			link.in

#
# classical tests
#

CHECK_LIST		=						

#
# big tests
#

#						in/real4.in		\

#
# special tests
#

CHECK_GENERATOR		=			gen

#
# shell
#

CHECK_SH		=			sh

#
# compile
#

CC			=			gcc

CFLAGS_linux_XXX	=			-lm			\
						-Wall			\
						-fno-strict-prototype	\
						-Werror			\
						-Wmissing-declarations	\
						-Wparentheses		\
						-Wuninitialized		\
						-Wunused		\
						-O3

CFLAGS_NetBSD		=			$(CFLAGS_linux)

CFLAGS			=			$(CFLAGS_$(OSTYPE))

RM			=			rm -f
LN			=			ln -s
CAT			=			cat

all:		sh

gen:
	@$(RM) $(CHECK_GENERATOR)
	@$(CC) $(CFLAGS) $(CHECK_GENERATOR).c -o $(CHECK_GENERATOR)
	@./$(CHECK_GENERATOR)

sh:
	@$(RM) $(CHECK_SH)
	@$(CC) $(CFLAGS) $(CHECK_SH).c -o $(CHECK_SH)

distclean:
	@$(RM) $(CHECK_INPUT) $(CHECK_SH) $(CHECK_GENERATOR)
	@$(RM) $(CHECK_BENCH_LIST) $(CHECK_BENCH_BPT) *~
