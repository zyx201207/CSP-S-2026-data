#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q;
int w[500010];
struct node{
	int to , len;
};
struct node3{
	int id , v;
};
vector<node> k[510];
vector<node3> g[500010];
bool vis[500010];
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)cin >> w[i];
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		for(int j = 1 ; j <= x ; j++){
			int a , t;
			cin >> a >> t;
			k[i].push_back({a , t});
			g[a].push_back({i , j - 1});
		}
	}
	while(q--){
		int x , y;
		cin >> x >> y;
		bool flag = 0;
		int ans = 0;
		for(int i = 0 ; i < g[x].size() ; i++){
			int res = 0;
			for(int i = g[x][i].v ; i < n ; i++){
				res += k[g[x][i].id][i].len;
				if(i == y){
					flag = 1;
					break;
				}
			}
			if(flag)ans = res;
			else ans = min(ans , res);
			if(flag)break;
		}
		for(int i = 1 ; i <= 510 ; i++)k[i].clear();
		for(int i = 1 ; i <= 500010 ; i++)g[i].clear();
		cout << ans + w[x] + w[y];
	}
	return 0;
}
