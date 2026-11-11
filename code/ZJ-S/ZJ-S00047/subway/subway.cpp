#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,T;
ll w[500005];
ll k[505];
struct node{
	int v;
	ll w;
};
vector<node> g[510005];
ll dis[505][505];
int vis[505];
void dij(int s){
	for(int i=1;i<=n;i++){
		dis[s][i]=inf;
		vis[i]=0;
	}
	dis[s][s]=0;
	for(int t=1;t<=n;t++){
		int u=0,v,v2;
		ll d=inf,w,w2;
		for(int i=1;i<=n;i++){
			if(vis[i]==0&&dis[s][i]<d){
				u=i;
				d=dis[s][i];
			}
		}
		vis[u]=1;
		for(int i=0;i<k[u];i++){
			v=g[u][i].v,w=g[u][i].w;
			for(int j=0;j<g[v].size();j++){
				v2=g[v][j].v,w2=w+g[v][j].w;
				//cout<<u<<"->"<<v-n<<"->"<<v2<<' '<<w2<<'\n';
				if(vis[v2]==0&&dis[s][v2]>dis[s][u]+w2){
					dis[s][v2]=dis[s][u]+w2;
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//don't forget to delete!!!!!
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int id;
		ll t;
		for(int j=1;j<=k[i];j++){
			cin>>id>>t;
			g[id+n].push_back({i,t});
			g[i].push_back({id+n,t});
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		/*
		for(int j=1;j<=n;j++){
			cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
		}
		*/
	}
	while(T--){
		int xr,yr;
		cin>>xr>>yr;
		ll ans=inf;
		//cout<<"Yes\n";
		for(int i=0;i<g[xr+n].size();i++){
			int x=g[xr+n][i].v;
			ll w1=g[xr+n][i].w;
			for(int j=0;j<g[yr+n].size();j++){
				int y=g[yr+n][j].v;
				ll w2=g[yr+n][j].w;
				//cout<<x<<' '<<y<<' '<<w1<<' '<<w2<<'\n';
				ans=min(ans,dis[x][y]+w1+w2);
			}
		}
		cout<<ans+w[xr]+w[yr]<<'\n';
	}
	return 0;
}