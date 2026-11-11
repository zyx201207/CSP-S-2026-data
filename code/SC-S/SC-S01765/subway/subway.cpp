#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
这个题目太长了
算不出来时间复杂度怎么办
只算出来一部分是O(n^3)
也不知道能得几分
24pts~32pts？
*/

const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M],dist[N][N];//dist记录地铁线路两两之间的距离
int k[N];
pair<int,int> a[N][25];
vector<pair<int,int>> station[M];//哪条地铁，站台走到的时间

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(dist,0x3f,sizeof(dist));
	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	//从每个地铁站的地铁口走到站厅需要的时间
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	//经过的地铁站数；第几个地铁站，站厅走到这条地铁需要多久
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j].first,&a[i][j].second);
			station[a[i][j].first].push_back({i,a[i][j].second});
		}
		sort(a[i]+1,a[i]+k[i]+1);
		for(int j=1;j<i;j++){
			int l1=1,l2=1;
			while(l1<=k[i]&&l2<=k[j]){
				if(a[i][l1].first==a[j][l2].first){
					dist[i][j]=min(dist[i][j],a[i][l1].second+a[j][l2].second);
					dist[j][i]=dist[i][j];
					l1++,l2++;
				}else if(a[i][l1].first<a[j][l2].first) l1++;
				else l2++;
			}
		}
	}
	
	for(int i=1;i<=n;i++) dist[i][i]=0;
	//算出任意两条线路的最短距离
	for(int i=1;i<=n;i++){
		for(int kk=1;kk<=n;kk++){
			if(dist[i][kk]==dist[0][0]) continue;
			for(int j=i+1;j<=n;j++){
				if(dist[kk][j]==dist[0][0]) continue;
				dist[i][j]=min(dist[i][j],dist[i][kk]+dist[kk][j]);
				dist[j][i]=dist[i][j];
			}
		}
	}
	
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=0x3f3f3f3f;
		for(auto i:station[x]){
			for(auto j:station[y]){
				ans=min(ans,i.second+j.second+dist[i.first][j.first]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}