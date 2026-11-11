#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1,x2;
	string t1,t2;
	cin>>x1>>t1>>x2>>t2;
	if(x1==x2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(t1[0]==t2[0]&&t1[1]==t2[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}	
	if(((t1[2]=='A'||t1[2]=='B'||t1[2]=='C')&&(t2[2]=='A'||t2[2]=='B'||t2[2]=='C'))||((t1[2]=='D'||t1[2]=='E')&&(t2[2]=='D'||t2[2]=='E'))){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if((t1[2]=='A'&&t2[2]=='B')||(t2[2]=='A'&&t1[2]=='B')||(t1[2]=='C'&&t2[2]=='B')||(t2[2]=='C'&&t1[2]=='B')||(t1[2]=='D'&&t2[2]=='E')||(t2[2]=='D'&&t1[2]=='E')){
		cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
} 
