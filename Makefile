NAME = computor
CPP = c++ -fsanitize=address -g3
INCS = inc
BUILDDIR=build/
CPP_FLAGS = -I${INCS} -std=c++11 -Wall -Wextra
SRCS = srcs/computor.cpp srcs/main.cpp srcs/math.cpp srcs/print.cpp srcs/termutils.cpp srcs/utils.cpp
OBJS = ${SRCS:.cpp=.o}
OBJS_TARGET=${addprefix ${BUILDDIR},${subst /,_,${OBJS}}}

# Style constants
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
NC=\033[0m # No Color


all : ${NAME}
	@echo "${GREEN}✔️  Done build..${NC}"

bonus : ${NAME}

${NAME}: ${OBJS_TARGET}
	@echo "${GREEN}😏  Linking..${NC}"
	@${CPP} ${BUILDDIR}*.o ${CPP_FLAGS} -o ${NAME}

build/%.o : ${OBJS}
	@echo "${GREEN}📇  Compile finish..${NC}"

.cpp.o : 
	@echo "${GREEN}📇  Compiling $<..${NC}"
	@${CPP} ${CPP_FLAGS} -c $< -o ${BUILDDIR}${subst /,_,$@}

clean : 
	@echo "${YELLOW}🗑️  Removing Objects..${NC}"
	@rm -rf ${BUILDDIR}*.o

fclean : clean
	@echo "${YELLOW}🗑️  Removing ${NAME}..${NC}"
	@rm -rf ${NAME}

re : fclean all

.PHONY : re clean fclean all