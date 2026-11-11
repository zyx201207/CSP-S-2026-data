#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10,K=2e4+10;
int mp[N][N],f[N][N],sg[N][N];
vector<int> a[N],t[N];
int c,n,m,d,q;
int w[N],k[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=mp[i][j]=1e9;
	for(int i=1;i<=m;i++)f[i][i]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);a[i].push_back(0),t[i].push_back(0);
		int pp,qq;
		for(int j=1;j<=k[i];j++)
			scanf("%lld%lld",&pp,&qq),a[i].push_back(pp),t[i].push_back(qq);
	}
	for(int i=1;i<=n;i++){
		int ls,val,u,v;
		for(int j=1;j<=k[i];j++){
			for(int p=1;p<=k[i];p++){
				f[a[i][j]][a[i][p]]=f[a[i][p]][a[i][j]]=
				min(f[a[i][p]][a[i][j]],t[i][j]+t[i][p]);
			}
//			u=a[i][j-1],v=a[i][j],val=t[i][j]+t[i][j-1];
//			f[u][v]=f[v][u]=min(f[v][u],val);
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	cout<<f[1][2]<<'\n';
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",f[x][y]+w[x]+w[y]);
	}
	return 0;
}//32pts