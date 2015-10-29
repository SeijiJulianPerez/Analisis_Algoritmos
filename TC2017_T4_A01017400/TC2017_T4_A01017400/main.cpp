//
//  main.cpp
//  TC2017_T4_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 29/10/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <chrono>
#include "Snap.h"

using namespace std::chrono;
typedef PNGraph DGraph;

int main() {
	DGraph dg = TSnap::LoadEdgeList<DGraph>("/Users/corage_wow/Desktop/twitter_combined.txt",0,1);
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	GraphML(dg);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
	std::cout << "GraphML: " << duration << std::endl;
    
	t1 = high_resolution_clock::now();
	GEXF(dg);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
	std::cout << "GEXF: " << duration << std::endl;
    
	t1 = high_resolution_clock::now();
	GDF(dg);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
	std::cout << "GDF: " << duration << std::endl;
    
	t1 = high_resolution_clock::now();
	JSON(dg);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
	std::cout << "JSON: " << duration << std::endl;
	return 0;
}


void GraphML(DGraph g) {
	std::ofstream file ("twitter.graphml");
	if (file.is_open()) {
		file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
		file << "<graphml xmlns=\"http://graphml.graphdrawing.org/xmlns\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://graphml.graphdrawing.org/xmlns http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd\">\n";
		file << "<graph id=\"G\" edgedefault=\"directed\">\n";
        
		for (DGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
			file << "<node id=\"" << NI.GetId() << "\"/>\n";
        
		int i = 1;
		for (DGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); EI++, ++i)
			file << "<edge id=\"e" << i << "\" source=\"" << EI.GetSrcNId() << "\" target=\"" << EI.GetDstNId() << "\"/>\n";
        
		file << "</graph>\n";
		file << "</graphml>\n";
		file.close();
	}
}

void GEXF(DGraph g) {
	std::ofstream file ("twitter.gexf");
	if (file.is_open()) {
		file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
		file << "<gexf xmlns=\"http://www.gexf.net/1.2draft\" version=\"1.2\">\n";
		file << "<graph mode=\"static\" defaultedgetype=\"directed\">\n";
		
		file << "<nodes>\n";
		for (DGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
			file << "<node id=\"" << NI.GetId() << "\" />\n";
		file << "</nodes>\n";
        
		file << "<edges>\n";
		int i = 1;
		for (DGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); EI++, ++i)
			file << "<edge id=\"" << i << "\" source=\"" << EI.GetSrcNId() << "\" target=\"" << EI.GetDstNId() << "\" />\n";
		file << "</edges>\n";
        
		file << "</graph>\n";
		file << "</gexf>\n";
		file.close();
	}
}

void GDF(DGraph g) {
	std::ofstream file ("twitter.gdf");
	if (file.is_open()) {
		file << "nodedef>id VARCHAR\n";
		for (DGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
			file << NI.GetId() << "\n";
        
		file << "edgedef>source VARCHAR, destination VARCHAR\n";
		for (DGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); EI++)
			file << EI.GetSrcNId() << ", " << EI.GetDstNId() << "\n";
        
		file.close();
	}
}

void JSON(DGraph g) {
	std::ofstream file ("twitter.json");
	if (file.is_open()) {
		file << "{ \"graph\": {\n";
		file << "\"nodes\": [\n";
		for (DGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); ) {
			file << "{ \"id\": \"" << NI.GetId() << "\" }";
			if (NI++ == g->EndNI())
				file << " ],\n";
			else
				file << ",\n";
		}
        
		file << "\"edges\": [\n";
		for (DGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); ) {
			file << "{ \"source\": \"" << EI.GetSrcNId() << "\", \"target\": \"" << EI.GetDstNId() << "\" }";
			if (EI++ == g->EndEI())
				file << " ]\n";
			else
				file << ",\n";
		}
		file << "} }";
        
		file.close();
	}
}