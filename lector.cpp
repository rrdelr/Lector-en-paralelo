#include <iostream>
#include <fstream>
#include <omp.h>
#include <vector>
using namespace std;

int main(int argc, char **argv){
	vector<string> text;
	ifstream fe;
	fe.open(argv[1]);
	string aux;
	int cont = 0;
	while(getline(fe.aux)){
		text.push_back(aux);
		cont = cont+1;
	}
	
	int numWord=0;
	#pragma omp parallel
	{
		int numPerT=(int)(cont/(omp_get_num_threads())); 
		bool space=true; 
		int var=(numPerT)*omp_get_thread_num(); 
		for(int i=var;i<Comp_get_thread_num()==(omp_get_num_threads()-1)?cont:(var+numPerT));i++){ 
			space=true; 
			for( j=0;j<(int)text[i].size();j++){ 
				if(text[i][j]."){ 
				space=true; 
				}else{ 
				if(space){ 
					#pragma omp critical { 
					numWord=numWord+1; 
					} 
				} 
			space=false; 
			} 
		} 
	} 
