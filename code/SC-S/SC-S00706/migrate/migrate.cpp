#include<bits/stdc++.h>
using namespace std;
const long long INF=2e18;
struct node{
	long long nxt;
	long long v;
	long long w;
}e[4000010];
long long head[2000010],tot;
void add(long long u,long long v,long long w){
	tot++;
	e[tot].nxt=head[u];
	e[tot].v=v;
	e[tot].w=w;
	head[u]=tot;
}

struct pa{
	long long dis;
	long long pos;
	bool operator < (const pa &a) const{
		return a.dis<dis;
	}
};
priority_queue<pa> pq;
long long dis[2000010],vis[2000010],cnt[2000010];

void dij(long long s){
	for(long long i=0;i<=2000005;i++){
		dis[i]=INF;
	}
	pa tmp;
	tmp.dis=0;
	tmp.pos=s;
	dis[s]=0;
	pq.push(tmp);
	
	while(!pq.empty()){
		tmp=pq.top();
		pq.pop();
		
		long long u=tmp.pos;
		if(vis[u]) continue;
		vis[u]=1;
		for(long long i=head[u];i;i=e[i].nxt){
			long long v=e[i].v;
			long long w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				cnt[v]=1;
				if(!vis[v]){
					tmp.dis=dis[v];
					tmp.pos=v;
					pq.push(tmp);
				}
			}
			else if(dis[u]+w==dis[v]){
				cnt[v]++;
			}
		}
	}
}
long long pos[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long c,T;
	cin>>c>>T;
	while(T--){
		memset(e,0,sizeof(e));
		memset(head,0,sizeof(head));
		tot=0;
		long long n;
		long long d;
		long long ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>pos[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(pos[j]-pos[i]<=d){
					add(i,j,1);
					add(j,i,1);
				}
			}
		}
		for(long long i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			memset(cnt,0,sizeof(cnt));
			dij(i);
			for(long long j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}