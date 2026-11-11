#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iomanip>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

ll X[MAXN], d;
int n, F[MAXN];

void Solve_1() {
	cin >> n >> d;
	for(int i = 1; i <= n; i ++) cin >> X[i];
	return cout << 0 << "\n", void();
}

void Solve_2() {
	cin >> n >> d;
	for(int i = 1; i <= n; i ++) cin >> X[i];
	if(X[2] - X[1] >= d || n == 1) return cout << 0 << "\n", void();
	ll len = d / (X[2] - X[1]);
	len = len * (ll)2;
	if(len > (ll)n) return cout << 0 << "\n", void();
	cout << ((ll)n - len + (ll)1) << "\n";
	return ;
}

int main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c, t; cin >> c >> t;
	if(c == 11 || c == 12) while(t --) Solve_2();
	else while(t --) Solve_1();
	
	return 0;

}


