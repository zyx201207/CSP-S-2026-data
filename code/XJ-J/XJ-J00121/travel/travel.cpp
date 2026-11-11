#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string e,f;
	cin>>a>>e>>b>>f;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(e==f){
		cout<<"000";
		return 0;
	}
	if(e[0]==f[0]&&e[1]==f[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(e[0]==f[0]){
		if(e[1]==f[1]){
			if((e[2]=='A'||e[2]=='B'||e[2]=='C')&&(f[2]=='A'||f[2]=='B'||f[2]=='C')){
				cout<<"1";
			}else if((e[2]=='D'||e[2]=='F')&&(f[2]=='D'||f[2]=='F')){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
		else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if((e[2]=='A'||e[2]=='B'||e[2]=='C')&&(f[2]=='A'||f[2]=='B'||f[2]=='C')){
		if(e[0]==f[0]&&e[1]==f[1]){
			if(e[2]=='A'&&f[2]=='B'||e[2]=='B'&&f[2]=='C'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}
	if((e[2]=='D'||e[2]=='F')&&(f[2]=='D'||f[2]=='F')){
		if(e[0]==f[0]&&e[1]==f[1]){
			if(e[2]=='D'&&f[2]=='F'){
				cout<<"1";
				return 0;
			}else{
				cout<<"0";
				return 0;
			}
		}else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
} 
