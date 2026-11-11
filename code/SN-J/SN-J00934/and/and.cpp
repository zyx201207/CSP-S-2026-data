#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int a[200010];

void solve()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N, [](int x, int y){ return x > y; });
	int ans = a[1];
	for(int i = 2; i <= M; i++) ans &= a[i];
	cout << ans;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	solve();
	return 0;
}

