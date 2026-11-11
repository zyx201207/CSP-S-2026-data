#include<bits/stdc++.h>
using namespace std;

long long a[500010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1,a + n + 1);
	int ans = 0;
	long long sum = 0;
	for(int i = 1,j = 1;i <= n;i++)
	{
		sum += (a[i] - a[i - 1]) * (i - j);
		while(sum > m)sum -= (a[i] - a[j]),j++;
		ans = max(ans,i - j + 1);
	}
	cout << ans;
	return 0;
}
