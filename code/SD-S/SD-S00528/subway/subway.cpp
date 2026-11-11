#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=605,M=6e5+5;
int c,n,m,d,q;
int w[M];
vector<pair<int,int>> b[M];
ll dis[N][N];
int x,y;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

inline void add(int u,int v,ll w){
	dis[u][v]=min(dis[u][v],w);
	dis[v][u]=min(dis[v][u],w);
}

inline void solve(){
	ll ans=0x3f3f3f3f3f3f;
	for(int i=0;i<b[x].size();i++){
		for(int j=0;j<b[y].size();j++){
			ans=min(ans,dis[b[x][i].first][b[y][j].first]+b[x][i].second+b[y][j].second);
		}
	}
	printf("%lld\n",ans+w[x]+w[y]);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		for(int j=1;j<=k;j++){
			 int a,t;
			 a=read();t=read();
			 b[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=j+1;k<b[i].size();k++){
				add(b[i][j].first,b[i][k].first,0ll+b[i][j].second+b[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		x=read();y=read();
		solve();
	}
	return 0;
} 
