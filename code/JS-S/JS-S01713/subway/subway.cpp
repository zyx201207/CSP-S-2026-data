#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long LL;
typedef pair<int,LL> PIL;
typedef pair<LL,int> PLI;
const int M=5e5+10,N=510;
int C,n,m,d,p;
int way[N][M],k[N],q[M],l=0;
LL w[M],c[N][M],tdist[M];
vector<int> sta[M],g[M];
vector<PIL> jd[M];
vector<LL> val[M];
bool st[M];
priority_queue< PLI,vector<PLI>,greater<PLI> > pq;
void Dijkstra(int x,int y){
	memset(tdist,0x3f,sizeof(tdist));
	memset(st,0,sizeof(st));
	tdist[x]=0;
	pq.push({0,x});
	st[x]=1;
	while(pq.size()){
		PLI x=pq.top();
		pq.pop();
		if(st[x.s]) continue;
		st[x.s]=1;
		for(size_t i=0;i<g[x.s].size();++i){
			if(tdist[g[x.s][i]]>tdist[x.s]+val[x.s][i]){
				tdist[g[x.s][i]]=tdist[x.s]+val[x.s][i];
				pq.push({tdist[g[x.s][i]],g[x.s][i]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&p);
	for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j){
			scanf("%d%lld",&way[i][j],&c[i][j]);
			sta[way[i][j]].push_back(i);
			if(sta[way[i][j]].size()==2) q[++l]=way[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k[i];++j){
			int prev=0,now=0;
			if(sta[way[i][j]].size()>1){
				prev=now;
				now=j;
				for(int ii=prev+1;ii<now-1;++ii){
					g[way[i][ii]].push_back(way[i][ii+1]);
					g[way[i][ii+1]].push_back(way[i][ii]);
					val[way[i][ii]].push_back(0);
					g[way[i][ii+1]].push_back(0);
				}
				if(j>1) jd[way[i][j]].push_back({way[i][j-1],c[i][j-1]});
				if(j<k[i]) jd[way[i][j]].push_back({way[i][j+1],c[i][j+1]});
				if(j>1 && j<k[i]){
					g[way[i][j-1]].push_back(way[i][j+1]);
					g[way[i][j+1]].push_back(way[i][j-1]);
					val[way[i][j-1]].push_back(0);
					val[way[i][j+1]].push_back(0);
				}
			}
			prev=now,now=k[i];
			for(int ii=prev+1;ii<now;++ii){
				g[way[i][ii]].push_back(way[i][ii+1]);
				g[way[i][ii+1]].push_back(way[i][ii]);
				val[way[i][ii]].push_back(0);
				g[way[i][ii+1]].push_back(0);
			}
		}
	}
	for(int i=1;i<=l;++i){
		int x=q[i];
		for(size_t j=0;j<jd[x].size();++j){
			for(size_t ii=j+1;ii<jd[x].size();++ii){
				g[jd[x][j].f].push_back(jd[x][ii].f);
				g[jd[x][ii].f].push_back(jd[x][j].f);
				val[jd[x][j].f].push_back(jd[x][j].s+jd[x][ii].s);
				val[jd[x][ii].f].push_back(jd[x][j].s+jd[x][ii].s);
			}
		}
	}
	while(p--){
		int x,y;
		scanf("%d%d",&x,&y);
		Dijkstra(x,y);
		printf("%lld\n",tdist[y]);
	}
	return 0;
}
