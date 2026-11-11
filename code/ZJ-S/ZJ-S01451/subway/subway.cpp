#include<bits/stdc++.h>
using namespace std;
#define int long long
#define isd(c) (c>=48 && c<=58)

const int M=5e5+10;
const int N=510;

int c,n,m,d,q; 
int w[M];
int k[N];
int head[M];
int cnt;
int dis[M+N];
int vis[M+N];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

struct edge{
	int u;
	int v;
	int w;
	int nxt;
}e[M<<3];

void init(){
	cnt=0;
	memset(head,-1,sizeof head);
}
void dij(int start,int end){
	memset(dis,0x3f,sizeof dis);
	memset(vis,false,sizeof vis);
	pq.push({0,start});
	dis[start]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		vis[u]=true;
		int now=pq.top().first;
		pq.pop();
		//if(u==end) return;
		for(int i=head[u];~i;i=e[i].nxt){
			int v=e[i].v;
			int w=e[i].w;
			if(vis[v]) continue;
			if(dis[v]>now+w){
				dis[v]=now+w;
				pq.push({dis[v],v});
			}
		}
	}
}
void add(int u,int v,int w){
	e[cnt].u=u;
	e[cnt].w=w;
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	cnt++;
}
void solve(int start,int end,int q){
	int ans;
	ans=w[start]+w[end];
	dij(start,end);	
	ans+=dis[end];
	cout<<ans<<'\n';
}

inline int rd(){
	int f=1,x=0;
	char c;
	for(c=getchar();!isd(c);c=getchar()){
		if(c=='-') f=-1;
	}
	for(;isd(c);c=getchar()){
		x=(x<<3)+(x<<1)+(c-48);
	}
	return x*f;
}
signed main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	init();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//m+i - railway
	//1-m - station
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int u,t,j=1;j<=k[i];j++){
			cin>>u>>t;
			add(m+i,u,t);
			add(u,m+i,t);
		}
	}
	for(int start,end,i=1;i<=q;i++){
		cin>>start>>end;
		solve(start,end,i);
	}
	
	return 0;
}
