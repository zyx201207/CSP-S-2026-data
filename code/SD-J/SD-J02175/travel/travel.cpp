#include<bits/stdc++.h>
using namespace std;
int r1,x1;
string r2,x2;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>r1>>r2>>x1>>x2;
	int x=r2[2],y=x2[2];
	if(r1==x1 && r1!=01 && r1!=16&& x1!=01 && x1!=16){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(r2[0]==x2[0] && r2[1]==x2[1]){
		cout<<"1";
		
	}
	else{
		cout<<"000";
		return 0;
	}
	if(x<='C' && y>='D'){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(abs(x-y)==1){
		cout<<1;
	} 
	else{
		cout<<0;
	}
	return 0;
} 
