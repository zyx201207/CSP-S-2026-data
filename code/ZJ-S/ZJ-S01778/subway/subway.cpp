#include<bits/stdc++.h>
#define PII pair<long long,long long>
using namespace std;
long long c,n,m,d,q,len[505],a[505][20005],t[505][20005],dis[1010][1010],dist[1010][1010],w[500010];
long long h[500010],e[500010],ne[500010],W[500010],idx;
bool vis[500010];
void add(int x,int y,long long z){
	e[idx]=y;
	ne[idx]=h[x];
	W[idx]=z;
	h[x]=idx++;
}
void Dijkstra(int st){
	for(int i=1;i<=m;i++) vis[i]=0;
	priority_queue<PII,vector<PII>,greater<PII> >q;
	dist[st][st]=0;
	q.push({0,st});
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int d=t.second;
		if(vis[d]) continue;
		vis[d]=1;
		for(int i=h[d];~i;i=ne[i]){
			int j=e[i];
			if(dist[st][j]>dist[st][d]+W[i]){
				dist[st][j]=dist[st][d]+W[i];
				q.push({dist[st][j],j});
			}
		}
	}
}
void solv(){
	int x,y;
	cin>>x>>y;
	cout<<dist[min(x,y)][max(x,y)]+w[x]+w[y]<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++) cin>>a[i][j]>>t[i][j];
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len[i];j++){
			for(int k=j+1;k<=len[i];k++){
				int J=a[i][j],K=a[i][k];
				dis[J][K]=min(dis[J][K],t[i][j]+t[i][k]);
				dis[K][J]=min(dis[K][J],t[i][j]+t[i][k]);
			}
		}
	}
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len[i];j++){
			for(int k=j+1;k<=len[i];k++){
				int J=a[i][j],K=a[i][k];
				if(dis[J][K]) add(J,K,dis[J][K]);
				if(dis[K][J]) add(K,J,dis[K][J]);
				dis[J][K]=dis[K][J]=0;
			}
		}
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=m;i++) Dijkstra(i);
	while(q--) solv();
	return 0;            	
}
