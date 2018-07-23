
/*
* 	Graph Algorithm : Undirected Adjacency List Instantiation
* 	
*	TestKruskal.hpp
* 
*	Created by Nino Lau on 2017.
* 	Copyright © Nino 2017. All rights reserved.
*/

#ifndef _TESTKRUSKAL_HPP_
#define _TESTKRUSKAL_HPP_
#include "ADJList.hpp"

void testKruskal()
{
    cout << "\n********** Kruskal TEST BEGIN **********" << endl << endl;
    // preparation
    int prev[MAX] = {0};
    int dist[MAX] = {0};
    // Vertice array
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    // UDGList::Einfo array
    UDGList::Einfo *edges[] = {
               // Vstart Vend weight
        new UDGList::Einfo('A', 'B', 12), 
        new UDGList::Einfo('A', 'F', 16), 
        new UDGList::Einfo('A', 'G', 14), 
        new UDGList::Einfo('B', 'C', 10), 
        new UDGList::Einfo('B', 'F',  7), 
        new UDGList::Einfo('C', 'D',  3), 
        new UDGList::Einfo('C', 'E',  5), 
        new UDGList::Einfo('C', 'F',  6), 
        new UDGList::Einfo('D', 'E',  4), 
        new UDGList::Einfo('E', 'F',  2), 
        new UDGList::Einfo('E', 'G',  8), 
        new UDGList::Einfo('F', 'G',  9), 
    };
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    
    // item
    int item = 0;
    cout << "Which construction do you want to try?" << endl;
    cout << "Item(0): default construction." << endl;
    cout << "Item(1): array defined." << endl;
    UDGList* pG;
    cout << "item: ";
    cin >> item;
    if(item == 0)
        pG = new UDGList();
    else 
        pG = new UDGList(vexs, vlen, edges, elen);

    // Kruskal
    pG->Kruskal();
    
    // clear the storage
    for(int i = 0; i < 12; i++) {
        delete edges[i];
        edges[i] = NULL;
    }
    delete pG;
    pG = NULL;
    cout << "\n********** Kruskal TEST COMPLETE **********" << endl << endl;
}

#endif