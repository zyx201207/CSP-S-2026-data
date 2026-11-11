#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c-'0'),c=getchar();
	return x;
}
int c,n,m,a[500005],t,q,x,y,kk;//n线，m站，每条线kk个站
struct node{
	int k,x;
};vector<node> v[500005];
int d[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),t=read(),q=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		kk=read();
		for(int j=1;j<=kk;j++){
			x=read(),y=read();
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=2e18;
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++) for(int k=j+1;k<v[i].size();k++){
			node x=v[i][j],y=v[i][k];
			d[x.k][y.k]=d[y.k][x.k]=min(d[x.k][y.k],x.x+y.x);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=1;i<=q;i++){
		x=read(),y=read();
		int minn=2e18;
		for(int j=0;j<v[x].size();j++) for(int k=0;k<v[y].size();k++)
			minn=min(minn,v[x][j].x+d[v[x][j].k][v[y][k].k]+v[y][k].x);
		printf("%lld\n",minn+a[x]+a[y]);
	}
	return 0;
}
