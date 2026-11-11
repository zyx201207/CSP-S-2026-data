#include<bits/stdc++.h> 
using namespace std;
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a1>>b1>>a2>>b2;
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	if(b1[0]!=b2[0]||b1[1]!=b2[1]){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	bool f=0,k=0;
	if((b1[2]=='A'&&b2[2]=='B')||(b1[2]=='A'&&b2[2]=='C')){
		f=1;
	}
	if((b1[2]=='B'&&b2[2]=='A')||(b1[2]=='B'&&b2[2]=='C')){
		f=1;
	}
	if((b1[2]=='C'&&b2[2]=='A')||(b1[2]=='C'&&b2[2]=='B')){
		f=1;
	}
	if((b1[2]=='D'&&b2[2]=='E')||(b1[2]=='E'&&b2[2]=='D')){
		f=1;
		k=1;
	}
	if(!f){
		cout<<"00";
		return 0;
	}else{
		cout<<"1";
	}
	if(b1[2]=='A'&&b2[2]=='B'){
		k=1;
	}
	if((b1[2]=='B'&&b2[2]=='A')||(b1[2]=='B'&&b2[2]=='C')){
		k=1;
	}
	if(b1[2]=='C'&&b2[2]=='B'){
		k=1;
	}
	cout<<k;
	return 0;
}
