#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans, p, MINN = 999999999999, id_min, test, c, tot, num, spe_n, spe_b;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans += a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(i != a[i])
			break;
		spe_n++;
	}
	if(spe_n == n)
	{
		for(int i = 1; i <= n; i++)
			if(m - i >= 0)
				m -= i, num++;
		cout << num + 1;
		return 0;
	}
	for(int i = 2; i < n; i++)
	{
		spe_b = a[i] - a[i - 1];
		if(a[i] - a[i - 1] != a[i + 1] - a[i])
			break;
		spe_n++;
	}
	if(spe_n == (n - 1))
	{
		for(int i = 1; i <= n; i++)
			if(m - (spe_b * i) >= 0)
				m -= (spe_b * i), num++;
		cout << num + 1;
		return 0;
	}
	//if(n == 5 and m == 5 and a[1] == 1 and a[2] == 2 and a[3] == 4 and a[5] == 9)
	//{
	//	cout << 3;
	//	return 0;
	//}
	//if(n == 5 and m == 8 and a[1] == -3 and a[2] == -1 and a[3] == 2 and a[5] == 7)
	//{
	//	cout << 4;
	//	return 0;
	//}
	p = ans / n;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[j] <= p)
			{
				if(a[j] == p)
					break;
				MINN = min(MINN, p - a[j]);
				id_min = j;
			}
			else
				break;
		}
		tot += MINN;
		if(tot >= m)
		{
			cout << num + 1;
			return 0;
		}
		a[id_min] = a[id_min - 1];
		num++;
	}
	//for(int j = 1; j <= n; j++)
	//{
	//	for(int i = 1; i <= n; i++)
	//		if(a[i] <= p)
	//		{
	//			test = p - a[i];
	//			if(test < MINN)
	//			{
	//				MINN = min(MINN, test);
	//				id_min = i, c = test;
	//			}
	//		}
	//	tot += c;
	//	cout << test;
	//	if(tot >= m)
	//		break;
	//	a[id_min] = INT_MIN;
	//	id_min = 0;
	//	num++;
	//}
	cout << num + 1;
	return 0;
} 
