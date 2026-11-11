#include<bits/stdc++.h>
using namespace std;
using ll=long long;
namespace Solver_T2{
	int cnt[500005];
	short sid[500005][21];
	int t2[500005][21];
	int t1[500005];
	ll dis[505][505];
	void Recall(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0);cin.tie(0);
		int _id,n,m,k,q;
		cin>>_id>>n>>m>>k>>q; 
		for(int i=1;i<=m;i++)cin>>t1[i];
		for(int i=1;i<=n;i++){
			int c;
			cin>>c;
			for(int j=1;j<=c;j++){
				int u,t;
				cin>>u>>t;
				cnt[u]++;
				sid[u][cnt[u]]=i;
				t2[u][cnt[u]]=t;
			}
		}
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=cnt[i];j++){
				for(int k=j+1;k<=cnt[i];k++){
					int u=sid[i][j],v=sid[i][k];
					dis[u][v]=min(dis[u][v],(ll)t2[i][j]+t2[i][k]);
					dis[v][u]=min(dis[v][u],(ll)t2[i][j]+t2[i][k]);
				}
			}
		}
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		while(q--){
			int u,v;
			cin>>u>>v;
			ll ans=1e18;
			for(int i=1;i<=cnt[u];i++){
				for(int j=1;j<=cnt[v];j++)ans=min(ans,t2[u][i]+t2[v][j]+dis[sid[u][i]][sid[v][j]]);
			}
			cout<<ans+t1[u]+t1[v]<<'\n';
		}
	}
}
int main(){
	Solver_T2::Recall();
}
/*
我们对于每组询问，枚举两个点分别在哪个地铁站上下车
然后，我们对着每个地铁线路做floyd
O(n^3+nm+qd^2)
诶不对！nm需要带个log
O(n^3+nmlogm+qd^2)
显然过不了
诶我去，可以正难则反
O(n^3+md^2+qd^2)
不对，分析一下还是O(n^3+md+qd^2)
好耶，冲冲冲
floyd改成n遍dij变成n^3 log了，更劣了，所以不行
诶不对，是n^2dlogn
算了n^3估计能过 
*/
