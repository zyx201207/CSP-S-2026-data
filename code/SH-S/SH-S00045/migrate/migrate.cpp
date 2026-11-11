#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
int n;
ll d;
vector <ll> x;
void do_A(){
	cin >> n >> d;
	x.resize(n);
	for (auto &i : x) cin >> i;
	ll x_d = x[1] - x[0]; // 公差
	if (x_d >= d){
		cout << "0\n";
		return ;
	}
	ll x_p = d / x_d; // 一次性飞过多少岛
	cout << max(n - (2 * x_p - 1), 0ll) << '\n';
}

ll brute_ans1 = 2e18;
map <ll, int> brute_cnt;
void dfs(int where, int to, ll cost){
//	cout << where << ' ' << cost << '\n';
	if (where == to){
		brute_cnt[cost] ++;
		brute_ans1 = min(brute_ans1, cost);
	}
	if (cost > brute_ans1) return ;
	for (int i = where + 1; i <= to; i ++){
		if (x[i] - x[where] <= d) dfs(i, to, cost + 1);
		else break;
	}
	return ;
}
bool is_it(int u, int v){
	brute_ans1 = 2e18; brute_cnt.clear();
	dfs(u, v, 0);
	if (brute_cnt[brute_ans1] == 2) return 1;
	return 0;
}
void do_brute(){
	cin >> n >> d; x.resize(n);
	for (auto &i : x) cin >> i;
	int ans = 0;
	for (int i = 0; i < n; i ++){
		for (int j = i + 1; j < n; j ++){
			ans += is_it(i, j);
//			cout << "as for (u, v) = " << i << ", " << j << ":\n";
//			for (auto p : brute_cnt){
//				cout << "WW:" << p.first << ' ' << p.second << '\n';
//			} 
		}
	}
	cout << ans << '\n';
}

vector <vector <int>> F;
ll abss(ll x){
	return x * (x < 0 ? -1 : 1);
}
void do_floyd(){
	cin >> n >> d; x.resize(n);
	for (auto &i : x) cin >> i;
	F.resize(n); for (auto &vec : F) vec.resize(n);
	int ans = 0;
	
	vector <vector <vector <int>>> Ff(n);
	for (auto &vec : Ff) vec.resize(n);
	for (int i = 0; i < n; i ++){
		for (int j = i + 1; j < n; j ++){
			if (x[j] - x[i] <= d){
				F[i][j] = 1;
				Ff[i][j] = {i, j};
			}
		} 
	}
	for (int i = 0; i < n; i ++){
		F[i][i] = 0; Ff[i][i].clear();
		for(int j = i + 1; j < n; j ++){
			if (F[i][j] != 1) F[i][j] = -1, Ff[i][j].clear();
		}
	}
	
	for (int i = n - 2; i >= 0; i --){
		for (int j = i + 1; j < n; j ++){
			for (int k = i + 1, leng; k < j; k ++){
				leng = F[i][k] + F[k][j];
				if (leng < 0) continue; 
				if (leng < F[i][j] || F[i][j] < 0){
					F[i][j] = leng;
					cout << "New F" << i << "," << j << "/ that k = " << k << "/ pre:"; for (auto p : Ff[i][j]) cout << p << ' '; cout << '\n';
					Ff[i][j].clear();
					for (auto px : Ff[i][k]) Ff[i][j].push_back(px); Ff[i][j].pop_back();
					for (auto px : Ff[k][j]) Ff[i][j].push_back(px);
					cout << "now:"; for (auto p : Ff[i][j]) cout << p << ' '; cout << '\n';
				}
			}
		}
	}
	
	for (int i = 0; i < n; i ++){
		for (int j = i + 1; j < n; j ++){
			cout << i << ' ' << j << "L:";
			for (auto p : Ff[i][j]) cout << p << ' ';
			cout << '\n';
		}
	}
	
	for (int i = 0; i < n; i ++){
		for (int j = i + 1, res = 1; j < n; j ++){
			for (int k = i + 1, leng; k < j; k ++){
				leng = F[i][k] + F[k][j];
				if (leng == F[i][j]){
					vector <int> tmp;
					for (auto p : Ff[i][k]) tmp.push_back(p); tmp.pop_back(); 
					for (auto p : Ff[k][j]) tmp.push_back(p);
					if (tmp != Ff[i][j]){
						++ res;
						cout << "ANOTHER:" << i << ' ' << k << ' ' << j << ":";
						for (auto p : tmp) cout << p << ' '; cout << '\n'; 
					}
				}
				if (res > 2) break;
			}
			ans += (res == 2);
			if (res == 2) cout << "BINGO:" << i << ' ' << j << '\n'; 
		}
	}
	
	cout << ans << '\n';
} 

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t; cin >> c >> t;
	if (c == 11 || c == 12){
		while (t --) do_A(); // 8pts
	}else{
		while (t --) do_brute(); // 8pts
	}

	return 0;
}

/*
3 2
6 3
0 1 2 3 4 7
8 3
0 1 2 4 8 10 11 13
*/
