#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> > v[500005];
int c,n,m,d,q,w[500005],t[500005][21],ans,s,e;
bool visited[500005];
void dfs(int d,int sum){
	if(d==e){ans=min(ans,sum);return;}
	for(auto x:v[d]){
		int u=x.first;
		if(!visited[u]){
			visited[u]=1;
			dfs(x.first,sum+x.second);
			visited[u]=0;
		}
	}
}
signed main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1,k,a1,a2;i<=n;i++){
		scanf("%lld%lld",&k,&a1);scanf("%lld%lld",&t[i][a1],&a2);scanf("%lld",&t[i][a2]);
		v[a1].push_back({a2,t[i][a1]+t[i][a2]});v[a2].push_back({a1,t[i][a1]+t[i][a2]});
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&s,&e);
		ans=1e18;
		dfs(s,w[s]+w[e]);
		cout<<ans<<endl;
	}
	return 0;
}