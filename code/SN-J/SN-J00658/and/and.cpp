//白屹桐  西安辅轮中学  SN-J00658
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
int n, m, x, y, maxn = -1;
int a[N], b[N], sum[N] = {1};

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << a[n];

	return 0;
}


