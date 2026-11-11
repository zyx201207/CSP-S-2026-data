#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
ll n, m, ans;
ll a[N], b[N];
ll mp1[N];
ll pre[N];
ll cnt[N], sum[N];
map<ll, ll> mp2;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int x = unique(b + 1, b + n + 1) - b - 1;	//离散化 
	for(int i = 1; i <= x; i ++)
	{
		mp1[i] = b[i];	//表示i号对应b[i] 
		mp2[b[i]] = i;	//表示b[i]的编号为i 
	}
	for(int i = 1; i <= n; i ++) cnt[mp2[a[i]]] ++;	//编号为i的数出现次数 
	for(int i = 1; i <= x; i ++) sum[i] = sum[i - 1] + cnt[i];	//编号为1 to i的宝石数 
	for(int i = 1; i <= x; i ++) pre[i] = pre[i - 1] + cnt[i] * mp1[i];
	for(int i = 1; i <= x; i ++)
	{
		int idx = i;
		int left = 1, right = i, mid;
		while(left <= right)
		{
			mid = (left + right) / 2;
			if(mp1[i] * (sum[i - 1] - sum[mid - 1]) - (pre[i - 1] - pre[mid - 1]) <= m)
			{
				idx = mid;
				right = mid - 1;
			}
			else left = mid + 1;
		}
		ll res = m - (mp1[i] * (sum[i - 1] - sum[idx - 1]) - (pre[i - 1] - pre[idx - 1]));
		ll curr = sum[i] - sum[idx - 1];
		if(idx != 1) curr += (res / (mp1[i] - mp1[idx - 1]));
		ans = max(ans, curr);
	}
	cout << ans << "\n";
	return 0;
}
