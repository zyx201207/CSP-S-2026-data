#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
unsigned c,n,m,d,q,k,a,t,x,y;
unsigned w[1<<20];
std::vector<std::pair<unsigned,unsigned>>v[1<<20];
unsigned adj[1<<9][1<<9];
unsigned edge_cnt;
unsigned long long dist[1<<9][1<<9];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%u%u%u%u%u",&c,&n,&m,&d,&q);
	for(unsigned i=1;i<=m;++i)
		scanf("%u",w+i);
	for(unsigned i=1;i<=n;++i){
		scanf("%u",&k);
		while(k--){
			scanf("%u%u",&a,&t);
			v[a].emplace_back(i,t);
		}
	}
	memset(adj,-1,sizeof(adj));
	for(unsigned i=1;i<=m;++i)
		for(const auto &s:v[i])
			for(const auto &e:v[i])
				if(adj[s.first][e.first]>s.second+e.second)
					adj[s.first][e.first]=s.second+e.second;
	memset(dist,-1,sizeof(dist));
	for(unsigned s=1;s<=n;++s){
		dist[s][s]=0;
		std::priority_queue<std::pair<unsigned long long,unsigned>,std::vector<std::pair<unsigned long long,unsigned>>,std::greater<std::pair<unsigned long long,unsigned>>>pq;
		pq.emplace(0,s);
		while(pq.size()){
			unsigned long long dis=pq.top().first;
			unsigned mid=pq.top().second;
			pq.pop();
			if(dist[s][mid]==dis)
				for(unsigned e=1;e<=n;++e)
					if(adj[mid][e]!=-1&&dist[s][e]>dist[s][mid]+adj[mid][e])
						pq.emplace(dist[s][e]=dist[s][mid]+adj[mid][e],e);
		}
	}
	while(q--){
		scanf("%u%u",&x,&y);
		unsigned long long ans=-1;
		for(const auto &s:v[x])
			for(const auto &e:v[y]){
				unsigned long long res=dist[s.first][e.first]+s.second+e.second;
				if(ans>res)
					ans=res;
			}
		printf("%llu\n",ans+w[x]+w[y]);
	}
	return 0;
}
