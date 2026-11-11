#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<int> a(n + 1);
	vector<char> c(n + 1);
	int mid = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		mid += a[i];
	}
	mid >>= 1;
	//cout << mid << endl;
	
	vector<int> a1, a2;
	vector<char> c1, c2;
	int lst = 0;
	for (int i = 1; i <= n; i++)
	{
		if (lst + a[i] <= mid)
		{
			a1.push_back(a[i]);
			c1.push_back(c[i]);
			lst += a[i];
		}
		else if (lst + a[i] > mid)
		{
			if (mid - lst)
			{
				a1.push_back(mid - lst);
				c1.push_back(c[i]);
				//cout << "sb " << i << " " << c[i] << "\n";
			}
			break;
		}
	}
	
	lst = 0;
	for (int i = n; i >= 1; i--)
	{
		//cout << "sb " << i << " " << c[i] << "\n";
		if (lst + a[i] <= mid)
		{
			a2.push_back(a[i]);
			c2.push_back(c[i]);
			lst += a[i];
			//cout << lst << "\n";
		}
		else if (lst + a[i] > mid)
		{
			a2.push_back(mid - lst);
			c2.push_back(c[i]);
			
			break;
		}
	}
	/*
	for (int i : a1) cout << i << " ";
	cout << "\n";
	for (char i : c1) cout << i << " ";
	cout << "\n";
	for (int i : a2) cout << i << " ";
	cout << "\n";
	for (char i : c2) cout << i << " ";
	cout << "\n";
	*/
	int cur = 0;
	int up = 0, dn = 0;
	int id1 = 0, id2 = 0;
	int ans = 0;
	while (id1 < (int)a1.size() && id2 < (int)a2.size())
	{
		up = cur + a1[id1];
		dn = cur + a2[id2];
		if (up == dn)
		{
			if (c1[id1] != c2[id2]) ans += a1[id1];
			cur = up;
			id1++; id2++;
		}
		else if (up > dn)
		{
			if (c1[id1] != c2[id2]) ans += a2[id2];
			a1[id1] -= a2[id2];
			cur = dn;
			id2++;
		}
		else if (up < dn)
		{
			if (c1[id1] != c2[id2]) ans += a1[id1];
			a2[id2] -= a1[id1];
			cur = up;
			id1++;
		}
		//cout << cur << " " << ans << "\n";
	}
	cout << ans << "\n";
	
	return 0;
}
