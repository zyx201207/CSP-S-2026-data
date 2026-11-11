#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],diff[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int ptr = 1;
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		diff[i] = a[i]-a[i-1];
	}
	int ans = 0,now = 0;
	for(int i = 1;i <= n;i++)
	{
		while(ptr <= n)
		{
			if(now+diff[ptr+1]*(ptr-i+1) > m)break;
			ptr++;
			now += diff[ptr]*(ptr-i);
		}
		ans = max(ans,ptr-i+1);
		now -= a[ptr]-a[i];
	}
	cout << ans;
	return 0;
}
