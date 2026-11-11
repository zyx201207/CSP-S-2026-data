#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int M=5e5+10;
int c,t,n,m,d,q;
int f[N][N],dw[M];
vector<int>g[M];
vector<int>w[M];
int read(){
	int x=0,f=1;char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f; 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();m=read();
	d=read();q=read();
	for(int i=1;i<=m;i++)
	dw[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int u=read();
			int val=read();
			g[u].push_back(i);
			w[u].push_back(val);
		} 
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j)f[i][j]=1e18;
	for(int u=1;u<=m;u++)
	for(int x=0;x<g[u].size();x++)	
	for(int y=0;y<g[u].size();y++)
	f[g[u][x]][g[u][y]]=min(f[g[u][x]][g[u][y]],w[u][x]+w[u][y]);
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int u=read();
		int v=read();int ans=1e18;
		for(int x=0;x<g[u].size();x++)
		for(int y=0;y<g[v].size();y++)
		ans=min(ans,f[g[u][x]][g[v][y]]+w[u][x]+w[v][y]+dw[u]+dw[v]);
		printf("%lld\n",ans);
	}
	return 0;
}
