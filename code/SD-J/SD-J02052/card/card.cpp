#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 5;
int a[N];
struct No
{
	bool z;
	int i;
};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	bool p1 = 1;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] < a[i - 1]) p1 = 0;
	}
	if (p1)
	{
		for (int i = 1;i <= m;i++)
		{
			cout << i << " ";
		}
		return 0;
	}
	vector <int> ans(m + 5);
	for (int i = 1;i <= n;i++)
	{
		vector <int> v(n + 5);
		map <int,No> mp;
		int ii = 0,lsti = 0;
		for (int j = i;j <= n;j++)
		{
			if (mp[a[j]].z)
			{
//				cout << "i:" << j <<",cao:" << a[j] << "\n";
				lsti = ii;
				ii = mp[a[j]].i;
				for (int k = ii;k <= lsti;k++)
				{
//					mp[v[k]].z = 0;
					v[k] = 0;
				}
			}
			v[ii] = a[j];
			mp[a[j]].z = 1;
			mp[a[j]].i = ii;
			ii++;
		}
		for (auto it : v)
		{
//			cout << it << " ";
			if (it == 0 || !mp[it].z) continue;
			ans[it]++;
//			cout << it << " ";
		}
//		cout << "\n";
	}
	for (int i = 1;i <= m;i++)
	{
//		if (ans[i] == 0) continue;
		cout << ans[i] << " ";
	}
	return 0;
}
