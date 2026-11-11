#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define mkp make_pair
const int V=5e5+550,E=1e6+50,N=505,M=5e5+50;
vector<pli>vec[M];
ll ans[M];
int h[V],nxt[E],to[E],w[E],idx;
int cnt[V],Cnt[V];
int n,m;
void add(int u,int v,int W){
	nxt[++idx]=h[u],h[u]=idx,to[idx]=v,w[idx]=W;
	nxt[++idx]=h[v],h[v]=idx,to[idx]=u,w[idx]=W;
	++cnt[u],++cnt[v];
}
priority_queue<pli,vector<pli>,greater<pli> >que;
ll dis[V];
int Dis[M];
ll _Dis[N][N];
void dijkstra(int s){
	for(int i=1;i<=n+m;++i){
		dis[i]=1e18;
		Cnt[i]=cnt[i];
	}
	dis[s]=0;
	que.push(mkp(0,s));
	while(!que.empty()){
		int u=que.top().second;
		ll d=que.top().first;
		que.pop();
		if(dis[u]<d)continue;
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			ll c=w[i];
			--Cnt[v];
			--Cnt[u];
			if(dis[v]>d+c){
				dis[v]=d+c;
				if(Cnt[v])que.push(mkp(dis[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,Q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;++i)scanf("%d",&Dis[i]);
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		while(k--){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,m+i,y);
			vec[x].push_back(mkp(y,i));
		}
	}
	for(int i=1;i<=n;++i){
		dijkstra(m+i);
		for(int j=1;j<=n;++j){
			_Dis[i][j]=dis[m+j];
		}
	}
	for(int i=1;i<=Q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(int p=0;p<vec[x].size();++p){
			for(int q=0;q<vec[y].size();++q){
				ll res=vec[x][p].first+vec[y][q].first+_Dis[vec[x][p].second][vec[y][q].second];
				ans=min(ans,res);
			}
		}
		ans+=Dis[x];
		ans+=Dis[y];
		printf("%lld\n",ans);
	}
	return 0;
}

