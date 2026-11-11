#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 * 2 + 5;
int n;
int a;
char c;
char x[maxn];
char y[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	int cnt = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a >> c;
		while(a--)
		{
			x[cnt] = c;
			y[cnt] = c;
			cnt++;
		}
	}
	cnt--;
	int mid;
	if(cnt % 2 == 0)
	{
		mid = cnt / 2;
		for(int i = 1 ; i <= mid ; i++)
		{
			y[cnt + 1 - i] = y[i];
		}
	}
	else
	{
		mid = (cnt + 1) / 2;
		for(int i = 1 ; i < mid ; i++)
		{
			y[cnt + 1 - i] = y[i];
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= cnt ; i++)
	{
		if(x[i] != y[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
