#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define inf 1e18
using namespace std;
const int N=2e4+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int c,n,m,d,Q;
int a[505][N];
int t[505][N];
int k[505];
int w[N];
int dis[N];
int vis[N];
struct p{
	int v,w;
};
vector<p> f[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dij(int x){
	for(int i=1;i<=m;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	dis[x]=0;
	q.push({0,x});
	while(!q.empty()){
		int u=q.top().second;
		int di=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<f[u].size();i++){
			int v=f[u][i].v;
			int w=f[u][i].w;
			if(dis[v]>di+w){
				dis[v]=di+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();m=read();
	d=read();Q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
			t[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int z=1;z<=k[i];z++){
				if(j==z) continue;
				int u=a[i][j];
				int v=a[i][z];
				int w=t[i][j]+t[i][z];
				f[u].push_back({v,w});
				f[v].push_back({u,w});
			}
		}
	}
	while(Q--){
		int st,en;
		st=read();en=read();
		dij(st);
		cout<<dis[en]+w[st]+w[en]<<"\n";
	}
	return 0;
}
