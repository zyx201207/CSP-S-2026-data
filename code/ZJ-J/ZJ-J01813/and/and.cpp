#include <bits/stdc++.h>
using namespace std;
bool flag = 1;
int n, m, a[200005], max_l = 0, pos[200005], ans_l, for_l;
string s[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for_l = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int temp_int = a[i];
		string temp_s = "";
		while (temp_int > 0)
		{
			temp_s += '0' + (temp_int % 2);
			temp_int /= 2;
		}
		if (temp_s.size() > max_l) max_l = temp_s.size();
		for (int j = temp_s.size() - 1; j >= 0; j--) s[i] += temp_s[j];
	}
	for (int i = 1; i <= n; i++)
	{
		while (s[i].size() < max_l) s[i] = '0' + s[i];
	}
	
	int maxx = 0;
	for (int i = 1; i <= max_l; i++)
	{
		memset(pos, 0, sizeof(pos));
		int temp_sum = 0;
		for (int j = 1; j <= for_l; j++)
		{
			if (s[j][i - 1] == '1')
			{
				temp_sum++;
				pos[temp_sum] = j;
			}
		}
		if (temp_sum == m)
		{
			int ans = a[pos[1]];
			for (int k = 2; k <= temp_sum; k++) ans = (ans & a[pos[k]]);
			cout << ans;
			return 0;
		}
		if (temp_sum > m)
		{
			flag = 0;
			for_l = temp_sum;
			int b[200005] = {0};
			for (int k = 1; k <= temp_sum; k++) b[k] = a[pos[k]];
			memset(a, 0, sizeof(a));
			for (int k = 1; k <= temp_sum; k++) a[k] = b[k];
		}
	}
	if (flag) cout << 0;
	else cout << pow(2, max_l - 1) - 1;
	return 0;
}
