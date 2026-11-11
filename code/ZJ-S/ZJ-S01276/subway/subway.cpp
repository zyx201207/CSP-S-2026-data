#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int c,n,m,d,q,w[M],f[505][505];
int x,y,k,mi;
struct node{int v,w;};
vector<node>mp[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&x,&y);
			mp[x].push_back({i,y});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		for(int j=0;j<mp[i].size();j++)
			for(int k=j+1;k<mp[i].size();k++){
				int u=mp[i][j].v,v=mp[i][k].v,w=mp[i][j].w+mp[i][k].w;
				f[u][v]=min(f[u][v],w);
				f[v][u]=min(f[v][u],w);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
	for(int i=1;i<=n;i++)f[i][i]=0;
	while(q--){
		mi=1e18;
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<mp[x].size();i++)
			for(int j=0;j<mp[y].size();j++){
			//	cout<<mp[x][i].v<<" "<<mp[y][j].v<<"\n";
				mi=min(mi,f[mp[x][i].v][mp[y][j].v]+mp[x][i].w+mp[y][j].w);
			}
		cout<<mi+w[x]+w[y]<<"\n";
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
32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
35
16
*/

