#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int u,v;
vector<int>edge[1000001];
long long ans,g[11],mx,ks;
void dfs(int now,int from,long long l){
	if(g[now]&&(!g[from]||now==1))ks++;
	if(ks>2){mx=1e18;return ;}
	if(!g[now])mx=max(mx,l);
	else l=0;
	for(int i=0;i<edge[now].size();i++){
		if(edge[now][i]==from)continue;
		dfs(edge[now][i],now,l+1);
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)edge[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(c<=3){
			ans=1e18;
			for(int i=0;i<(1<<n);i++){
				ks=0;
				mx=0;
				int len=0;
				for(int j=1;j<=n;j++){
					g[j]=0;
				}
				for(int j=1;j<=n;j++){
					if((i>>(j-1))&1){g[j]=1;len++;}
				}
				if(len!=k)continue;
				dfs(1,1,1);
				ans=min(ans,mx);
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}