hw5:	main.cpp boardgame2d.h boardgame2d.cpp pegsolitaire.cpp pegsolitaire.h eightpuzzle.h eightpuzzle.cpp klostski.h klostski.cpp
		g++ main.cpp boardgame2d.cpp pegsolitaire.cpp eightpuzzle.cpp klostski.cpp -o hw5


target:	hw5



clean:
		rm hw5