#include<iostream>
#include<vector>
using namespace std;
#define N 501
#define M 500001
#define I 114514114514114514LL
using int64=long long;
int c,n,m,d,q,w[M],
i,j,u,v,k,k2;
int64 dis[N][N],ans;
struct E{
	int v,k;
};
vector<E>nxt[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;++i)cin>>w[i];
	for(i=1;i<=n;++i){
		cin>>j;
		while(j--){
			cin>>v>>k;
			nxt[v].push_back({i,k});
		}for(j=1;j<=n;++j){
			if(i!=j)dis[i][j]=I;
		}
	}for(i=1;i<=m;++i){
		v=nxt[i].size();
		for(j=0;j<v;++j){
			for(k=j+1;k<v;++k){
				int64&di1=dis[nxt[i][j].v][nxt[i][k].v];
				int64&di2=dis[nxt[i][k].v][nxt[i][j].v];
				di1=di2=min(di1,nxt[i][j].k+nxt[i][k].k+0LL);
			}
		}
	}for(k=1;k<=n;++k){
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}while(q--){
		cin>>u>>v;
		k=nxt[u].size();
		k2=nxt[v].size();
		ans=I;
		for(i=0;i<k;++i){
			for(j=0;j<k2;++j){
				ans=min(ans,nxt[u][i].k+nxt[v][j].k+dis[nxt[u][i].v][nxt[v][j].v]);
			}
		}cout<<ans+w[u]+w[v]<<'\n';
	}return 0;
}