#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool che=0,pai=0,ce=0,lin=0;
	if(c1==c2){
		che=1;
	}
	string pa1=s1.substr(0,2);
	string pa2=s2.substr(0,2);
	if(che&&pa1==pa2){
		pai=1;
	}
	char t1=s1[2],t2=s2[2];
	if(t1>t2)swap(t1,t2);
	if(che&&pai&&((t1=='A'&&t2=='B')||(t1=='A'&&t2=='C')||(t1=='B'&&t2=='C')||(t1=='D'&&t2=='F'))){
		ce=1;
	}
	if(che&&pai&&ce&&((t1=='A'&&t2=='B')||(t1=='B'&&t2=='C')||(t1=='D'&&t2=='F'))){
		lin=1;
	}
	cout << che << pai << ce << lin;
	
	return 0;
}
