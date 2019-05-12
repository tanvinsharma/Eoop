
footballmaker: main.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -o football_graph main.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -o football_no_graph main4.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -o football_man_pla_rel main2.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -o interactive_graph main3.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -o interactive_no_graph main5.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -o exceptions exceptions.cpp structure.cpp backbone.cpp
