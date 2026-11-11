#include<bits/stdc++.h>
using namespace std;
int n, m, nxt1[500005], tmp[300005], nxt2[500005], a[500005], ans[500005], b[500005], cnt[500005], _ans[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> b[i];//, cnt[i] = 1;
	int tot = 0;
	for(int i = 1; i <= n; i++)
	{
		if(b[i] != a[tot])a[++tot] = b[i], cnt[tot] = 1;
		else cnt[tot]++;
	}
	n = tot;
	for(int i = n; i >= 1; i--)
	{
		if(tmp[a[i]] == 0)tmp[a[i]] = i;
		nxt1[i] = tmp[a[i]];
		//tmp[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		int j = i;
		for(; j <= n && nxt1[j] == j; j++);
		for(int k = j - 1; k >= i; k--)nxt2[k] = j;
	}
	for(int j = 1; j <= n; j++)
	{
		int i = j;
		while(i <= n)
		{
			i = nxt1[i];
			ans[i] += cnt[j], ans[nxt2[i]] -= cnt[j], i = nxt2[i];
		}
	}
	for(int i = 1; i <= n; i++)ans[i] += ans[i - 1], _ans[a[i]] += ans[i];
	for(int i = 1; i <= m; i++)cout << (int)_ans[i] << ' ';
	//cout << nxt2[n];
	return 0;
}
