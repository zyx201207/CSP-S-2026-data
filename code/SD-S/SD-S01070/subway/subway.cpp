#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e6 + 10;
const int N = 505;
int c,n,m,d,Q;
ll dis[N][N];
int w[M];
struct Edge{
	int v;
	ll w;
};
vector<Edge>e[M];
//16:44
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i ++)cin >> w[i];
	for(int i = 1;i <= n;i ++){
		int num;
		cin >> num;
		for(int j = 1;j <= num;j ++){
			int v,w;
			cin >> v >> w;
			e[v].push_back((Edge){i,w});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= n;i ++)dis[i][i] = 0;
	for(int i = 1;i <= m;i ++){
		for(Edge to1 : e[i]){
			int v1 = to1.v;
			ll w1 = to1.w;
			for(Edge to2 : e[i]){
				int v2 = to2.v;
				ll w2 = to2.w;
				if(v1 == v2)continue;
				
				dis[v1][v2] = min(dis[v1][v2],w1 + w2);
			}
		}
	}
	for(int k = 1;k <= n;k ++){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while(Q --){
		ll ans = LONG_LONG_MAX;
		int x,y;
		cin >> x >> y;
		for(Edge to1 : e[x]){
			int v1 = to1.v;
			ll w1 = to1.w;
			for(Edge to2 : e[y]){
				int v2 = to2.v;
				ll w2 = to2.w;
				ans = min(ans,w[x] + w[y] + dis[v1][v2] + w1 + w2);
			}
		}
		cout << ans << "\n";
	}
	
	
	
	
	
	
	
	return 0;
}
