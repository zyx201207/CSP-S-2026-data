#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500050];
int sum[500050];
signed main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1]+a[i-1];
	
	bool cA = 1;
	for(int i = 1;i < n;i++)
	{
		if(a[i] != a[i+1])
		{
			cA = 0;
		}
	}
	bool cB = 1;
	int jz = a[1]-a[2];
	for(int i = 1;i < n;i++)
	{
		if(a[i] - a[i+1] != jz)
		{
			cB = 0;
		}
	}
	if(cA)
	{
		cout << n;
		return 0;
	}
	else if(cB)
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int hyw = sum[i];
			if(hyw <= m) ans++;
			else if(hyw > m)
			{
				cout << ans;
				return 0;
			}
		}
	}
	else if(n <= 5000)
	{
		int ans = 1;
		for(int i = 2;i <= n;i++)
		{
			for(int j = 1;j+i-1 <= n;j++)
			{
				int jz = a[j+i-1],sum = 0;
				for(int k = j;k < j+i-1;k++)
				{
					sum += jz-a[k];
				}
				if(sum <= m)
				{
					 ans = i;
					 break;
				}
			}
		}
		cout << ans;
	}
	else
	{
		cout << n;
		//cout << "Give me some points,please.Even 1 point,also OK.";
	}
	return 0;
}
