//when you use deque or vector,
//by OldDriverTree
#include<bits/stdc++.h>
#define range(vec) vec.begin(),vec.end()
#define tup array<int,3>
#define P pair<int,int>
#define mid (l+r>>1)
using namespace std;
const int N=501,M=5e5+1;
vector<P> a[M];
int n,m,q,w[M];
long long g[N][N];

int read() {
	int x=0; bool f=true; char c=0;
	while (!isdigit(c) ) f&=(c!='-'),c=getchar();
	while (isdigit(c) ) x=x*10+(c&15),c=getchar();
	return f?x:-x;
}
main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),read(),q=read();
	for (int i=1;i<=m;i++) w[i]=read();
	memset(g,0x3f,sizeof g);
	for (int i=1;i<=n;i++)
	{
		int k=read();
		while (k--) {
			int x=read(),y=read();
			a[x].push_back({i,y});
		}
	}
	for (int i=1;i<=n;i++) g[i][i]=0;
	for (int i=1;i<=m;i++)
		for (P x:a[i]) for (P y:a[i])
			g[x.first][y.first]=min<long long>(g[x.first][y.first],x.second+y.second);
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while (q--) {
		int x=read(),y=read(); long long ans=1e18;
		for (P p:a[x]) for (P q:a[y])
		ans=min(ans,p.second+q.second+g[p.first][q.first]);
		printf("%lld\n",w[x]+w[y]+ans);
	}
	return 0;
}
/*
O(dsum k+n^3+qd^2)
15:07 ´óÑùÀý 0.5s 
*/
