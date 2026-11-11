#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","r",stdout) ;
	int che[2];
	string suo , wu;
	string heo,hao;
	int pai,pei;
	for(int i = 0;i<2;i++){
		cin >> che[i];
		if(i==0){
			cin >> pai >> hao;
		}
		else{
			cin >> pei >> heo;
		}
		
	}
	if(che[0]==che[1]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	
	if(che[0]==che[1] && pai==pei){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	
	
	if(che[0]==che[1] && pai==pei&&hao>="A"&&hao <="C"&&heo>="A"&&heo <="C" || che[0]==che[1] && pai==pei&&hao=="D"&&heo =="F"||che[0]==che[1] && pai==pei&&heo=="D"&&hao =="F"){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	
	
	
	if(che[0]==che[1] && pai==pei&&"B"==hao && "A"==heo||"A"==hao && "B"==heo&&che[0]==che[1] && pai==pei ){
		cout << 1;
	}
	else if(che[0]==che[1] && pai==pei&&"B" == hao&& "C" ==heo || "C" == hao&& "B" ==heo&&che[0]==che[1] && pai==pei  ){
		cout << 1;
	}
	
	else if(che[0]==che[1] && pai==pei&&"D" == hao&& "F" ==heo || "F" == hao&& "D" ==heo&&che[0]==che[1] && pai==pei  ){
		cout << 1;
	}
    else{
		cout << 0;
	}	
	
	return 0;
	
}
