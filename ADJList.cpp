
/*
* 	Graph Algorithm : Undirected Adjacency List Instantiation
* 	
*	ADJList.cpp
* 
*	Created by Nino Lau on 2017.
* 	Copyright © Nino 2017. All rights reserved.
*/

#include "ADJList.hpp"


// Auxiliary Functions.



/* creat a list by default */
void UDGList::creatList() {
	cout << "Construct an undirected simple graph." << endl;
	// input vertex and edge number
	cout << "Input vertex number: ";
	cin >> Vnum;
	cout << "Input edge number: ";
	cin >> Enum;
	if(Vnum < 1 || Enum < 1 || (Enum > (Vnum * (Vnum-1) / 2))) {
		cout << "Input number invalid." << endl;
	}

	// initialize vertex node array
	for(int i = 0; i < Vnum; i++) {
		cout << "vertex(" << i << "): ";
		char ch = readChar();
		if(ch == 0) {
			cout << "Char is invalid." << endl;
			continue;
		}
		vexs[i].data = ch;   // data as input
		vexs[i].FirstEnode = NULL;        // linked list NULL
	}

	// initialize edge nodes
	for(int i = 0; i < Enum; i++) {
		cout << "Please input the edge start and end vertex data." << endl;
		cout << "edge(" << i << "): ";
		char c1, c2;                 // link two vertex
		int p1, p2;                  // get two vertex pos info
        Enode *node1, *node2;        // get two Enode
		c1 = readChar();
		c2 = readChar();
        if(c1 == 0 || c2 == 0) {
        	cout << "Char is invalid" << endl;
        	continue;
        }
        p1 = getPos(c1);
		p2 = getPos(c2);
        if(p1 == -1 || p2 == -1) {
        	cout << "The vertex hasn't been inserted." << endl;
        	continue;
        }
        cout << "Please input the edge weight above : ";
        int w;
        cin >> w;
		node1 = new Enode;
		node1->ivex = p2;            // add adjacent vertex info
		node1->weight = w;
		if(vexs[p1].FirstEnode == NULL)   // creat relation
			vexs[p1].FirstEnode = node1;
		else
			linkLast(vexs[p1].FirstEnode, node1);
        
		node2 = new Enode;           
		node2->ivex = p1;           // add adjacent vertex info 
		node2->weight = w;           
		if(vexs[p2].FirstEnode == NULL)  // created relation
			vexs[p2].FirstEnode = node2;
		else
			linkLast(vexs[p2].FirstEnode, node2);
	}
}



/* creat a list by array */
void UDGList::creatList(char vexs[], int vlen, Einfo *edges[], int elen) {
	cout << "Construct an undirected simple graph." << endl;
	//initialize vertex and edge number
	this->Vnum = vlen;
	this->Enum = elen;

	// initialize the vertex array
	for(int i = 0; i < vlen; i++) 
		if(!isalpha(vexs[i])) {
			cout << "Char is invalid." << endl;
	}
	for(int i = 0; i < vlen; i++) {
		this->vexs[i].data = vexs[i];
		this->vexs[i].FirstEnode = NULL;
	}

	// initialize the edge linked list
	for(int i = 0; i < elen; i++) {
		char c1 = edges[i]->start;
		char c2 = edges[i]->end;
		int w = edges[i]->weight;
        if(c1 == 0 || c2 == 0) {
        	cout << "Char is invalid" << endl;
        	continue;
        }
        int p1 = getPos(c1);
        int p2 = getPos(c2);
        if(p1 == -1 || p2 == -1) {
        	cout << "The vertex hasn't been inserted.";
        	continue;
        }
        Enode *node1, *node2;
        node1 = new Enode;
        node1->ivex = p2;
        node1->weight = w;
        if(this->vexs[p1].FirstEnode == NULL)
        	this->vexs[p1].FirstEnode = node1;
        else
        	linkLast(this->vexs[p1].FirstEnode, node1);
        node2 = new Enode;
        node2->ivex = p1;
        node2->weight = w;
        if(this->vexs[p2].FirstEnode == NULL)
        	this->vexs[p2].FirstEnode = node2;
        else
        	linkLast(this->vexs[p2].FirstEnode, node2);
	}
}



/* read a char function
* 
* @param: NULL
* @return: char
*/
char UDGList::readChar() {
	char ch;
	cin >> ch;
	if(isalpha(ch))
	    return ch;
	else return 0;
}



/* postion of char
* 
* @param: char
* @return: the position corresponding to vertex
*/   
int UDGList::getPos(char ch) {
	for(int i = 0; i < Vnum; i++) {
		if(vexs[i].data == ch)
			return i;
	}
	return -1;
}



/* add a node to existed UDGList
*
* @param: list of Enode
*         new node
* @return: NULL
*/
void UDGList::linkLast(Enode *list, Enode *node) {
	if(list == NULL) return;   // list mustn't be empty
	Enode *p = list;
	while(p->next) {
		p = p->next;
	}
	p->next = node;
}



