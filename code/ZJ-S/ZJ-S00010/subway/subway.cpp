#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int T,n,m,d,q;
int C[maxn];
struct edge{
	int v,w;
};
vector<edge>e[maxn];
int dis[505][505];
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=10*x+c-'0';
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	T=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)C[i]=read();
	for(int i=1;i<=n;i++){
		int y=read();
		for(int j=1;j<=y;j++){
			int x=read(),t=read();
			e[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
			if(i==j)dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)for(int j=0;j<e[i].size();j++)for(int k=0;k<e[i].size();k++)dis[e[i][j].v][e[i][k].v]=min(dis[e[i][j].v][e[i][k].v],e[i][j].w+e[i][k].w);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(dis[i][j]>dis[i][k]+dis[k][j])dis[i][j]=dis[i][k]+dis[k][j];
	for(int o=1;o<=q;o++){
		int x=read(),y=read(),ans=1e18;
		for(int i=0;i<e[x].size();i++)for(int j=0;j<e[y].size();j++)ans=min(ans,e[x][i].w+e[y][j].w+dis[e[x][i].v][e[y][j].v]);
		cout<<ans+C[x]+C[y]<<"\n";
	}
}
