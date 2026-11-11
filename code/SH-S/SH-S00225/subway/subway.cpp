#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+33,INF=0x3f3f3f3f;
long long c,n,m,d,q,k,w[maxn],a[maxn],t[maxn],st,ed,ans;
vector< pair<int,int> > e[maxn];
bool vis[maxn];
void dfs(int u,long long s){
	if (u==ed){
		ans=max(ans,s);
		return ;
	}
	vis[u]=1;
	for (int i=0;i<e[u].size();i++){
		pair<int,int> v=e[u][i];
		if (!vis[v.first]) dfs(v.first,s+v.second);
	}
}
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for (int g=1;g<j;g++){
				e[a[g]].push_back({a[j],t[g]+t[j]});
				e[a[j]].push_back({a[g],t[g]+t[j]});
			}
		}
	}
	while (q--){
		cin>>st>>ed;
		ans=INF;
		dfs(st,0);
		ans+=w[st]+w[ed];
		cout<<ans<<'\n';
	}
	return 0;
}