/* depth first search auxiliary
* 
* @param: the visited node position
*         whether been visited
* @return: NULL
*/
void UDGList::DFS_aux(int i, int *visited) {
	// have been there and output
	visited[i] = 1;
	cout << vexs[i].data << " ";
	Enode* node = vexs[i].FirstEnode;
	while(node != NULL) {
		// go deep as long as it can 
		if(visited[node->ivex] == 0)
			DFS_aux(node->ivex, visited);
		node = node->next;
	}
}



/* depth first search auxiliary
* 
* @param: NULL
* @return: NULL
*/
void UDGList::BFS_aux(int i, int *visited) {
	// modify a queue(FIFO)
	int head = 0;
	int rear = 0;
	int queue[MAX];    // a queue to remind the adjacent Vnode position
	// have been there and output
	visited[i] = 1;
	cout << vexs[i].data << " ";
	Enode *node = vexs[i].FirstEnode;
	// push all adjacent vertex into the queue
	while(node != NULL) {
		queue[rear] = node->ivex;
		rear++;
		node = node->next;
	}
	// pop and traverse them ifn been traversed
	while(head != rear) {
		if(visited[queue[head]] != 1){
			visited[queue[head]] = 1;
			cout << vexs[queue[head]].data << " ";
		}	
		head++;
	}
}



/* get weight of edge start from s to t */
int UDGList::getWeight(int s, int t)
{
	if(s == t) return 0;  // cycle return zero  
	Enode *node = vexs[s].FirstEnode;
	while(node != NULL){
		if(t == node->ivex)
			return node->weight;
		node = node->next;
	}
	return INF;
}



/* exchange Enode array to Einfo array
*
* @param: NULL
* @return Einfo array
*/
UDGList::Einfo* UDGList::getEdges() {
	Enode *node;
	Einfo *edges = new Einfo[Enum];
	int index = 0;
	// make sure start index smaller than the end index
	// so that same edge won't push twice
	for(int i = 0; i < Vnum; i++) {
		node = vexs[i].FirstEnode;
		while(node != NULL){
			if(node->ivex > i) {
				edges[index].start = vexs[i].data;
				edges[index].end = vexs[node->ivex].data;
				edges[index].weight = node->weight;
				index++;
			}
			node = node->next;
		}
	}
	return edges;
}



/* sort the edges by their weight
*
*
* @param: Einfo array
* @return: NULL
*/
void UDGList::sortEdges(Einfo *edges) { 
	// bubble sort method
	for(int i = 0; i < Enum; i++)
		for(int j = i+1; j < Enum; j++)
			if(edges[i].weight > edges[j].weight) {
				Einfo temp = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}
}



/*
 * get the vexs[i]'s destination
 */
int UDGList::getEnd(int vends[], int i)
{
    while (vends[i] != 0)
        i = vends[i];
    return i;
}



// Public Functions.



/* constructors
*
* @param: NULL
* @return: NULL
*/
UDGList::UDGList() {
	creatList();
}



/* constructors
*
* @param: char array for info of vertex array
*         D2 char array for info of Enode
*         arrays length
* @return: NULL
*/
UDGList::UDGList(char vexs[], int vlen, Einfo *edges[], int elen) {
	creatList(vexs, vlen, edges, elen);
}



/* destructors -- clear the storage */
UDGList::~UDGList() {
	clear();
}



/* visit all vertex once by DFS method */
void UDGList::DFS() {
	int visited[Vnum];
	// initial have not been visited
	memset(visited, 0, Vnum);
	// start to traverse
	cout << "DFS visit: ";
	for(int i = 0; i < Vnum; i++) {
		if(visited[i] != 1)
		    DFS_aux(i, visited);
	}
	cout << endl;
}



/* visit all vertex once by BFS method */
void UDGList::BFS() {
	int visited[Vnum];
	// initial have not been visited
	memset(visited, 0, Vnum);
	// start to traverse
	cout << "BFS visit: ";
	for(int i = 0; i < Vnum; i++) {
		if(visited[i] != 1)
			BFS_aux(i, visited);
	}
	cout << endl;
}



