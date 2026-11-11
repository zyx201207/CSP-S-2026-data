#include <bits/stdc++.h>
using namespace std;
int c,T,n,k,i,j,a[310],dis[310][310],vis[310],v[310][310],d,x,y,sum[310][310],
ans;
vector<int> f[310];
void dij(int x){
	int fx,fy,sx,i;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	while(q.size()) q.pop();
	memset(dis[x],127,sizeof(dis[x]));
	memset(vis,0,sizeof(vis));
	dis[x][x]=0;
	q.push({0,x});
	while(q.size()){
		fx=q.top().second;fy=dis[x][fx];q.pop();
		if(vis[fx]) continue;vis[fx]=1;
		for(i=0;i<f[fx].size();i++){
			sx=f[fx][i];
			if(fy+1<dis[x][sx])
				dis[x][sx]=fy+1,q.push({dis[x][sx],sx});
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		memset(v,0,sizeof(v));
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)
					f[i].push_back(j),f[j].push_back(i);
		for(i=1;i<=n;i++) dij(i);
		for(i=1;i<=n/2;i++)
			for(j=0;j<f[i].size();j++){
				x=f[i][j];
				for(k=0;k<f[x].size();k++){
					y=f[x][k];
					if(i!=y)
						if(dis[i][y]==dis[i][x]+dis[x][y]){
							cout<<i<<" "<<y<<"\n";
							if(x!=v[i][y]){
								if(v[i][y]!=0) sum[i][y]++;
								v[i][y]=x;
							}
						}
				}
			}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(sum[i][j]>=2) ans++;
		cout<<ans<<"\n";
	}
}