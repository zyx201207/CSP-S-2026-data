#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=505,M=5e5+5,iinf=2e9+100;
const long long inf=1e18;
int dis0[N][N];
long long dis[N][N];
vector<pair<int,int> > v[M];
int tc,n,m,d,q,w[M];
int read() {
	int x=0;
	char ch=getchar();
	while(ch<48) ch=getchar();
	while(ch>=48) {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	tc=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++) {
		int k=read();
		for(int j=1;j<=k;j++) {
			int x=read(),val=read();
			v[x].push_back({i,val});
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) dis0[i][j]=iinf;
	}
	for(int i=1;i<=m;i++) {
		for(int j=0;j<v[i].size();j++) {
			for(int k=j+1;k<v[i].size();k++) {
				int x=v[i][j].first,y=v[i][k].first,val=v[i][j].second+v[i][k].second;
				dis0[x][y]=min(dis0[x][y],val);
			}
		}
	}
	for(int i=1;i<n;i++) {
		for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=(dis0[i][j]==iinf?inf:dis0[i][j]);
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--) {
		int x=read(),y=read();
		long long ans=inf;
		for(int i=0;i<v[x].size();i++) {
			for(int j=0;j<v[y].size();j++) ans=min(ans,dis[v[x][i].first][v[y][j].first]+v[x][i].second+v[y][j].second);
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
/*
ÓÎ¼Ç£ºhttps://www.luogu.com.cn/article/vo1uk7d5
green

0.67s
Can I get 100pts?
15:17
*/
