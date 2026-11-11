#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int k=0,c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k;
}
struct aa {
	int x,y,w;
} p[500009][21];
int n,l[500009],m,d,dis[509][509],C,Q,w[500009],k[509];
vector<int> t[509];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();
	n=read();
	m=read();
	d=read();
	Q=read();
	for(int i=1; i<=m; i++) w[i]=read();
	for(int i=1; i<=n; i++) {
		k[i]=read();
		t[i].push_back(0);
		for(int j=1; j<=k[i]; j++) {
			int u,ww;
			u=read();
			ww=read();
			t[i].push_back(ww);
			p[u][++l[u]]= {i,j,ww};
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=l[i];j++)
			for(int z=1;z<=l[i];z++){
				aa u=p[i][j],v=p[i][z];
				dis[u.x][v.x]=min(dis[u.x][v.x],t[u.x][u.y]+t[v.x][v.y]);
			}
	for(int h=1;h<=n;h++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][h]+dis[h][j]);
	while(Q--){
		int s,tt,ans=1e16;
		s=read();
		tt=read();
		for(int i=1;i<=l[s];i++){
			for(int j=1;j<=l[tt];j++){
				ans=min(ans,w[s]+w[tt]+dis[p[s][i].x][p[tt][j].x]+t[p[s][i].x][p[s][i].y]+t[p[tt][j].x][p[tt][j].y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
