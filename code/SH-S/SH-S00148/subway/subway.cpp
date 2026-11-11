#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,dd,q;
int w[500010],k[500010];
int d[510][510];
struct node{
	int id,t;
};
vector<node> a[500010];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&dd,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1,x,y;j<=k[i];j++){
			scanf("%lld%lld",&x,&y);
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=INT_MAX;
			d[i][j]=1e18;
			if(i==j)d[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				int u=a[i][j].id,v=a[i][k].id;
				if(d[u][v]>a[i][j].t+a[i][k].t){
					d[u][v]=a[i][j].t+a[i][k].t;
					d[v][u]=d[u][v];
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]+d[k][j]<d[i][j]){
					d[i][j]=d[i][k]+d[k][j];
					d[j][i]=d[i][j];
				}
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		int ans=LONG_LONG_MAX;
		for(int j=0;j<a[x].size();j++){
			for(int k=0;k<a[y].size();k++){
				ans=min(ans,d[a[x][j].id][a[y][k].id]+a[x][j].t+a[y][k].t);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
}
