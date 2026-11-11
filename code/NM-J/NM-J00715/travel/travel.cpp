#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q,w,e,r;
	cin>>q>>w>>e>>r;
	bool a=1,b=1,c=0,d=1;
	int n=0;
	if(q!=e){
		cout<<"0000";
		return 0;
	}
	int s_1=(w[0]-48*10)+(w[1]-48);
	int s_2=(r[0]-48*10)+(r[1]-48);
	if(s_1!=s_2){
		cout<<"1000";
		return 0;
	}
	if((w[2]>='A'&&w[2]<='C'&&r[2]>='A'&&r[2]<='C')){
		n=1;
	}
	if((w[2]=='D'&&r[2]=='F')||(r[2]=='D'&&w[2]=='F')){
		n=2;
	}
	if(n==0){
		cout<<"1100";
		return 0;
	}
	if(n==2){
		cout<<1111;
		return 0;
	}
	if(w[2]=='B'||r[2]=='B'){
		cout<<1111;
	}
	else{
		cout<<1110;
	}
	return 0;
} 
