#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int c,n,m,d,q,w[N],a[505][1005],dep[N],vis[N],hx[N],t[505][1005];
vector<pair<int,int> >edge[N];
void dfs(int u){
	vis[u]=1;
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i].first;
		if(vis[v]) continue;
		dep[v]=dep[u]+1;
		dfs(v);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	if(c==7||c==8||c==9||c==10||c==11){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>a[i][j]>>t[i][j];
				hx[a[i][j]]=i;
				if(j>=2){
					edge[a[i][j]].push_back({a[i][j-1],i});
					edge[a[i][j-1]].push_back({a[i][j],i});
				}
			}
			if(i>=2){
				edge[a[i][0]].push_back({a[i-1][1],i-1});
				edge[a[i-1][1]].push_back({a[i][0],i});
			}
		}
		dfs(1);
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			ll ans=0;
			ans=w[x]+w[y];
			if(dep[x]>dep[y]) swap(x,y);
			queue<pair<int,int> >q;
			q.push({x,hx[x]});
			while(!q.empty()){
				int u=q.front().first,l=q.front().second;
				q.pop();
				if(u==y){
					ans+=t[l][u];
					break;
				}
				if(u==x) ans+=t[l][u];
				for(int i=0;i<edge[u].size();i++){
					int v=edge[u][i].first,nn=edge[u][i].second;
					if(dep[v]<dep[u]) continue;
					if(u!=x){
						ans+=t[l][v]+t[hx[v]][v];
					}
					q.push({v,hx[v]});
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
