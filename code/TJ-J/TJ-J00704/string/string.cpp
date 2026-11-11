#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int n,num;
long long a[200001],cnt[200001];
char b[200001];
char ff(int k)
{
	if (k < cnt[1])
	{
		return b[1];
	}
	if (k == cnt[n])
	{
		return b[n];
	}
	for (int i = 1; i < n; i++)
	{
		if (cnt[i] <= k&&cnt[i+1] > k)
		{
			return b[i];
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cin >> b[i];
		cnt[i] = cnt[i-1] + a[i];
	}
	for (int i = 1; i <= cnt[n]/2; i++)
	{
		if(ff(i) != ff(cnt[n]+1-i))
		{
			num++;
		}
	}
	cout << num;
	return 0;
}
