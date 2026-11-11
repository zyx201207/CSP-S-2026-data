#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5,M=5e2+5;
const ll inf=1e18;
int Type,n,m,d,q,w[N];
ll dis[M][M];
vector<pair<int,int> > G[N];
int read(){
	int res=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Type=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,len;i<=n;i++){
		len=read();
		for(int j=1,to,c;j<=len;j++){
			to=read(),c=read();
			G[to].push_back(make_pair(i,c));
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=inf;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto tmp1:G[i]){
			int u=tmp1.first;
			for(auto tmp2:G[i]){
				int v=tmp2.first;
				ll c=tmp1.second+tmp2.second;
				dis[u][v]=dis[v][u]=min(dis[u][v],c);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		ll ans=inf;
		scanf("%d%d",&x,&y);
		for(auto tmp1:G[x])
			for(auto tmp2:G[y])
				ans=min(ans,dis[tmp1.first][tmp2.first]+tmp1.second+tmp2.second);
		printf("%lld\n",ans+w[x]+w[y]);
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
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
