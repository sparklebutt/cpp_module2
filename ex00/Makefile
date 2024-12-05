# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 16:35:00 by shaboom           #+#    #+#              #
#    Updated: 2024/12/05 16:35:22 by shaboom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++11 -MMD -MP
CPPFILES = main.cpp Fixed.cpp
BUILDDIR = buildofiles/
OFILES = $(addprefix $(BUILDDIR), $(CPPFILES:.cpp=.o))
EXEC = Fixed

# depency files
DEPFILES = $(OFILES:.o=.d)

all: $(BUILDDIR) $(EXEC)

$(BUILDDIR)%.o: %.cpp
	$(CPP) $(CPPFLAGS) -g -c $< -o $@

$(EXEC): $(OFILES)
	$(CPP) $(CPPFLAGS) $(OFILES) -o $(EXEC)
	@echo "\033[0;95m Created executable\033[0m"

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	@echo "\033[0;91m Build folder created\033[0m"

-include $(DEPFILES)

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(OFILES)
	rm -rf $(DEPFILES)
	@echo "\033[0;93m build directory, ofiles and depency files cleaned out\033[0m"

fclean: clean
	rm -f $(EXEC)
	@echo "\033[0;91m executbale removed\033[0m"

re: fclean all $(EXEC)

.PHONY: all clean fclean re