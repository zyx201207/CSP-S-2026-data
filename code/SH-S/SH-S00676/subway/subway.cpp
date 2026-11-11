#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdio>
#define ll long long
using namespace std;

const int maxn = 505,maxm = 5e5 + 15;
const ll inf = 1e18;
struct node{
	int id;
	ll t;
};
ll dp[maxn][maxn],c,n,m,d,q,w[maxm];
vector<node> have_u[maxm];
void input(){
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%lld",&w[i]);
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d",&k);
		for(int j = 1;j <= k;j++){
			int a;
			ll t;
			scanf("%d%lld",&a,&t);
			node nx;
			nx.id = i,nx.t = t;
			have_u[a].emplace_back(nx);
		}
	}
	
}
void solve(){
	for(int i = 0;i < maxn;i++)
		for(int j = 0;j < maxn;j++)
			dp[i][j] = inf;
	for(int i = 0;i < maxn;i++) dp[i][i] = 0;
	for(int i = 1;i <= m;i++){
		for(int x = 0;x < (int)have_u[i].size();x++){
			for(int y = 0;y < x;y++){
				int xid = have_u[i][x].id,yid = have_u[i][y].id;
				ll tx = have_u[i][x].t,ty = have_u[i][y].t;
				dp[xid][yid] = dp[yid][xid] = min(dp[xid][yid],tx + ty);
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				ll dik = dp[i][k],dkj = dp[k][j];
				if(dik == inf || dkj == inf) continue;
				dp[i][j] = min(dp[i][j],dik + dkj);
			}
		}
	}
	while(q--){
		ll ans = inf;
		int x,y;
		scanf("%d%d",&x,&y);
		for(auto i : have_u[x]){
			for(auto j : have_u[y]){
				ans = min(ans,dp[i.id][j.id] + i.t + j.t);
			}
		}
		ans += w[x] + w[y];
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
