
/*
* 	Graph Algorithm : Undirected Adjacency List Instantiation
* 	
*	ADJList.hpp
* 
*	Created by Nino Lau on 2017.
* 	Copyright © Nino 2017. All rights reserved.
*/

#ifndef _ADJLIST_HPP_
#define _ADJLIST_HPP_

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAX 100
#define INF 10000

class UDGList
{

private:               // Graph property classes.
    struct Enode       // edge node structure   
    {
    	Enode() {
    		ivex = -1;
    		next = NULL;
    	}
        int ivex;      // pointed vertex infomation
        int weight;    // the weight of the edge
        Enode* next;   // next edge
        friend class UDGList;
    };
	struct Vnode   	   // vertex node structure
	{
		Vnode() {
			data = 0;
			FirstEnode = NULL;
		}
		char data;     // vertex infomation
		Enode *FirstEnode;  // the FirstEnode connected with this vertex
		friend class UDGList;
	};



public:                // Exhibition class -- to show info of an edge.
    struct Einfo
    {
    	Einfo() {
    		start = 0;
    		end = 0;
    		weight = INF;
    	}
    	Einfo(char s, char t, int w) : start(s), end(t), weight(w) {}
    	~Einfo() {}
    	char start, end;// start and end vertex data
    	int weight;    // the weight of the edge
    };



private:               // Graph properties.
	int Vnum;          // vertex number
	int Enum;          // edge number
	Vnode vexs[MAX];   // vertex container



private:               // Auxiliary Functions.
	// creat the default list
    void creatList();
    // creat the list with array
    void creatList(char vexs[], int vlen, Einfo *edges[], int elen);
	// read a char
	char readChar();
	// return postion of char   
	int getPos(char ch);
	// link node behind the list
	void linkLast(Enode *list, Enode *node);  
    // depth first search auxiliary
    void DFS_aux(int i, int *visited);
    // breadth first search auxiliary
    void BFS_aux(int i, int *visited);
    // get the weight of an edge
    int getWeight(int s, int t);
    // get the info of an edge
    Einfo* getEdges();
    // sort edge according to weight
    void sortEdges(Einfo *edges);
	int getEnd(int vends[], int i);


public:                 // Public Functions.
	// constructors and destructor
	UDGList();
	UDGList(char vexs[], int vlen, Einfo *edges[], int elen);
	~UDGList();
	// depth first search
	void DFS();
	// breadth first search
	void BFS();
	// Prime Algorithm
	void Prim(int start);
	// Kruskal Algorithm
	void Kruskal();
	// Dijkstra Algorithm
	void Dijkstra(int vs, int prev[], int dist[]);
	// print UDGList infomation
	void print();
	// clear the storage
	void clear();
};

#endif
