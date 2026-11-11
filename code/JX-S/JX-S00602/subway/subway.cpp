#include <bits/stdc++.h>
#define PII pair<int,int>
#define int long long
#define OI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int N=1e6+5,M=2*N;
int n,m,d,q;
int W[505];
//int h[N],ne[M],e[M],w[M],idx;
int g[5005][5005];
int cnt;

/*
void add(int a,int b,int c){
	ne[idx]=h[a],e[idx]=b,w[idx]=c,h[a]=idx++;
}
*/

void Floyd(){
	for(int k=1;k<=cnt;k++)
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

signed main(){
	OI("subway");
	//memset(h,-1,sizeof h);
	scanf("%lld%lld%lld%lld%lld",&m,&m,&n,&d,&q);
	cnt=n;
	for(int i=1;i<=5000;i++) 
		for(int j=1;j<=5000;j++) 
			g[i][j]=0x3f3f3f3f;
	for(int i=1;i<=5000;i++) g[i][i]=0; 
	for(int i=1;i<=n;i++) scanf("%lld",&W[i]);
	for(int i=1;i<=m;i++){
		int k;cin>>k;
		int S=cnt+1;
		for(int j=1;j<=k;j++){
			int u,w;scanf("%lld%lld",&u,&w);
			g[u][++cnt]=w;
			g[cnt][u]=w;
			//add(u,++cnt,w);
			//add(cnt,u,w);
		}
		for(int u=S;u<=cnt;u++)
			for(int v=S+1;v<=cnt;v++){
				g[u][v]=0,g[v][u]=0;
				//add(u,v,0),add(v,u,0);
			}
	}
	Floyd();
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		printf("%lld\n",W[x]+W[y]+g[x][y]);
	} 
	return 0;
}
