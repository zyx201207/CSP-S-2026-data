#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d,T,t,k,s,ma,x,y,i,j,fx,sx,a[500010],dis[500010],vis[500010],dij[1010][1010];
vector<int>f[500010],g[500010];
queue<int>q;
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>n>>m>>d>>T;
	for(i=1;i<=m;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>x>>y;
			f[x].push_back(i+m);
			f[i+m].push_back(x);
			g[x].push_back(y);
			g[i+m].push_back(y);
		}
	}
	while(T--){
		cin>>x>>y;
		for(i=1;i<=n+m;i++)dis[i]=1e18,vis[i]=0;
		q.push(x);
		vis[x]=1;dis[x]=0;
		while(!q.empty()){
			fx=q.front();
			for(i=0;i<f[fx].size();i++){
				sx=f[fx][i];
				if(dis[sx]>dis[fx]+g[fx][i]){
					dis[sx]=dis[fx]+g[fx][i];
					if(!vis[sx]){
						vis[sx]=1;
						q.push(sx);
					}
				}
			}
			q.pop();vis[fx]=0;
		}
		cout<<dis[y]+a[x]+a[y]<<"\n";
	}
	return 0;
}