#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=5e2+10,M=5e5+10;
int dis[N][N],c,n,m,d,q,k[M];
struct node{
	int v,w;
};
vector<node>g[M];
void floyd(){
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			if (i==k)continue;
			for (int j=1;j<=n;j++){
				if (i==j||j==k)continue;
				dis[i][j]=dis[j][i]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) dis[i][j]=1e18;
	for (int i=1;i<=m;i++)cin>>k[i];
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int tmp_a,tmp_b;cin>>tmp_a>>tmp_b;
			for (node it:g[tmp_a]){
				dis[it.v][i]=dis[i][it.v]=min(dis[it.v][i],tmp_b+it.w);
			}
			g[tmp_a].push_back({i,tmp_b});
		}
	}
	floyd();
	while(q--){
		int x,y;cin>>x>>y;
		int ans=LLONG_MAX;
		for (node it1:g[x]){
			for (node it2:g[y]){
//				cout<<x<<" "<<y<<'-'<<dis[it1.v][it2.v]<<endl;
				int len=dis[it1.v][it2.v]+it1.w+it2.w+k[x]+k[y];
				ans=min(ans,len);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}





