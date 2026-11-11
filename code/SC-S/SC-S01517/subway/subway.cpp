#include<bits/stdc++.h>
using namespace std;
const int N=5e5+510;
int c,m,n,d,q;
int w[N],k[N];
long long dis[510][510];
int vis[510];
struct edges{
	long long to,w; 
};
vector<edges>G[510]; 
long long eg[510][510];
vector<edges>jg[N];
static inline void read(int &x){
	x=0;
	char c=getchar();
	int f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-')f=-1; 
	}for(;c>='0'&&c<='9';c=getchar()){
		x=(x<<1)+(x<<3)+c-'0';
	}x*=f;
	//scanf("%d",&x);
}static inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}if(x>9)write(x/10);
	putchar(x%10+'0');
}void Dijkstra(int s){
	memset(dis[s],0x3f,sizeof(dis[s]));
	dis[s][s]=0;
	priority_queue<pair<long long,int>,vector<pair<long long ,int> >,greater<pair<long long,int> > >pq;
	memset(vis,0,sizeof(vis));
	pq.push({0,s});
	while(!pq.empty()){
		pair<long long ,int> u_pa=pq.top();
		pq.pop();
		int u=u_pa.second;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<G[u].size();i++){
			int to=int(G[u][i].to);long long w=G[u][i].w;
			if(!vis[to]){
				if(dis[s][to]>dis[s][u]+w){
					dis[s][to]=dis[s][u]+w;
					pair<long long,int> to_nxt;
					to_nxt.first=dis[s][to];
					to_nxt.second=to;
					pq.push(to_nxt);
				}
			}
		}//cout<<1;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	//cout<<1;
//	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		read(w[i]);
//		cin>>w[i];
	}int x,len;
	for(int i=1;i<=n;i++){
//		cout<<n;
		read(k[i]);
//		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			read(x);read(len);
//			cin>>x>>len;
			jg[x].push_back({1ll*i,1ll*len});
		}
	}memset(eg,0x3f,sizeof(eg));
	for(int u=1;u<=m;u++){
		if(jg[u].size()>1){
			for(int i=0;i<jg[u].size();i++){
				for(int j=i+1;j<jg[u].size();j++){
					long long w=jg[u][i].w+jg[u][j].w;
					int to1=jg[u][i].to,to2=jg[u][j].to;
					eg[to1][to2]=min(eg[to1][to2],w);
					eg[to2][to1]=eg[to1][to2];
				}
			}
		}
	}for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(eg[i][j]==0x3f3f3f3f3f3f3f3f)continue;
			if(i==j)continue;
			G[i].push_back({j,eg[i][j]});
		}
	}for(int i=1;i<=n;++i){
		Dijkstra(i);
	}
	
	while(q--){
		//cout<<q;
		int xr,yr;
		read(xr);read(yr);
//		cin>>xr>>yr;
		long long ans=1e18;
		for(int i=0;i<jg[xr].size();i++){
			for(int j=0;j<jg[yr].size();j++){
				int x_sta=jg[xr][i].to,y_sta=jg[yr][j].to;
				ans=min(ans,dis[x_sta][y_sta]+w[xr]+w[yr]+jg[xr][i].w+jg[yr][j].w);
			}
		}write(ans);
		putchar('\n');
	}
	

	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/