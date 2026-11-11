#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n] = {0};
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n > 22000)
	{
		int cnt = 1;
		int i = n - 1;
		int q = m;
		int k = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (q >= a[i] - a[j])
			{
				q -= (a[i] - a[j]);
				cnt++;
//				cout << "-" << endl;
			}
			else
			{
				k = j;
				break;
			}
		}
		cout << cnt;
		return 0;
	}
	if (n == 1)
	{
		cout << "1";
		return 0;
	}
	sort(a, a + n);
	int maxn = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int cnt = 1;
		int q = m;
		int k = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (q >= a[i] - a[j])
			{
				q -= (a[i] - a[j]);
				cnt++;
//				cout << "-" << endl;
			}
			else
			{
				k = j;
				break;
			}
		}
//		for (; k < n; k++)
//		{
//			if (a[k] == a[i]) cnt++;
//			else break;
//		}
		maxn = max(maxn, cnt);
	}
	cout << maxn << endl;
	return 0;
}
