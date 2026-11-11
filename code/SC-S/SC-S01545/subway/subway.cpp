#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N=5e2+5;
const int M=5e5+5;
struct node{
	int v,w;
};
int tid,n,m,d,q;
int nde;
int w[M];
int dis[N][N];
vector<node>tj[M];
void add(int u,int v,int w){
	dis[u][v]=min(dis[u][v],w);
	dis[v][u]=min(dis[v][u],w);
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>tid>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	nde=m;
	rep(i,1,n){
		rep(j,1,n){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	rep(i,1,n){
		int k;
		cin>>k;
		rep(j,1,k){
			int a,t;
			cin>>a>>t;
			tj[a].pb({i,t});
		}
	}	
	rep(i,1,m){
		for(node &u:tj[i]){
			for(node &v:tj[i]){
				int uv=u.v;
				int vv=v.v;
				int uw=u.w;
				int vw=v.w;
				if(uv==vv)continue;
				add(uv,vv,uw+vw);
			}
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for(node &i:tj[u]){
			for(node &j:tj[v]){
				int uv=i.v;
				int uw=i.w;
				int vv=j.v;
				int vw=j.w;
				ans=min(ans,dis[uv][vv]+uw+vw);
			}
		} 
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
