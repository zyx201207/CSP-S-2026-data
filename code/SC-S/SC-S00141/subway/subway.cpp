#include<bits/stdc++.h>
using namespace std;
const int N=500010,M=510;
int op,n,m,d,q,kk,a,x,y;
long long w[N],dis[M][M],t,ans;
struct node{
	int a;
	long long t;
};
vector<node>g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&op,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&kk);
		for(int j=1;j<=kk;j++){
			scanf("%d%lld",&a,&t);
			g[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1,len;i<=m;i++){
		len=g[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				if(g[i][j].a==g[i][k].a)continue;
				dis[g[i][j].a][g[i][k].a]=min(dis[g[i][j].a][g[i][k].a],g[i][j].t+g[i][k].t);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int z=1;z<=q;z++){
		scanf("%d%d",&x,&y);
		ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0,len1=g[x].size();i<len1;i++){
			for(int j=0,len2=g[y].size();j<len2;j++){
				ans=min(ans,w[x]+w[y]+dis[g[x][i].a][g[y][j].a]+g[x][i].t+g[y][j].t);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 