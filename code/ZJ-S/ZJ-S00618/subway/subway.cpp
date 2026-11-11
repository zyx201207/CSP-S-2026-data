#include<bits/stdc++.h>
using namespace std;
int dis[500010],i,j,c,d,T,vis[500010],a[500010],x,y,n,m,k,t;
vector<int>f[501010],g[501010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
struct no{
	int x,t;
}b[500010];
bool cmp(no q,no h){
	return q.x<h.x;
}
void dij(int x){
	int fx,i,fy,j,sx,sg,sxx,sgg;
	memset(vis,0,sizeof(vis));
	memset(dis,127,sizeof(dis));
	dis[x]=a[x];q.push({0,x});
	while(!q.empty()){
		fx=q.top().second;
		fy=dis[fx];
		q.pop();
		if(vis[fx]==1)continue;
		vis[fx]=1;
		for(i=0;i<f[fx].size();i++){
			sx=f[fx][i];sg=fy+g[fx][i];
			for(j=0;j<f[sx].size();j++){
				sxx=f[sx][j];sgg=sg+g[sx][j];
				if(dis[sxx]>sgg)dis[sxx]=sgg,q.push({sgg,sxx});
			}
		}
	}
}
 main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(i=1;i<=m;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++)cin>>b[j].x>>b[j].t;
		sort(b+1,b+1+k,cmp);
		for(j=1;j<=k;j++)
			if(b[j].x!=b[j-1].x)
				x=b[j].x,t=b[j].t,f[i+m].push_back(x),f[x].push_back(i+m),g[i+m].push_back(t),g[x].push_back(t);
	}
	while(T--){
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+a[y]<<"\n";
	}
}
