#include <bits/stdc++.h>
using namespace std;
int n,m,cnt[200003],ans = 0;
long long a[200003],b[200003];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		int p = a[i];
		while(p > 0)
		{
			cnt[i] += p % 2;
			p /= 2;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <=n;j++)
		{
			if(cnt[j+1]> cnt[j])
				{
					swap(cnt[j+1],cnt[j]);
					swap(a[j],a[j+1]);
				}
			if(a[j+1]> a[j] && cnt[j+1] == cnt[j])
				{
					swap(cnt[j+1],cnt[j]);
					swap(a[j],a[j+1]);
				}
		}
	}
	ans = a[1];
	for (int i = m;i > 0;i--)
		ans &= a[i];
	cout << ans;
	return 0;
}