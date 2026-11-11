#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool x=0,p=0,z=0;
string p1,p2;
char h1,h2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	//条件1 
	if(c1==c2){
		cout<<"1";
		x=1;
	}
	else{
		cout<<"0";
		x=0;	
	} 
	p1=s1[0]+s1[1];
	p2=s2[0]+s2[1];
	h1=s1[2];
	h2=s2[2];
	//同侧判断 
	if(h1>='A'&&h1<='C'&&h2>='A'&&h2<='C'||h1>='E'&&h1<='F'&&h2>='E'&&h2<='F'){
		z=1;
	}
	else{
		z=0;
	}
	//条件2
	if(x==1&&p1==p2){
		cout<<"1";
		p=1;
	}
	else{
		cout<<"0";
		p=0;
	}
	//条件3 
	if(p==1&&z==1){
		cout<<"1";
		
	}
	else{
		cout<<"0";
	}
	//条件4 
	if(x==1&&z==1&&(abs(((s1[0]-'0')*10+(s1[1]-'0'))-((s2[0]-'0')*10+(s2[1]-'0')))+abs(h1-h2))<=1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
