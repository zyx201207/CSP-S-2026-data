#include<bits/stdc++.h>
using namespace std;
/*====================*/
const int N=1e5+10;
const int M=1e5+10;
/*====================*/
const int INF=0x3f3f3f3f;
const int MOD=998244353;
/*====================*/
string a,b,c,d; 
/*====================*/
void Solve(){
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return;
	}
	cout<<"1";
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<"000";
		return;
	}
	int x,y;
	if(b[2]=='A')x=1;
	if(b[2]=='B')x=2;
	if(b[2]=='C')x=3;
	if(b[2]=='D')x=4;
	if(b[2]=='F')x=5;
	if(d[2]=='A')y=1;
	if(d[2]=='B')y=2;
	if(d[2]=='C')y=3;
	if(d[2]=='D')y=4;
	if(d[2]=='F')y=5;
	if((x<=3&&y<=3)||(x>3&&y>3)){
		cout<<1;
	}else{
		cout<<"00";
		return;
	}
	if(abs(x-y)==1)cout<<1;
	else cout<<0;
}
/*====================*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}

