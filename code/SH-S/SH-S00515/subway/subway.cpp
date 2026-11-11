#include <bits/stdc++.h>
using namespace std;
const long long INF=1000000000000000;
int fll,n,m,k,qy,u,v,a;
long long x[500010],b,w,d[510][510],ans;
bool vis[510];
vector<long long> f[500010],t[500010];
typedef pair<long long,long long> T;
vector<T> g[510];
priority_queue<T,vector<T>,greater<T> > pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&fll,&n,&m,&k,&qy);
	for(int i=1;i<=m;++i) scanf("%lld",&x[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			scanf("%d",&a);
			f[a].push_back(i);
			scanf("%lld",&b);
			t[a].push_back(b);
		}
	}
	for(u=1;u<=m;++u){
		for(int i=0;i<f[u].size();++i){
			for(int j=i+1;j<f[u].size();++j){
				a=f[u][i];
				b=f[u][j];
				long long ta=t[u][i],tb=t[u][j];
				g[a].push_back(make_pair(b,ta+tb));
				g[b].push_back(make_pair(a,ta+tb));
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) d[i][j]=INF;
		for(int j=1;j<=n;++j) vis[j]=false;
		d[i][i]=0;
		pq.push(make_pair(0,i));
		while(!pq.empty()){
			u=pq.top().second;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=true;
			for(int j=0;j<g[u].size();++j){
				v=g[u][j].first;
				w=g[u][j].second;
				if(d[i][u]+w<d[i][v]){
					d[i][v]=d[i][u]+w;
					pq.push(make_pair(d[i][v],v));
				}
			}
		}
	}
	for(int i=1;i<=qy;++i){
		scanf("%d %d",&u,&v);
		ans=INF;
		for(int j=0;j<f[u].size();++j){
			for(int k=0;k<f[v].size();++k){
				ans=min(ans,x[u]+t[u][j]+d[f[u][j]][f[v][k]]+t[v][k]+x[v]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}/*
设m_d为题目中的d;
对于每个站厅,先枚举经过它的每条地铁线路,根据往返时间建边,时间复杂度:O(m*m_d*m_d);
求地铁线路两两之间的最短路,时间复杂度<=O(n*n*n);
枚举两个站厅(u,v)的所有地铁线路(f[u][i],f[v][j]),答案为x[u]+t[u][i]+d[f[u][i]][f[v][j]]+t[v][j]+x[v]
,时间复杂度:O(qy*m_d*m_d);
*/
