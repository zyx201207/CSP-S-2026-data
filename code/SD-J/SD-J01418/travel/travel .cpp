#include<bits/stdc++.h>
using namespace std;
/*====================*/
using lnt=long long;
/*====================*/
/*====================*/
/*====================*/
void Solve(){
	string a,b,c,d; cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<'\n';
		return;
	}
	cout<<"1";
	/*====================*/
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"000"<<'\n';
		return;
	}
	cout<<"1";
	/*====================*/
	if(bool(b[2]>'C')!=bool(d[2]>'C')){
		cout<<"00"<<'\n';
		return;
	}
	cout<<"1";
	/*====================*/
	if(b[2]>'C'){
		cout<<"1"<<'\n';
		return;
	}
	if(b[2]=='B'||d[2]=='B'){
		cout<<"1"<<'\n';
		return;
	}
	cout<<"0"<<'\n';
	return;
}
/*====================*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1; //cin>>T;
	while(T--) Solve();
	return 0;
}
