#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > e[500010];
int c,n,m,w[500010],q,td;
long long d[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&td,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=0,a,b;j<k;j++){
			scanf("%d%d",&a,&b);
			e[a].emplace_back(i,b);
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++){
		int l=e[i].size();
		for(int j=0;j<l;j++)
			for(int k=j+1;k<l;k++)
				d[e[i][j].first][e[i][k].first]=d[e[i][k].first][e[i][j].first]=min(d[e[i][j].first][e[i][k].first],1ll*e[i][j].second+e[i][k].second);
	}
	for(int i=1;i<=n;i++)
		d[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			printf("%lld ",d[i][j]);
//		puts("");
//	}
	for(int i=0,x,y;i<q;i++){
		scanf("%d%d",&x,&y);
		long long tans=d[0][0];
		for(auto g1:e[x])
			for(auto g2:e[y])
				tans=min(tans,g1.second+d[g1.first][g2.first]+g2.second);
		printf("%lld\n",tans+w[x]+w[y]);
	}
	return 0;
} 
