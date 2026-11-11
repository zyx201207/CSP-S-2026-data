// 西安市铁一中学 王正清和 SN-S00336
#include<bits/stdc++.h>
#define fir first
#define sec second
#define mkp make_pair
#define ll long long
using namespace std;
int aqx = 1;

const int maxn = 500000;
int n, m;
ll A[maxn + 10], Q[maxn + 10];
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
void wangzqh()
{
	cin>> n >> m;
	for (int i = 1;i <= n;i++) cin >> A[i];
	sort(A + 1, A + n + 1);
	for (int i = 1;i <= n;i++) Q[i] = Q[i - 1] + A[i];
	
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		int l = 1, r = i, tt = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (A[i] * (i - mid + 1) - (Q[i] - Q[mid - 1]) <= m) r = mid - 1, tt = mid; 
			else l = mid + 1;
		}
		ans = max(ans, i - tt + 1);
	}
	cout << ans << "\n"; 
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	init();
	aqx = 1;
	while (aqx--) wangzqh();
	return 0;
}
