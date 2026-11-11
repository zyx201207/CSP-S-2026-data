#include <bits/stdc++.h>
using namespace std;
int n,m;
bool a,b,c;
string n1,m1; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>n1>>m>>m1;
	if(n==m){
		cout<<1;
		a=true;
	}
	else{
		cout<<0;
		a=false;
	}
	if(a&&n1[0]==m1[0]&&n1[1]==m1[1]){
		cout<<1;
		b=true;
	}
	else{
		cout<<0;
		b=false;
	}
	bool qwer;
	if(n1[2]>='A' && n1[2]<='C' && m1[2]>='A' && m1[2]<='C'|| n1[2]>='D' && n1[2]<='F' && m1[2]>='D' && m1[2]<='F'){
		qwer=true;
	}
	else{
		qwer=false;
	}
	if(a&&b&&qwer){
		cout<<1;
		c=true;
	}
	else{
		cout<<0;
		c=false;
	}
	bool qwert;
	if(n1[2]-m1[2]==1 || m1[2]-n1[2]==1){
		if(n1[2]=='C' && m1[2]=='D' || n1[2]=='D' && m1[2]=='C'){
			qwert=true;
		}
	}
	else{
		qwert=false;
	}
	if(a&&b&&c&&qwert){
		cout<<1;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
