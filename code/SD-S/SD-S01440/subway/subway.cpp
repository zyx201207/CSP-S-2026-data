#include<bits/stdc++.h>
using namespace std;
const int N=510,M=30005; 
int c,n,m,d,q,w[N],a[N][M],t[N][M],x[N],sum[25][N][M],ans[M],vis[M],ll[1001][1001];
vector<int> e[M],h[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
void di(int r){
	while(!p.empty()){
		auto k=p.top();
		p.pop();
		if(vis[k.second]==1){
			continue;
		}
		vis[k.second]=1;
		for(int u:e[k.second]){
			for(int v:h[u]){
				if(ans[v]>k.first+sum[u][k.second][v]&&e[v].size()>1||v==r&&ans[v]>k.first+sum[u][k.second][v]){
					ans[v]=k.first+sum[u][k.second][v];
					p.push({ans[v],v});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=x[i];j++){
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]].push_back(i);
		}
		for(int j=1;j<=x[i];j++){
			for(int k=j+1;k<=x[i];k++){
				sum[i][a[i][j]][a[i][k]]=sum[i][a[i][k]][a[i][j]]=t[i][j]+t[i][k];
				ll[a[i][j]][a[i][k]]=ll[a[i][k]][a[i][j]]=i;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int u : e[i]){
			h[u].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
			for(int i=1;i<=m;i++){
				ans[i]=1e9;
			}
			ans[l]=w[l];
			p.push({ans[l],l});
			di(r);
			cout<<ans[r]+w[r]<<"\n";
			for(int i=1;i<=m;i++){
				ans[i]=0;
				vis[i]=0;
			}
			while(!p.empty()){
				p.pop();
			}
	}
	return 0;
}

