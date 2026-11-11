#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5,M=505,INF=1e15;
int c,n,m,d,q,k[M];
long long dis[M][M],w[N];
struct node{
	long long v,w;
};
vector<node> G[N];
vector<long long> a[N];
unordered_map<long long,unordered_map<long long,long long>> t;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long ls;
			cin>>ls;
			a[i].push_back(ls);
			cin>>t[i][ls];
			G[ls].push_back({i,t[i][ls]});
		}
	}
	for(int i=0;i<M;i++) for(int j=0;j<M;j++) dis[i][j]=INF;
	for(int i=0;i<M;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int len=G[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				long long va=G[i][j].v,wa=G[i][j].w,vb=G[i][k].v,wb=G[i][k].w;
				if(va==vb) continue;
				dis[va][vb]=min(dis[va][vb],wa+wb);
				dis[vb][va]=min(dis[vb][va],wa+wb);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]==INF||dis[k][j]==INF) continue;
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int p=0;p<q;p++){
		int u,v;
		cin>>u>>v;
		long long ans=INF;
		int lenu=G[u].size(),lenv=G[v].size();
		for(int i=0;i<lenu;i++) for(int j=0;j<lenv;j++){
			int va=G[u][i].v,vb=G[v][j].v;
			if(t[va][u]==0||t[vb][v]==0) continue;
			ans=min(ans,dis[va][vb]+t[va][u]+t[vb][v]);
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
