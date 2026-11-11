#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m, a[N], res[N], ans, now;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	now = 1;
	for(int i = 1; i <= n; i++)
	{
		res[i] = res[i - 1] + a[i];
		while((i - now + 1) * a[i] - (res[i] - res[now - 1]) > m)
		{
			now++;
		}
		ans = max(ans, i - now + 1);
//		cout << "!" << now << endl;
	}
	cout << ans;
	return 0;
}
