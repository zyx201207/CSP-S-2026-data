#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,v[500010],k,a,t,b;
long long dis[510][510],ans;
vector<pair<int,int>>f[500010];
void read(int &a){
	a=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')a=a*10+(c^48),c=getchar();
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int w=1;w<=m;w++)read(v[w]);
	for(int w=1;w<=n;w++){
		for(int x=1;x<=n;x++)dis[w][x]=1e18;
		dis[w][w]=0,read(k);
		for(int x=1;x<=k;x++){
			read(a),read(t),f[a].push_back({w,t});
			for(int y=0;y<f[a].size();y++){
				int u=f[a][y].first;
				dis[w][u]=dis[u][w]=min(dis[u][w],(long long)t+f[a][y].second);
			}
		}
	}
	for(int y=1;y<=n;y++)for(int w=1;w<=n;w++)for(int x=1;x<=n;x++)
		dis[w][x]=min(dis[w][x],dis[w][y]+dis[y][x]);
	while(q--){
		read(a),read(b);ans=1e18;
		for(int w=0;w<f[a].size();w++)for(int x=0;x<f[b].size();x++)
			ans=min(ans,dis[f[a][w].first][f[b][x].first]+f[a][w].second+f[b][x].second+v[a]+v[b]);
		printf("%lld\n",ans);
	}
	return 0;
}
