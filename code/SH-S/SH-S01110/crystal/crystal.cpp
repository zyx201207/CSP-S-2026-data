#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n;
long long m;

long long a[N];
long long sum = 0;
int ans = 0;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int j = 1;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		while ((i - j + 1) * a[i] - sum > m)
		{
			sum -= a[j++];
		}
		ans = max(ans, i - j + 1);
	}
	
	cout << ans;
	
	return 0;
}
