SRCS =  Project3Tester.C ProjectMatrix.C ProjectShort.C
EXEC = Project3Tester

OBJS = $(SRCS:.C=.o)


$(EXEC): $(OBJS)
	g++ -o $(EXEC) $(OBJS)


%.o : %.C
	g++ -g -Wall -c $<

clean:
	rm -f *.o *~ $(EXEC)



# DO NOT DELETE THIS LINE -- make depend needs it 