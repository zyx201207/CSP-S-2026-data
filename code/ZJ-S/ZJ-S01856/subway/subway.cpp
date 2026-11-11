#include<bits/stdc++.h>
using namespace std;
int C,n,m,D,q,sl,u,v,s1,s2,o1,o2;
long long dis,ans,w[500005],x,y,d[505][505];
vector<pair<int,long long> > tu[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&D,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&sl);
		while(sl--){
			scanf("%lld%lld",&x,&y);
			tu[x].push_back({i,y});
		}
		for(int j=1;j<=n;j++){
			d[i][j]=0x3f3f3f3f3f3f3f3f;
		}
		d[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		sl=tu[i].size();
		for(int j=0;j<sl;j++){
			u=tu[i][j].first;
			for(int k=j+1;k<sl;k++){
				v=tu[i][k].first;
				dis=tu[i][j].second+tu[i][k].second;
				d[u][v]=min(d[u][v],dis);
				d[v][u]=min(d[v][u],dis);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&u,&v);
		ans=0x3f3f3f3f3f3f3f3f;
		s1=tu[u].size();
		s2=tu[v].size();
		for(int i=0;i<s1;i++){
			o1=tu[u][i].first;
			for(int j=0;j<s2;j++){
				o2=tu[v][j].first;
				dis=tu[u][i].second+tu[v][j].second;
				ans=min(ans,w[u]+w[v]+dis+d[o1][o2]);
			}
		}
		printf("%lld\n",ans);
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

/*
45min good?
big run 2s GGlow
*/
