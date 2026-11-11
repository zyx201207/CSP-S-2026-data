#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x;
}
int ww[N],num[N],g[510][510];
vector<pair<int,int> > v[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int tes,n,m,mm,q;cin>>tes>>n>>m>>mm>>q;
	for(int i=1;i<=m;i++)ww[i]=read();
	for(int i=1;i<=n;i++){
		num[i]=read();
		for(int j=1;j<=num[i];j++){
			int t=read(),tt=read();
			v[t].push_back(make_pair(i,tt));
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i^j)g[i][j]=(int)(1e18);
	for(int i=1;i<=m;i++)
		for(int j=0;j<v[i].size();j++)
			for(int k=j+1;k<v[i].size();k++){
				int x=v[i][j].first,y=v[i][k].first;
				g[x][y]=g[y][x]=min(g[x][y],v[i][j].second+v[i][k].second);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=q;i++){
		int x=read(),y=read(),ans=(int)(1e18);
		for(pair<int,int> j:v[x])
			for(pair<int,int> k:v[y])ans=min(ans,ww[x]+ww[y]+j.second+k.second+g[j.first][k.first]);
		printf("%lld\n",ans);
	}
}
