#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,LN=2e3+10;
inline int rd(){
	int re=0,c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9'){
		re=re*10+c-'0';
		c=getchar();
	}
	return re;
}
int c,n,m,d,q;
int w[N];
int a[N];
long long t[N];
long long dis[LN][LN];
int vis[N<<1];
vector<pair<int,long long> > e[LN];
inline void dijkstra(int stt){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>p;
	dis[stt][stt]=0;
	p.push({0,stt});
	while(!p.empty()){
		int now=p.top().second;p.pop();
		if(vis[now]==stt)continue;
		vis[now]=stt;
		for(int i=0;i<e[now].size();i++){
			int to=e[now][i].first;
			long long val=e[now][i].second;
			if(dis[stt][now]+val < dis[stt][to]){
				dis[stt][to]=dis[stt][now]+val;
				p.push({dis[stt][to],to});
			}
		}
	}
}
vector<int> ne[N<<1];
int D[N<<1];
int que[N<<1];
inline int bfs(int stt,int edd,int qwp){
	int start=1,tail=0;
	que[++tail]=stt;vis[stt]=qwp;D[stt]=0;
	while(start<=tail){
		int now=que[start++];
		for(int i=0;i<ne[now].size();i++){
			int to=ne[now][i];
			if(vis[to]<qwp){
				vis[to]=qwp;
				D[to]=D[now]+1;
				que[++tail]=to;
				if(to==edd)return D[edd];
			}
		}
	}
	return D[edd];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd();m=rd();n=rd();d=rd();q=rd();
	for(int i=1;i<=n;i++)w[i]=rd();
	if(c<=11){
		memset(dis,0x3f,sizeof(dis));
		for(int i=1,k;i<=m;i++){
			k=rd();
			for(int j=1;j<=k;j++)a[j]=rd(),t[j]=rd();
			for(int u=1;u<=k;u++){
				for(int v=1;v<=k;v++){
					if(u==v)continue;
					e[a[u]].push_back({a[v],t[u]+t[v]});
				}
			}
		}
		for(int i=1;i<=n;i++)dijkstra(i);
		int x,y;
		while(q--){
			x=rd();y=rd();
			cout << (dis[x][y]+w[x]+w[y]) << '\n';
		}
	}else{
		long long T;
		for(int i=1,k;i<=m;i++){
			k=rd();
			for(int j=1;j<=k;j++){
				a[j]=rd();T=rd();
				ne[n+i].push_back(a[j]);
				ne[a[j]].push_back(n+i);
			}
		}
		int x,y;
		for(int i=1;i<=q;i++){
			x=rd();y=rd();
			cout << (T*bfs(x,y,i)+w[x]+w[y]) << '\n'; 
		}
	}
	return 0;
}
