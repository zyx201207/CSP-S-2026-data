#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pal pair<ll,ll>
#define fi first
#define se second
const ll N=3e5+10;
const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n;
pal a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>a[i].fi>>x;
		a[i].se=x-'a';
	}
	ll l=1,r=n,cnt=0;
	while(l<r){
		ll x=min(a[l].fi,a[r].fi);
		if(a[l].se!=a[r].se)cnt+=x;
		a[l].fi-=x,a[r].fi-=x;
		if(a[l].fi==0)l++;
		if(a[r].fi==0)r--;
	}
	if(l==r)a[l].fi=0;
	cout<<cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
