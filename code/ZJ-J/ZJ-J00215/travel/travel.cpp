#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
bool re(){
	if(e=='A'&&(f=='B'||f=='C')) return 1;
	if(e=='B'&&(f=='A'||f=='C')) return 1;
	if(e=='C'&&(f=='B'||f=='A')) return 1;
	if(e=='D'&&f=='E') return 1;
	if(e=='E'&&f=='D') return 1;
	return 0;
}
bool xiangl(){
	if(e=='A'&&f=='B') return 1;
	if(e=='B'&&f=='A') return 1;
	if(e=='B'&&f=='C') return 1;
	if(e=='C'&&f=='B') return 1;
	if(e=='D'&&f=='E') return 1;
	if(e=='E'&&f=='D') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(re()){
				cout<<1;
				if(xiangl()) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
