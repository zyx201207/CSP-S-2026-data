#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		char x1=s1[2];
		char x2=s2[2];
		if((x1<='C'&&x1>='A'&&x2<='C'&&x2>='A')||(x1=='D'&&x2=='F')||(x1=='F'&&x2=='D')){
			cout<<1;
		}else{
			cout<<0;
		}
		char xx1=s1[2];
		char xx2=s2[2];
		if((xx1=='A'&&xx2=='B')||(xx1=='B'&&xx2=='A')||(xx1=='B'&&xx2=='C')||(xx1=='C'&&xx2=='B')||(xx1=='F'&&xx2=='D')||(xx1=='D'&&xx2=='F')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
