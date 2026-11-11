#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pal pair<ll,ll>
#define fi first
#define se second
const ll N=5e5+10;
const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f;
ll n,m,a[N],b[N],ma=0,c[N],e[N],f[N],asdf;
vector<ll> d[N];
ll dfs(ll x){
	ll cnt=1,xx=d[x].size();
	for(int i=0;i<xx;i++){
		cnt+=dfs(d[x][i]);
	}
	f[x]=cnt;
	return cnt;
} 
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(int i=1;i<n;i++){
		if(i!=b[a[i]])d[b[a[i]]].push_back(i);
		else d[i+1].push_back(i);
	}
	asdf=dfs(n);
	for(int i=1;i<=m;i++)cout<<f[b[i]]<<" ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
