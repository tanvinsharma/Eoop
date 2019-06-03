
basketballmaker: main.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -w -o basketball_graph main.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -w -o basketball_no_graph main4.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -w -o basketball_man_pla_rel main2.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -w -o basketball_graph main3.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -w -o basketball_no_graph main5.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -w -o exceptions exceptions.cpp structure.cpp backbone.cpp
	g++ -std=gnu++11 -w -o final main_one.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp
	g++ -std=gnu++11 -w -o test tests.cpp backbone.cpp structure.cpp graph.cpp interactive.cpp