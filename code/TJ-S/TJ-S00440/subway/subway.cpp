#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000;
ll c,n,m,d,q,w[N],mn=INT_MAX,ans[N][N],cnt[N];
vector<pair<ll,ll> >g[N];
int dfs(ll x,ll y,ll tm,ll fa){
	cnt[x]=1;
	if(x==y)min(ans[x][y],tm);
	for(auto v:g[x]){
		if(v.first==fa or cnt[v.first])continue;
		dfs(v.first,y,tm+v.second,x);
		cnt[v.first]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			ll num,tm;
			scanf("%lld%lld",&num,&tm);
			g[i].push_back({num,tm});
			
		}
	}for(int i=1;i<=q;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		dfs(x,y,0,0);
		printf("%lld\n",w[x]+ans[x][y]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

