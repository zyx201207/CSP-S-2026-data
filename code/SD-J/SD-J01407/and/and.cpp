#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pal pair<ll,ll>
#define fi first
#define se second
const ll N=3e5+10;
const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f;
ll n,m,a[N],t,e[N],tt,cnt=0;
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	t=n;
	for(int i=29;i>=0;i--){
		tt=0;
		for(int j=1;j<=t;j++){
			if(a[j]&(1<<i))e[++tt]=a[j];
		}
		if(tt>=m){
			cnt+=(1<<i);
			t=tt;
			for(int j=1;j<=t;j++)a[j]=e[j];
		}
		tt=0;
	}
	cout<<cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
