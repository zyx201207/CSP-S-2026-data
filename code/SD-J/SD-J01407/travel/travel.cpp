#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pal pair<ll,ll>
#define fi first
#define se second
const ll N=3e5+10;
const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
string a,b,c,d;
void Solve(){
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<"000";
		return;
	}
	ll x=(b[2]>='A'&&b[2]<='C'?1:0),y=(d[2]>='A'&&d[2]<='C'?1:0);
	if(x==y){
		cout<<1;
	}else{
		cout<<"00";
		return;
	}
	if(x==1){
		if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))cout<<0;
		else cout<<1;
	}else cout<<1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
