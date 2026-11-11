#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long a[200005],n,sum[200005];
	sum[0] = 0;
	char c[200005];
	cin >> n;
	long long cnt2 = n,cnt1 = 1,ans = 0;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		sum[i] = a[i] + sum[i - 1];
	}
	long long l = sum[n];
	for(long long i = 1;i <= l / 2;i++)
	{
		if(i > sum[cnt1])
		{
			cnt1++;
		}
		if((l - i + 1) <= sum[cnt2 - 1])
		{
			cnt2--;
		}
		if(c[cnt1] != c[cnt2])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
