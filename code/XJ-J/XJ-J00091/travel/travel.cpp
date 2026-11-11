#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	
	bool b1=0,b2=0,b3=0,b4=0;
	if(c1==c3){
		b1=1;
	}
	
	string p1,p2;
	p1=c2[0]+c2[1];
	p2=c4[0]+c4[1];
	if(p1==p2 && b1){
		b2=1;
	} 
	
	if((c2[2]<='C')==(c4[2]<='C') && b2){
		b3=1;
	}
	
	if((c2[2]=='A') && (c4[2]=='B')
	   || (c2[2]=='B') && (c4[2]=='A')
	   || (c2[2]=='B') && (c4[2]=='C')
	   || (c2[2]=='C') && (c4[2]=='B')
	   || (c2[2]=='D') && (c4[2]=='F')
	   || (c2[2]=='F') && (c4[2]=='D')){
		if(b2){
	   		b4=1;
		} 
	}
	
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
