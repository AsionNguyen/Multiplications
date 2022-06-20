TARGET = main.out
SRC = main.c

CC=gcc
CFLAGS=-Wall

#GMP_INCLUDE=-I/Users/quyennguyen/Programs/libs/gmp/6.2.1/include
#GMP_LIBS=-L/Users/quyennguyen/Programs/libs/gmp/6.2.1/lib -lgmp
FLINT_INCLUDE=-I/usr/local/Cellar/flint/2.8.5/include/flint
FLINT_LIBS=-L/usr/local/Cellar/flint/2.8.5/lib -lflint

main : main.c
	${CC} ${CFLAGS} -o ${TARGET} ${SRC} ${FLINT_INCLUDE} ${FLINT_LIBS}


#all: ${TARGET}

#${TARGET} : ${SRC}
#	${CC} ${CFLAGS} -o ${TARGET} ${SRC} ${FLINT_INCLUDE} ${FLINT_LIBS}


clean:
	rm *.out

