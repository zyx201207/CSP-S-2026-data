#include <bits/stdc++.h>
using namespace std;
bool p[200005][35];
int pp[200005]; 
vector < int > ch;
int cnt[35], a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		int m;
		scanf("%d", &m);
		a[i] = m;
		int t = 0;
		while (m)
		{
			int r = m % 2;
			m /= 2;
			p[i][t] = r;
			cnt[t] += r;
			t++;
		}
	}
	int ans = -1;
	for (int i = 30; i >= 0; i--)
	{
		if (cnt[i] >= k)
		{
			ans = i;
			break;
		}
	}
	if (ans == -1)
	{
		printf("0");
		return 0;
	}
	int num = 0;
	for (int i = 1; i <= n; i++)
		if (p[i][ans] == 1) ch.push_back(i), num++;
	int t = num;
	while (num > k && ans > 0)
	{
		ans--;
		for (int i : ch)
		{
			if (pp[i]) continue;
			if (p[i][ans] == 0)
			{
				num--;
				pp[i] = 1;
			}
		}
		if (num < k)
		{
			num = t;
			for (int i : ch)
				if (pp[i] == 1) pp[i] = 0;
		}
		else if (num > k)
		{
			t = num;
			for (int i : ch)
				if (pp[i] == 1) pp[i] = 2;
		}
	}
	int q = 0;
	int answ = INT_MAX;
	for (int i : ch)
	{
		if (q == k) break;
		if (pp[i] == 0)
		{
			q++;
			answ = answ & a[i];
		}
	}
	printf("%d", answ);
	return 0;
}
