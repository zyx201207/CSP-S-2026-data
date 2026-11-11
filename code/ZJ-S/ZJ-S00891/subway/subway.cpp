#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e6+5,M=5e5+5;
int c,n,m,d,q,st,ed,ans,a[M],t[M],vis[N];
vector<PII>G[N];
void dfs(int now,int fa,int time){
	if(now==ed){
		ans=min(ans,time);
		return;
	}
	for(auto nex:G[now]){
		if(nex.fi==fa||vis[nex.fi]||(nex.fi<=m&&nex.fi!=ed))
			continue;
		time+=nex.se;
		vis[nex.fi]=1;
		dfs(nex.fi,now,time);
		time-=nex.se;
		vis[nex.fi]=0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		G[i].push_back({m+i,w});
		G[m+i].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[j];
		for(int j=1;j<k;j++){
			G[(i+1)*m+a[j]].push_back({(i+1)*m+a[j+1],0});
			G[(i+1)*m+a[j+1]].push_back({(i+1)*m+a[j],0});
			G[(i+1)*m+a[j]].push_back({m+a[j],t[j]});
			G[m+a[j]].push_back({(i+1)*m+a[j],t[j]});
		}
		G[(i+1)*m+a[k]].push_back({m+a[k],t[k]});
		G[m+a[k]].push_back({(i+1)*m+a[k],t[k]});
		G[(i+1)*m+a[k]].push_back({m+a[k],t[k]});
	}
	while(q--){
		cin>>st>>ed;
		ans=LLONG_MAX;
		memset(vis,0,sizeof vis);
		vis[st]=1;
		dfs(st,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