/* Prim Algorithm
*
* Prim Algorithm to find a MST
* @param: start Vnode
* @function: find a minimal spanning tree
*/
void UDGList::Prim(int start) {
	
	// initialization
    char prims[Vnum];                    // MST set
    int index = 0;                       // index of MST
    // initialize start node as first prims
    prims[index++] = vexs[start].data;  
    int weights[Vnum];                   // nearest neighbor weight of MST set
    // initialize the weights
    for(int i = 0; i < Vnum; i++)        
    	weights[i] = getWeight(start, i);
    
    // Prim Algorithm to creat a MST
    for(int i = 0; i < Vnum; i++) {
    	if(start == i) continue;
    	int minimal = INF;
    	int nearest;
    	// find the nearest adjacent vertex
    	for(int j = 0; j < Vnum; j++)
    		if(weights[j] != 0 && weights[j] < minimal) {
    			minimal = weights[j];
    			nearest = j;
    		}
    	// add the nearest into the MST set
    	prims[index++] = vexs[nearest].data;
    	// reset weight of vertices
    	weights[nearest] = 0;
    	for(int j = 0; j < Vnum; j++) {
    		if(weights[j] != 0)
    			weights[j] = std::min(getWeight(nearest, j), weights[j]);
    	}
    }

    //throw the error
    if(index != Vnum) {
    	cout << "Sorry, MST only admit connected graph." << endl;
    	return ;
    }

    // add the weight of MST
    int sum = 0;
    int minimum;
    for (int i = 1; i < index; i++) {
        minimum = INF;
        // get the position of prims[i]
        int pos2 = getPos(prims[i]);
        // find the minimal length between prims[i] and vertex front
        // also see as find prims prev
        for (int j = 0; j < i; j++) {
            int pos1 = getPos(prims[j]);
            int temp = getWeight(pos1, pos2);
            if (temp < minimum)
                minimum = temp;
        }
        sum += minimum;
    }

    // print MST
    cout << "Prim (" << vexs[start].data << ") = " << sum << "." << endl;
    cout << "Tree nodes are : ";
    for(int i = 0; i < index; i++)
    	cout << prims[i] << " ";
    cout << endl;
}



/* Kruskal Algorithm
*
* Kruskal Algorithm to find a MST
* @param: NULL
* @function: find a minimal spanning tree
*/
void UDGList::Kruskal() {
    
	// initialization
	Einfo *edges = getEdges();          // all edges in graph 
	Einfo rets[MAX];                        // MST edges        
	// sort the edges according to the weight priority
	sortEdges(edges);
	int vends[MAX] = {0};
	int index = 0;

	for(int i = 0; i < Enum; i++) {
		int final1 = getEnd(vends, getPos(edges[i].start));
		int final2 = getEnd(vends, getPos(edges[i].end));
		if(final1 != final2){          // do not form a cycle
			vends[final1] = final2;
			rets[index++] = edges[i];
		}
	}

	// print Kruskal
    int sum = 0;
    for(int i = 0; i < index; ++i)
    	if(rets[i].weight != INF)
    		sum += rets[i].weight;
    cout << "Kruskal = " << sum << "\nEdges: ";
    for(int i = 0; i < index; ++i)
    	cout << "(" << rets[i].start << "," << rets[i].end << ") ";
    cout << endl;
}



/* Dijkstra Algorithm
*
* Dijkstra Algorithm to find the minimun path
* @param: start vertex -- Vstart's index
*         previous vertex
*         distance array
* @return: NULL
* @function: find the minimun path from start vertex to the destination
*/
void UDGList::Dijkstra(int vs, int prev[], int dist[]) {
	int flag[Vnum];                   // be sure of the minimum access

	// initialization
	for(int i = 0; i < Vnum; i++) {
		flag[i] = 0;                  // haven't got minimum access
		prev[i] = 0;                  // no prev vertex
		dist[i] = getWeight(vs, i);   // the path length of vs to V(i)
	}
	// vs setting
    flag[vs] = 1;
    dist[vs] = 0;

    // find the minimal path of a vertex
    int minimal = INF;
    int nearest;                
    for(int i = 1; i < Vnum; i++) {
    	minimal = INF;

    	// first to find the nearest vertex from vs
    	for(int j = 0; j < Vnum; j++)
    		if(flag[j] == 0 && dist[j] < minimal) {
    			minimal = dist[j];
    			nearest = j;
    		}
    	flag[nearest] = 1;

    	// recorrect the distance and add prevous vertex
    	for(int j = 0; j < Vnum; j++) {
    		int temp = getWeight(nearest, j);
    		if(temp != INF)
    			temp += minimal;
    		if(flag[j] == 0 && temp < dist[j]) {
    			dist[j] = temp;
    			prev[j] = nearest;
    		}
    	}
    }

    // print the Dijkstra Minimal Path
    cout << "Dijkstra(" << vexs[vs].data << "): " << endl;
    for(int i = 0; i < Vnum; i++)
    	cout << "shortest(" << vexs[vs].data << "," << vexs[i].data << ")= " << dist[i] << endl;
}



/* print UDGList infomation
* 
* formatted:
*/
void UDGList::print() {
	cout << "List Graph: " << endl;
	for(int i = 0; i < Vnum; i++){
		cout << vexs[i].data << ": " << endl;
        Enode *node = vexs[i].FirstEnode;
        while (node != NULL)
        {
            cout << "  (" << vexs[i].data << "," << vexs[node->ivex].data << ") with the length of " << getWeight(i, node->ivex) << endl;
            node = node->next;
        }
        cout << endl;
	}
}



/* 
*clear UDGList -- clear the storage
*/
void UDGList::clear() {
	// clear the edge storage
	for(int i = 0; i< Enum; i++) {
		Enode *node = vexs[i].FirstEnode;
		while(node != NULL) {
			Enode *temp = node;
			node = node->next;
			delete temp;
			temp = NULL;
		}
	}
}
