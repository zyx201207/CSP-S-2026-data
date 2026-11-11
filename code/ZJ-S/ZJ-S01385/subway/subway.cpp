#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long c,n,m,d,q,tot=0;
struct edge{
	long long nxt,to,w;
}e[N<<1];
long long head[N],vis[N],dis[N],times[N],k[N],stat[N];
long long distances[2005][2005];
void add(long long u,long long v,long long w){
	e[++tot].nxt=head[u];
	head[u]=tot,e[tot].to=v;
	e[tot].w=w;
}
struct node{
	long long u,dis;
	bool operator<(const node&x)const{
		return dis>x.dis;
	}
};
priority_queue<node>que;
void dijkstra(long long now){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	while(!que.empty())que.pop();
	dis[now]=0;que.push((node){now,0});
	while(!que.empty()){
		long long u=que.top().u;que.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(long long i=head[u];i;i=e[i].nxt){
			long long v=e[i].to;
			if(dis[u]+e[i].w<dis[v]){
				dis[v]=dis[u]+e[i].w;
				que.push((node){v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++)
		scanf("%lld",&times[i]);
	long long cnt_stat=m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++){
			long long tt;
			scanf("%lld%lld",&stat[j],&tt);
			cnt_stat++;
			add(stat[j],cnt_stat,tt);
			add(cnt_stat,stat[j],tt);
			stat[j]=cnt_stat;
			if(j>=2){
				add(stat[j],stat[j-1],0);
				add(stat[j-1],stat[j],0);
			}
		}
	}
	if(c<=8||c>=12){
		while(q--){
			long long st,ed;
			scanf("%lld%lld",&st,&ed);
			dijkstra(st);
			printf("%lld\n",dis[ed]+times[st]+times[ed]);
		}
	}
	if(9<=c&&c<=11){
		for(long long i=1;i<=m;i++){
			dijkstra(i);
			for(long long j=i;j<=m;j++)
				distances[i][j]=dis[j];
		}
		while(q--){
			long long st,ed;
			scanf("%lld%lld",&st,&ed);
			if(st>ed)swap(st,ed);
			printf("%lld\n",distances[st][ed]+times[st]+times[ed]);
		}
	}
	return 0;
}
