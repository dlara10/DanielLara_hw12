adv_graph.png : DL_graph.py advection.txt
	python DL_graph.py
advection.txt : advection
	./advection > advection.txt
advection : DL_advection.cpp
	c++ DL_advection.cpp -o advection
