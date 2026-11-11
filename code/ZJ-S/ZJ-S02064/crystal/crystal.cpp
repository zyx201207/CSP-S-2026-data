#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define ll long long
using namespace std;
bool o = 0;
int n,m,a[1000001],mid = 1e6,num,b[1000001],f[1000001],sum = 0,p[1000001],ans = 0; 
int diff (int x)
{
	int res = 0;
	for (int i = 1;i <= n;i ++)
	{
		b[i] = x;
	}
	for (int i = 1;i <= n;i ++)
	{
		if (a[i] != b[i])res+=abs(a[i]-b[i]);
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
//	dfs(1,0);
	for (int i = 1;i <= n;i ++)
	{
		f[i] = diff(a[i]);
	//	cout << f[i] << ' '; 
	}
	for (int i = 1;i <= n-1;i ++)
	{
		if (mid > f[i])
		{
			mid = f[i];
			num = a[i];
		}
	}
//	cout << num << ' ' << mid;
	for(int i = 1;i <= mid;i ++)
	{
		p[i] = abs(a[i] - num);
	}
//	cout << num << endl;
	sort (p+1,p+1+mid);
	for (int i = 1;i <= n; i++)
	{
		if (sum > m)
		{
			ans--;
			o = 1;
		//	cout << endl << ans << endl;
			break;
		}
		
		sum += p[i];
		ans++;
		//cout << sum << ' ' << ans << endl;
	} 
	if (o == 0)ans--;
	cout << ans;
	return 0; 
}
//第一题的取中间值看运气算法 
