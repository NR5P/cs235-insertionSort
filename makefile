###############################################################
# Program:
#     Assignment 06, NODE
#     Brother JonesL, CS235
# Author:
#     Dan Worwood, Dallen Cluff, Nathan Rigg, Griffin Pope
# Summary:
#     implementation of linked lists which is a data structure
#     where elements can only be accessed in sequence.
#     Also implemented an insertion sort which used linked
#     list to sort number and letters from files via testBed
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h assignment06.o 
	g++ -g -o a.out assignment06.o  -g -std=c++11
	tar -cf assignment06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment06.o      : the driver program
#      <anything else?>
##############################################################
assignment06.o: node.h assignment06.cpp sortInsertion.h
	g++ -g -c assignment06.cpp -g -std=c++11
