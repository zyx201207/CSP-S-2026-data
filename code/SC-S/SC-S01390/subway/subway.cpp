#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q,cnt;
vector <ll> w,vis,trans,dist;
struct edge{
	int l,tm;
};
vector<vector<edge> >sta;
vector<vector<int> > line;//stations that each line has 
ll dijkstra(int s,int t){
	dist.resize(n+1,LONG_LONG_MAX);
	for(int i=0;i<sta[s].size();++i){
		dist[sta[s][i].l]=sta[s][i].tm;
	}
	vis.resize(n+1,0);
	for(int x=1;x<=n;++x){
		ll p,disp=LONG_LONG_MAX;
		for(int i=1;i<=n;++i){
			if(dist[i]<disp&&!vis[i]){
				p=i,disp=dist[i];
			}
		}
		vis[p]=1;
		//printf("%d:%d\n",p,disp);
		for(int i=0;i<line[p].size();++i){
			if(sta[line[p][i]].size()>1){//中转点： line[p][i].a->pq
				int pq=line[p][i];
				int br;
				for(int j=0;j<sta[pq].size();++j){
					if(sta[pq][j].l==p){
						br=j;
						break;
					}
				}
				for(int j=0;j<sta[pq].size();++j){
					int nl=sta[pq][j].l;
					if(!vis[nl]&&dist[nl]>disp+sta[pq][j].tm+sta[pq][br].tm){
						dist[nl]=disp+sta[pq][j].tm+sta[pq][br].tm;
					} 
				}
			}
		}
	}
	ll res=LONG_LONG_MAX;
	for(int i=0;i<sta[t].size();++i){
		res=min(res,dist[sta[t][i].l]+sta[t][i].tm);
	}
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	//cout<<n<<m;
	w.resize(m+1);
	line.resize(n+1);
	sta.resize(m+1);
	for(int i=1;i<=m;++i){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			int a,t;
			scanf("%d%d",&a,&t);
			line[i].push_back(a);
			sta[a].push_back({i,t});
		}
	}
	for(int i=1;i<=q;++i){
		int s,t;
		scanf("%d%d",&s,&t);
		ll ans=w[s]+w[t];
		ans+=dijkstra(s,t);
		printf("%lld\n",ans);
	}
} 