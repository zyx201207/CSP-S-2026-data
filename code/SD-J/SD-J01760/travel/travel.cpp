#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	int x=(s1[0]-'0')*10+(s1[1]-'0');
	int y=(s2[0]-'0')*10+(s2[1]-'0');
	if(x!=y){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	x=(c1[0]-'0')*10+(c1[1]-'0');
	y=(c2[0]-'0')*10+(c2[1]-'0');
	char op1=c1[2];
	char op2=c2[2];
	if(x!=y){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((op1=='A'||op1=='B'||op1=='C')&&(op2=='D'||op2=='F')||(op2=='A'||op2=='B'||op2=='C')&&(op1=='D'||op1=='F')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(op1=='A'&&op2=='B'||op1=='B'&&op2=='C'||op1=='D'&&op2=='F'||op2=='A'&&op1=='B'||op2=='B'&&op1=='C'||op2=='D'&&op1=='F'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

