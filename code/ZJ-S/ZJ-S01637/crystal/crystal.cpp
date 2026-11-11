#include <iostream>
#include <algorithm>
#include <cstdio> 
#define int long long
using namespace std;

int n, m;
int nlist[1000000];
int qz[1000000];

int get_sum(int l, int r)
{
	if (l == 0) return qz[r];
	return qz[r] - qz[l - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> nlist[i];
	}
	sort(nlist, nlist + n);
	qz[0] = nlist[0];
	for (int i = 1; i < n; i++)
	{
		qz[i] = qz[i - 1] + nlist[i];
		//cout << qz[i] << endl;
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		int k = nlist[i];
		int left = 0, right = i - 1, mid = 0, ans = -1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if ((i - mid) * k - get_sum(mid, i - 1) <= m)
			{
				ans = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		if (ans != -1)
			answer = answer > (i - ans + 1) ? answer : (i - ans + 1);
		//cout << ans << " " << i - ans + 1 << endl;
	}
	cout << answer << endl;
	return 0;
 } 
//Furina Furina Furina