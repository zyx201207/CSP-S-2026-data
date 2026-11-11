#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int t[500005],to[500005][21],dis[505][505],D[500005][21],tot[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)cin>>t[i];
	for(int i=1;i<=n;++i){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;++j){
			int a,t;
			scanf("%lld%lld",&a,&t);
			to[a][++tot[a]]=i;
			D[a][tot[a]]=t;
		}
	}memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=tot[i];++j){
			for(int k=1;k<=tot[i];++k){
				dis[to[i][j]][to[i][k]]=min(dis[to[i][j]][to[i][k]],D[i][j]+D[i][k]);
			}
		}
	}for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k-1]+dis[k-1][j]);
			}
		}
	}while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=tot[x];++i){
			for(int j=1;j<=tot[y];++j){
				ans=min(ans,t[x]+t[y]+D[x][i]+D[y][j]+dis[to[x][i]][to[y][j]]);
			}
		}printf("%lld\n",ans);
	}
}