#include<iostream>
#define int long long
using namespace std;
const int maxn = 5e3+100;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cout << n * (n+1) / 2;
}
