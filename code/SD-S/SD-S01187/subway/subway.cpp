#include<bits/stdc++.h>
#define int long long 
#define PII pair<long long,long long>
#define x first
#define y second
using namespace std;
const int N=500100;
int n,m,c,d,T;
int dis[501][501],w[N];
PII zz[N];
vector<PII>a[N];
int read(){
	int x=0;
	int f=1; 
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();T=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			zz[j].x=read();
			zz[j].y=read();
			a[zz[j].x].push_back({i,zz[j].y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18-1;
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(PII u:a[i]){
			for(PII v:a[i]){
				if(u.x!=v.x){
					dis[u.x][v.x]=min(dis[u.x][v.x],u.y+v.y);
					dis[v.x][u.x]=dis[u.x][v.x];	
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	while(T--){
		int u,v,ans=1e18-1;
		u=read();v=read();
		for(PII p1:a[u]){
			for(PII p2:a[v]){
				ans=min(ans,dis[p1.x][p2.x]+p1.y+p2.y);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
