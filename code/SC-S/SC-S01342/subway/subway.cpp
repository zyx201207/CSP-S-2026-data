#include<bits/stdc++.h>
using namespace std; 
#define ll long long
const int N=505,M=5e5+5;
int c,n,m,d,q,cnt;
ll dis[N][N],w[M],b[M];
int head[M],a[M],nxt[M];
int read(){
	char c='~';
	int ans=0;
	while(c<'0'||c>'9')c=getchar();
	while(!(c<'0'||c>'9')){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k,v,w;
		for(int j=1;j<=n;j++)
			dis[i][j]=1e18;
		dis[i][i]=0;
		k=read();
		for(int j=1;j<=k;j++){
			v=read();w=read();
			nxt[++cnt]=head[v];
			a[cnt]=i;b[cnt]=w;
			head[v]=cnt;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=head[i];j;j=nxt[j])
			for(int k=head[i];k;k=nxt[k])
				dis[a[j]][a[k]]=dis[a[k]][a[j]]=min(b[j]+b[k],dis[a[k]][a[j]]);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++){
		int u,v;
		ll ans=1e18;
		u=read();v=read();
		for(int j=head[u];j;j=nxt[j])
			for(int k=head[v];k;k=nxt[k])
				ans=min(ans,b[j]+b[k]+dis[a[j]][a[k]]);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}