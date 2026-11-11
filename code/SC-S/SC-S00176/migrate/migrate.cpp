//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！

#include<bits/stdc++.h>
#define LoveCyrene ios :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define LoveAnastasya freopen("migrate.in", "r", stdin)
#define LoveOdette freopen("migrate.out", "w", stdout)
#define int long long int
using namespace std;;
constexpr int N = 2e6 + 1978;
constexpr int INF = 1E18;
int a[N];

struct G{ int u, v, w; };

bool A(int n){
	for (int i = 3; i <= n; ++i) if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) return 0;
	return 1;
}

int tpa(int n, int d){
	int dif = a[2] - a[1];
	int cnt = d / dif;
	return n - cnt - 2;
}

int Anastasya(int n, int d){
	if(A(n)) return tpa(n, d);
	
	vector<vector<int>> dis(n + 1, vector<int> (n + 1, INF));
	vector<vector<int>> cnt(n + 1, vector<int> (n + 1, 0));
	
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			if(i != j && abs(a[i] - a[j]) <= d){
				dis[i][j] = dis[j][i] = 1;
			}
		}
	}
	
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
//				if(i == j) continue;
				if(dis[i][j] >= dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if(dis[i][j] == dis[i][k] + dis[k][j]){
					cnt[i][j]++;
				}
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i){
		for (int j = i + 1; j <= n; ++j){
			if(cnt[i][j] == 2) ans++; 
		}
	}
	
	return ans;
}

signed main(){
	LoveAnastasya;
	LoveOdette;
	LoveCyrene;
	int c, t; cin >> c >> t;
	for (int n, d; t--; cout << Anastasya(n, d) << '\n') {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> a[i];
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/