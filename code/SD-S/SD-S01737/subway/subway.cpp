#include<bits/stdc++.h>
#define ll long long//±ðÕ¨int 
using namespace std;
const int N = 500+3;
const int M = 5e5+3;
const int D = 20+3;
ll dis[N][N],w[M];
struct node{
	int x;
	ll t;
};
vector<node>  g[M];
int c,n,m,d,q;
ll ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for (int i = 1;i <= n;i++)
	  for (int j = 1;j <= n;j++)
	    if (i != j)  dis[i][j] = 1e18;
	for (int i = 1;i <= m;i++)  cin>>w[i];
	for (int i = 1;i <= n;i++){
		int k,a,tm;
		cin>>k;
		for (int j = 1;j <= k;j++){
			cin>>a>>tm;
			g[a].push_back({i,tm});
		}
	}
	for (int i = 1;i <= m;i++){
		for (auto nj : g[i]){
			for (auto nk : g[i]){
				int j = nj.x,k = nk.x;
				ll tj = nj.t,tk = nk.t;
				if (j == k)  continue;
				dis[k][j] = dis[j][k] = min(dis[j][k],tj+tk);
			}
		}
	}
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			if (i == k)  continue;
			for (int j = 1;j <= n;j++){
				if (i == j||j == k)  continue;
				dis[j][i] = dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (int i = 1,x,y;i <= q;i++){
		ans = 1e18;
		cin>>x>>y;
		for (auto nj : g[x]){
			for (auto nk : g[y]){
				int j = nj.x,k = nk.x;
				ll tj = nj.t,tk = nk.t;
				ans = min(ans,w[x]+w[y]+tj+tk+dis[j][k]);
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
