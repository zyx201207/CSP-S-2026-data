#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false) , std::cin.tie(0) , std::cout.tie(0);
#define fi first
#define se second
#define pb push_back

using pii = std::pair <int , int>;
using i64 = long long;
using u64 = unsigned long long;

using namespace std;

const int MAXN = 550 , MAXM = 5e5 + 10;
const i64 INF = 0x3f3f3f3f3f3f3f3fll;
int cid , n , m , d , q;
i64 w[MAXM];
i64 dis[MAXN][MAXN];

vector <pii> t[MAXM];

int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	fastio;
	cin >> cid >> n >> m >> d >> q;
	memset(dis , 0x3f , sizeof(dis));

	for(int i = 1 ; i <= m ; i++) cin >> w[i];
	for(int i = 1 ; i <= n ; i++){
		int k;
		cin >> k;
		for(int j = 1 ; j <= k ; j++){
			int tmpa , tmpt;
			cin >> tmpa >> tmpt;
			t[tmpa].pb({i , tmpt});
		}
	}

	for(int i = 1 ; i <= m ; i++){
		for(auto t1 : t[i]){
			for(auto t2 : t[i]){
				dis[t1.fi][t2.fi] = min(dis[t1.fi][t2.fi] , (i64)(t1.se + t2.se));
				dis[t2.fi][t1.fi] = min(dis[t2.fi][t1.fi] , (i64)(t1.se + t2.se));
			}
		}
	}

	for(int i = 1 ; i <= n ; i++) dis[i][i] = 0;
	for(int k = 1 ; k <= n ; k++) for(int i = 1 ; i <= n ; i++) for(int j = 1 ; j <= n ; j++) dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
	while(q--){
		i64 ans = INF;
		int x , y;
		cin >> x >> y;

		for(auto t1 : t[x]){
			for(auto t2 : t[y]){
				// if(!q) cerr << x << ' ' << y << ' ' << t1.se << ' ' << t2.se << ' ' << dis[t1.fi][t2.fi] << '\n';
				ans = min(ans , w[x] + w[y] + t1.se + t2.se + dis[t1.fi][t2.fi]);
			}
		}

		cout << ans << '\n';
	}
	return 0;
}
/*
g++ subway.cpp -o subway -O2 -std=c++14 -static
./subway
diff -Z test.out subway3.ans

15:18:
O(nd^2+n^3+qd^2)
*/