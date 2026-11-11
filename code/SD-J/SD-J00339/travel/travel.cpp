#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	bool flag=true;
	string r,x,r1,x1,r2,x2;
	cin>>r>>r1>>x>>x1;
	if(r==x){
		cout<<1;
	}else{
		cout<<0;
		flag=false;
	}
	r2=r1[0]+r1[1];
	x2=x1[0]+x1[1];
	if(r2==x2 && flag){
		cout<<1;
	}else{
		cout<<0;
		flag=false;
	}
	if(r1[2]>='A'&&r1[2]<='C'&&x1[2]>='A'&&x1[2]<='C'&&flag){
		cout<<1;
	}else if(((r1[2]=='D'&&x1[2]=='F')||(r1[2]=='F'&&x1[2]=='D'))&&flag){
		cout<<1;
	}else{
		cout<<0;
		flag=false;
	} 
	if((r1[2]=='A'&&x1[2]=='B')||(r1[2]=='B'&&x1[2]=='A')||(r1[2]=='B'&&x1[2]=='C')||(r1[2]=='C'&&x1[2]=='B')||(r1[2]=='D'&&x1[2]=='F')||(r1[2]=='F'&&x1[2]=='D')){
		if(flag){ 
			cout<<1;
		}else{
			cout<<0;
			flag=false;
		}
	}else{
		cout<<0;
		flag=false;
	}
	return 0;
}
