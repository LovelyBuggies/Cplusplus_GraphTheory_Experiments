
/*
* 	Graph Algorithm : Undirected Adjacency List Instantiation
* 	
*	Client.cpp
* 
*	Created by Nino Lau on 2017.
* 	Copyright © Nino 2017. All rights reserved.
*/

#include "TestPrint.hpp"
#include "TestBFS.hpp"
#include "TestDFS.hpp"
#include "TestPrim.hpp"
#include "TestKruskal.hpp"
#include "TestDijkstra.hpp"
#include <iostream>

using namespace std;

int main() {
	cout << "\n\nThis is a test for Algorithms in Graph." << endl;
	cout << "Welcome to have a try!" << endl;
	cout << "Are you ready for beginning? - 'r' to run." << endl;
	char ready = '\0';
	cin >> ready;
	while(ready != 'r' && ready != 'R') {
		cout << "You need to run this project with command - 'r'. If you have to leave please input - 'b'" << endl;
		cin >> ready;
		if(ready == 'b' || ready == 'B') {
			cout << "\nGlad for your using! And see you next time!" << endl;
			cout << "😚 😚 😚 Bye-Bye! 😚 😚 😚" << endl << endl;
            return 0;
		}
	}
	cout << "\n😀 😀 😀  Graph Adventure Begin 😀 😀 😀\n " << endl;
	cout << "\nGuide: " << endl;
	cout << "		- 'm' 	-- Manipulor of this graph algorithm tests." << endl;
	cout << "		- 'g' 	-- To show the guide of this graph algorithm tests." << endl;
	cout << "		- 'i' 	-- Information of the graph you have constructed." << endl;
	cout << "		- 'b' 	-- Breath First Search for vertices in graph." << endl;
	cout << "		- 'd' 	-- Depth First Search for vertices in graph." << endl;
	cout << "		- 'p' 	-- Prim Algorithm to find a minimal spanning tree." << endl;
	cout << "		- 'k' 	-- Kruskal Algorithm to find a minimal spanning tree." << endl;
	cout << "		- 'j' 	-- Dijkstar Algorithm to find minimal path length of a single source graph." << endl;
	cout << "		- 'a' 	-- To run all the graph algorithm tests." << endl;
	cout << "		- 'q' 	-- To quit the graph algorithm tests." << endl;
	bool run = true;
	while(run) {
		char item;
		cout << "[ choice ] " << endl << " ";
		cin >> item;
		if(item == 'b' || item == 'B')
			testBFS();
		else if(item == 'd' || item == 'D')
			testDFS();
		else if(item == 'i' || item == 'I')
			testPrint();
		else if(item == 'p' || item == 'P')
		    testPrim();
		else if(item == 'k' || item == 'K')
		    testKruskal();
		else if(item == 'j' || item == 'J')
		    testDijkstra();
		else if(item == 'a' || item == 'A') {
			testBFS();
			testDFS();
			testPrim();
			testKruskal();
			testDijkstra();
		}
		else if(item == 'q' || item == 'Q')
			run = false;
		else if(item == 'g' || item == 'G') {
			cout << "\nGuide: " << endl;
			cout << "		- 'm' 	- Manipulor of this graph algorithm tests." << endl;
			cout << "		- 'g' 	- To show the guide of this graph algorithm tests." << endl;
			cout << "		- 'i' 	- Information of the graph you have constructed." << endl;
			cout << "		- 'b' 	- Breath First Search for vertices in graph." << endl;
			cout << "		- 'd' 	- Depth First Search for vertices in graph." << endl;
			cout << "		- 'p' 	- Prim Algorithm to find a minimal spanning tree." << endl;
			cout << "		- 'k' 	- Kruskal Algorithm to find a minimal spanning tree." << endl;
			cout << "		- 'j' 	- Dijkstar Algorithm to find minimal path length of a single source graph." << endl;
			cout << "		- 'a' 	- To run all the graph algorithm tests." << endl;
			cout << "		- 'q' 	- To quit the graph algorithm tests." << endl;
		}
		else if(item == 'm' || item == 'M') {
			cout << "\nNAME: " << endl;
			cout << "\nGraphic Adventure" << endl << endl;
			cout << "SYNOPSIS: " << endl;
			cout << "\n\"Graphic Adventure\"\t[ - m ]\t[ - g ]\t[ - i ]\t[ - b ]\t[ - d ]\n\t\t\t[ - p ]\t[ - k ]\t[ - j ]\t[ - a ]\t[ - q ]\t" << endl << endl;
			cout << "DESCRIPTION: " << endl;
			cout << "\nThe command options are showing in the guide.";
			cout << " If you want to see the guide, please input - 'g' in the choice below. And all command options are adapted to both uppercase letters and lowercase letters." << endl;
			cout << "\nThe purpose of a such a program is to allow you to solve basic graph algorithm problems efficiently. ";
			cout << "Graphic Adventure is invoked with the command 'r'. Once start, this program can do several kinds of things, such as using Breath First Search for vertices in graph; ";
			cout << "using Depth First Search for vertices in graph; using Prim Algorithm to find a minimal spanning tree;";
			cout << " using Kruskal Algorithm to find a minimal spanning tree; using Dijkstar Algorithm to find minimal path length of a single source graph.";
			cout << " You can end the adventure with command option - 'q'. And when you are structed in problems, it is nice to see the guide with command option - 'g'." << endl << endl;
			cout << "Copyright © Nino 2017. All rights reserved." << endl << endl;
		}
		else
			cout << "No options command found. 'q' to quit." << endl;
	}
	cout << "\nGlad for your using! And see you next time!" << endl;
	cout << "😚 😚 😚 Bye-Bye! 😚 😚 😚" << endl << endl;
    return 0;
}