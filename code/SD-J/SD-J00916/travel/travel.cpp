#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else{
		cout<<"000"; 
		return 0;
	}
	bool f1=0;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
			cout<<1;
			f1=1;
		}
	}
	if(b[2]=='D'||b[2]=='E'){
		if(d[2]=='D'||d[2]=='E'){
			cout<<1;
			f1=1;
		}
	}
	if(!f1){
		cout<<"00";
		return 0;
	}
	bool f2=0;
	if(f1){
		if(b[2]=='A'){
			if(d[2]=='B') {
				f2=1;
				cout<<1;
			}
		}
		if(b[2]=='B'){
			if(d[2]=='A'||d[2]=='C') {
				f2=1;
				cout<<1;
			}
		}
		if(b[2]=='C'){
			if(d[2]=='B') {
				f2=1;
				cout<<1;
			}
		}
		if(b[2]=='D'){
			if(d[2]=='E') {
				f2=1;
				cout<<1;
			}
		}
		if(b[2]=='E'){
			if(d[2]=='D') {
				f2=1;
				cout<<1;
			}
		}
	}
	if(!f2) cout<<0;
	return 0;
}

