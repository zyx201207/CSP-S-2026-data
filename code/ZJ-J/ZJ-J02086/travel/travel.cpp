#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string u,v;
	cin>>a>>u>>b>>v;
	if(a==b){
		cout<<1;
	} else {
		cout<<0;
	}
	if((u[0]-'0')*10+u[1]-'0'==(v[0]-'0')*10+v[1]-'0'&&a==b){
		cout<<1;
	} else {
		cout<<0;
	}
	if((u[2]=='F'||u[2]=='D')&&a==b){
		if(v[2]=='F'||v[2]=='D'){
			cout<<(1&&(u[0]-'0')*10+u[1]-'0'==(v[0]-'0')*10+v[1]-'0');
		} else {
			cout<<0;
		}
	} else if (a==b&&(u[2]=='C'||u[2]=='B'||u[2]=='A')){
		if(v[2]=='C'||v[2]=='B'||v[2]=='A'){
			cout<<(1&&(u[0]-'0')*10+u[1]-'0'==(v[0]-'0')*10+v[1]-'0');
		} else {
			cout<<0;
		}
	} else {
		cout<<0;
	}
	if(a==b&&(u[0]-'0')*10+u[1]-'0'==(v[0]-'0')*10+v[1]-'0'){
		if(u[2]=='F'||u[2]=='D'){
			if(v[2]=='F'||v[2]=='D'){
				cout<<1;
			} else {
				cout<<0;
			}
		} else if (u[2]=='B'){
			if(v[2]=='C'||v[2]=='A'){
				cout<<1;
			} else {
				cout<<0;
			}
		} else if (u[2]=='C'||u[2]=='A'){
			if(v[2]=='B'){
				cout<<1;
			} else {
				cout<<0;
			}
		} else {
			cout<<0;
		}
	} else {
		cout<<0;
	}
	return 0;
}
