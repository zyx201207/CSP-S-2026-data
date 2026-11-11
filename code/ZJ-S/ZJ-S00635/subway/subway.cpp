#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,d,w[500005],k[505];
long long dis[505][505],ans;
vector<int>e[500005],t[500005];
int read(){
	int r=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return r;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int x=read(),y=read();
			e[x].push_back(i),t[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=1e18;
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size()-1;j++)
		for(int k=j+1;k<e[i].size();k++){
			int x=e[i][j],y=e[i][k];
			dis[x][y]=min(dis[x][y],1ll*t[i][j]+t[i][k]);
			dis[y][x]=dis[x][y];
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x=read(),y=read();ans=1e18;
		for(int i=0;i<e[x].size();i++)
		for(int j=0;j<e[y].size();j++)
			ans=min(ans,dis[e[x][i]][e[y][j]]+t[x][i]+t[y][j]+w[x]+w[y]);
		printf("%lld\n",ans);
	}
	return 0;
}