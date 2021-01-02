CC	=	gcc
CFLAGS	=	-W -Wall -O2
LDFLAGS	=	-lm

project2 	:	project2.c BST.h BST.c
	$(CC)   $(CFLAGS)       -o      $@      $^      $(LDFLAGS)
	
clean   :
	@rm     -rf     *.o     mst
	@rm 		-rf 		*.exe 	mst