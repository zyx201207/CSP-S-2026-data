#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=5e5+5,MAXM=500+5,INF=1e18;
ll ID,n,m,K,Q,c[MAXN],dis[MAXM][MAXM];
struct vec{
	ll x,y;
}vru;
vector<vec>a[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>ID>>n>>m>>K>>Q;
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		ll len;
		cin>>len;
		for(int j=1;j<=len;j++){
			ll x,y;
			cin>>x>>y;
			vru.x=i,vru.y=y;
			a[x].push_back(vru);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=INF;
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			ll x=a[i][j].x,y=a[i][j].y;
			for(int k=j+1;k<a[i].size();k++){
				ll xx=a[i][k].x,yy=a[i][k].y;
				dis[x][xx]=dis[xx][x]=min(dis[x][xx],y+yy);
			}
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=Q;i++){
		ll u,v,re=INF;
		cin>>u>>v;
		if(u==v){
			cout<<0<<'\n';
			continue;
		}
		for(int j=0;j<a[u].size();j++){
			ll x=a[u][j].x,y=a[u][j].y;
			for(int k=0;k<a[v].size();k++){
				ll xx=a[v][k].x,yy=a[v][k].y;
				re=min(re,dis[x][xx]+y+yy);
			}
		}
		re+=c[u]+c[v];
		cout<<re<<'\n';
	}
	return 0;
}