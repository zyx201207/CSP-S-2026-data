//平晁宇 SN-S00350 西安铁一中滨河高级学校
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII> > pq;

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return w*s;
}

int c,n,m,d,q;
vector<PII> G[1000005];
int dist[1000005];

void dij(int s){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	pq.push({dist[s],s});
	while(!pq.empty()){
		int d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(dist[u]<d)continue;
		for(PII x:G[u]){
			int v=x.first;
			int w=x.second;
			if(w+dist[u]<dist[v]){
				dist[v]=w+dist[u];
				pq.push({dist[v],v});
			}
		}
	}
	return;
}




signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1,w;i<=m;i++){
		w=read();
		G[i].push_back({i+m,w});
		G[i+m].push_back({i,w});
	}
	for(int i=1,kk[100005],k;i<=n;i++){
		k=read();
		for(int j=1,t;j<=k;j++){
			kk[j]=read();
			if(j!=1){
				G[kk[j]+m*(i+1)].push_back({kk[j]+m*(i+1)-1,0});
				G[kk[j]+m*(i+1)-1].push_back({kk[j]+m*(i+1),0});
			}
			t=read();
			G[kk[j]].push_back({kk[j]+m*(i+1),t});
			G[kk[j]+m*(i+1)].push_back({kk[j],t});
		}
	}
	
	for(int i=1,s,e;i<=q;i++){
		s=read(),e=read();
		dij(s+m);
		printf("%d\n",dist[e+m]);
	}
	
	return 0;
}

