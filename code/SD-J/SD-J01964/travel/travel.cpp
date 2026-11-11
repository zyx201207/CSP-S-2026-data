#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a1,a2;
	string b1,b2,b1x,b2x;
	char b1y,b2y;
	cin>>a1>>b1>>a2>>b2;
	b1x=b1[0]+b1[1];
	b1y=b1[2];
	b2x=b2[0]+b2[1];
	b2y=b2[2];
	
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}else if(b1x!=b2x){
		cout<<"1000";
		return 0;
	}else if((b1y=='B'||b1y=='A'||b1y=='C')&&(b2y=='D'||b2y=='F')){
		cout<<"1100";
		return 0;
	}else if((b2y=='B'||b2y=='A'||b2y=='C')&&(b1y=='D'||b1y=='F')){
		cout<<"1100";
		return 0;
	}else if(abs(b1y-b2y)==1||(b1y=='D'&&b2y=='F')||(b1y=='F'&&b2y=='D')){
		cout<<"1111";
		return 0;
	}else{
		cout<<"1110";
		return 0; 
	}
	return 0;
} 
