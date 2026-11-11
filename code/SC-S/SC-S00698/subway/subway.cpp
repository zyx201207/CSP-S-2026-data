#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int bian,n,m,d,q,w[M],cnt[M];
vector<pair<int,int> >zhan[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&bian,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,a,t;j<=k;j++){
			scanf("%d%d",&a,&t);
			zhan[a].push_back(make_pair(i,t));
			cnt[a]++;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int len=cnt[i];
		for(int j=0;j<len-1;j++){
			for(int k=j+1;k<len;k++)
				dis[zhan[i][j].first][zhan[i][k].first]=dis[zhan[i][k].first][zhan[i][j].first]=min(dis[zhan[i][j].first][zhan[i][k].first],min(dis[zhan[i][k].first][zhan[i][j].first],(ll)(zhan[i][j].second+zhan[i][k].second)));
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=w[x]+w[y],minn=1e18;
		int len1=cnt[x],len2=cnt[y];
		for(int i=0;i<len1;i++)
			for(int j=0;j<len2;j++){
				ll tmp=zhan[x][i].second+zhan[y][j].second+dis[zhan[x][i].first][zhan[y][j].first];
				minn=min(minn,tmp);
			}
		printf("%lld\n",ans+minn);
	}
	return 0;
}