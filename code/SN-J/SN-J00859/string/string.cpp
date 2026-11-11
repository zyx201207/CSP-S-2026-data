#include <bits/stdc++.h>
using namespace std;
const int Max = 2e5 + 5;
int n;
int a[Max];
char c[Max];
char S[Max];
bool check(int siz)
{
	int i = 0,j = siz - 1;
	while(i < j)
	{
		if(S[i] != S[j]) return 0;
		i++; j--;
	}
	return 1;
}
int num(int siz)
{
	int ans = 0;
	int i = 1,j = siz;
	while(i < j)
	{
		if(S[i] != S[j]) ans++;
		i++; j--;
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	bool flag1 = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		if(a[i] != 1) flag1 = 0;
	}
	if(n == 1)
	{
		cout << 0 << "\n";
		return 0;
	}
	else if(n == 2)
	{
		cout << min(a[1],a[2]) << "\n";
		return 0;
	}
	else if(flag1 == 1)
	{
		cout << n / 2 << "\n";
		return 0;
	}
	else
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = cnt + 1; j <= cnt + a[i]; j++)
			{
				S[j] = c[i];
			}
			cnt += a[i];
		}
		if(check(cnt))
		{
			cout << "0\n";
			return 0;
		}
		else
		{
			cout << num(cnt) << "\n";
			return 0;
		}
	}
	return 0;
}
