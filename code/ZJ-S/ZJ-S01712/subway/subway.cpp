#include <bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr first
#define sd second
using namespace std;
namespace l_mid_r{
	const int N=5e5+5,M=505,inf=0x3f3f3f3f3f3f3f3f;
	int c,n,m,d,T,dis[M][M],wi[N],ans;
	bool done[M][M];
	vector<pr> g[M],to_x[N];
	struct node{
		int to,w;
	};
	priority_queue<node> q;
	bool operator<(const node u,const node v){
		return u.w>v.w;
	}
	void dij(int x){
		for(int i=1;i<=n;i++) dis[x][i]=inf;
		q.push({x,dis[x][x]=0}),done[x][x]=1;
		while(!q.empty()){
			node u=q.top();q.pop();
			done[x][u.to]=1;
			for(pr i:g[u.to]){
				if(done[x][i.fr]) continue;
				if(dis[x][i.fr]>dis[x][u.to]+i.sd){
					dis[x][i.fr]=dis[x][u.to]+i.sd;
					q.push({i.fr,dis[x][i.fr]});
				}
			}
		}
	}
	int main(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&T);
		for(int i=1;i<=m;i++) scanf("%lld",wi+i);
		for(int i=1;i<=n;i++){
			int x;scanf("%lld",&x);
			for(int j=1,u,v;j<=x;j++){
				scanf("%lld%lld",&u,&v);
				to_x[u].push_back({i,v});
			}
		}
		for(int i=1;i<=m;i++){
			int sz=to_x[i].size();
			pr u,v;
			for(int j=0;j<sz;j++)
				for(int k=j+1;k<sz;k++){
					u=to_x[i][j],v=to_x[i][k];
					g[u.fr].push_back({v.fr,u.sd+v.sd});
					g[v.fr].push_back({u.fr,u.sd+v.sd});
				}
		}
		for(int i=1;i<=n;i++) dij(i);
		//~ for(int i=1;i<=n;i++){
			//~ for(int j=1;j<=n;j++)
				//~ printf("%lld %lld %lld\n",i,j,dis[i][j]);
		//~ }
		while(T--){
			ans=inf;
			int s,t;scanf("%lld%lld",&s,&t);
			for(pr i:to_x[s])
				for(pr j:to_x[t])
					ans=min(ans,wi[s]+wi[t]+j.sd+i.sd+dis[i.fr][j.fr]);
			printf("%lld\n",ans);
		}
		return 0;
	}
}
signed main(){return l_mid_r::main();}
//~ 0 3 7 20 2
//~ 8 3 6 1 7 2 9
//~ 3 1 4 2 5 5 100
//~ 3 2 6 3 1 7 2
//~ 4 3 2 5 100 4 6 6 7
//~ 1 6
//~ 2 3

