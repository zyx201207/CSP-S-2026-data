#include<bits/stdc++.h>
using namespace std;
string ca,cb,za,zb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>za>>cb>>zb;
	for(int i=0;i<2;i++){
		if(ca[i]!=cb[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<2;i++){
		if(za[i]!=zb[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(za[2]=='A'||za[2]=='B'||za[2]=='C'){
		if(zb[2]=='D'||zb[2]=='F'){
			cout<<"00";
			return 0;
		}
	}
	if(za[2]=='D'||za[2]=='F'){
		if(zb[2]=='A'||zb[2]=='B'||zb[2]=='C'){
			cout<<"00";
			return 0;
		}
	}
	cout<<"1";
	if(za[2]=='A'){
		if(zb[2]!='B'){
			cout<<"0";
			return 0;
		}
	}
	if(za[2]=='B'){
		if(zb[2]!='A'||zb[2]!='C'){
			cout<<"0";
			return 0;
		}
	}
	if(za[2]=='C'){
		if(zb[2]!='B'||zb[2]!='D'){
			cout<<"0";
			return 0;
		}
	}
	if(za[2]=='D'){
		if(zb[2]!='C'||zb[2]!='E'){
			cout<<"0";
			return 0;
		}
	}
	if(za[2]=='E'){
		if(zb[2]!='D'){
			cout<<"0";
			return 0;
		}
	}
	cout<<"1";
	return 0;
}
