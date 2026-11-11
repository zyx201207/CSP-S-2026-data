#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a[505][20005],t[505][20005],w[500005],k[505];
vector<array<int,2>>e[20005];
vector<array<int,2>>g[20005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(n<=500&&m<=1000){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				g[a[i][j]].push_back({i,j});
			}
		}
		vector<int>ans(q+1,0);
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y; 
			e[x].push_back({y,i});
		}
		for(int i=1;i<=m;i++){
			if(!e[i].size()) continue;
			vector<int>dis(m+1,0);
			for(int j=1;j<=m;j++){
				dis[j]=1e18;
			}
			dis[i]=w[i];
			queue<array<int,2>>q;
			q.push({i,0});
			while(q.size()){
				auto x=q.front();
				q.pop();
				int u=x[0],y=x[1];
				for(auto o:g[u]){
					int v=o[0],nu=o[1];
					for(int j=1;j<=k[v];j++){
						if(dis[a[v][j]]>dis[u]+t[v][nu]+t[v][j]){
							dis[a[v][j]]=dis[u]+t[v][nu]+t[v][j];
							q.push({a[v][j],v});
						}
					}
				}
			}
			for(auto x:e[i]){
				ans[x[1]]=dis[x[0]]+w[x[0]];
			}
		}
		for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';	
	}
	else{
		int tt;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int aa;
				cin>>a[i][j]>>tt;
				g[a[i][j]].push_back({i,j});
			}
		}
		vector<int>ans(q+1,0);
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y; 
			e[x].push_back({y,i});
		}
		for(int i=1;i<=m;i++){
			if(!e[i].size()) continue;
			vector<int>dis(m+1,0);
			for(int j=1;j<=m;j++){
				dis[j]=1e9;
			}
			dis[i]=0;
			queue<array<int,2>>q;
			q.push({i,0});
			while(q.size()){
				auto x=q.front();
				q.pop();
				int u=x[0],y=x[1];
				for(auto o:g[u]){
					int v=o[0],nu=o[1];
					for(int j=1;j<=k[v];j++){
						if(dis[a[v][j]]>dis[u]+(y!=0&&y!=v)){
							dis[a[v][j]]=dis[u]+(y!=0&&y!=v);
							q.push({a[v][j],v});
						}
					}
				}
			}
			for(auto x:e[i]){
				ans[x[1]]=dis[x[0]]*tt*2+2+w[x[0]]+w[i];
			}
		}
		for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';	
	}
	return 0;
}
