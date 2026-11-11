#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m,ans,ans2 = -111111,a[200005];
	cin >> n >> m;
	cin >> a[1];
	ans = a[1];
	for(int i = 2;i <= n;i++)
	{
		ans &= a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		ans2 = max(ans & a[i],ans2);
	}
	cout << ans2;
	return 0;
}
