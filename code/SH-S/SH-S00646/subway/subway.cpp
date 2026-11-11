#include<bits/stdc++.h>
using namespace std;
struct qu{
	long long id,dis;
};
long long c,n,m,d,q,w[1005],t[1005][505],dis[1005][1005],start,end,ans,k,a,tim,line[505][1005],sizel[505];
vector<long long> station[5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=1005;i++)for(int j=1;j<=1005;j++)dis[i][j]=1e18;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		while(k--){
			scanf("%lld%lld",&a,&tim);
			station[a].push_back(i);
			line[i][++sizel[i]]=a;
			t[a][i]=tim;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<station[i].size();j++){
			long long lne=station[i][j];
			for(int k=1;k<=sizel[lne];k++){
				long long des=line[lne][k];
				if(des!=i)dis[i][des]=min(dis[i][des],t[i][lne]+t[des][lne]),dis[des][i]=dis[i][des];
				if(des==i)dis[i][i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		scanf("%lld%lld",&start,&end);
		ans=w[start]+w[end];
		printf("%lld\n",ans+dis[start][end]);
	}
}
