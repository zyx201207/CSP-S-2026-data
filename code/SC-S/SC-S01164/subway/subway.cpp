#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

static inline int read(){
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res*f;
}

static inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=505,M=5e5+5,Q=1e5+5;
const long long INF=0x3f3f3f;
int c,n,m,d,q;//n 条地铁线路,m 个地铁站,每个地铁站最多被m条线路经过,出行计划数q
int w[M];
vector<pair<int,ll>> l[M+N];//1~m地铁站,m+1~m+n线路 

static inline void add(int u,int v,ll w){
	l[u].emplace_back(v,w);
	l[v].emplace_back(u,w);
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=n;++i){
		int k=read();
		for(int j=1,a,t;j<=k;++j) a=read(),t=read(),add(i+m,a,1ll*t);
	}
	
//	for(int i=m+1;i<=m+n;++i){
//		cout<<i-m<<" :  ";
//		for(const pair<int,ll>& ft:l[i]){
//			cout<<ft.first<<' ';
//		}cout<<'\n';
//	}
	
	int s,f;
	while(q--){
		s=read(),f=read();
		priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
		q.push({0,s});
		ll dis[n+m+5];
		memset(dis,INF,sizeof(dis));
		while(!q.empty()){
			pair<ll,int> ft=q.top();q.pop();
			int u=ft.second;
			dis[u]=ft.first;
			for(const pair<int,ll>& ftt:l[u]){
				int v=ftt.first;ll w=ftt.second;
				if(dis[v]>dis[u]+w) q.push({dis[u]+w,v});
			}
		}
		ll ans=dis[f]+w[s]+w[f];
		write(ans);putchar('\n');
	}
	
	return 0;
}