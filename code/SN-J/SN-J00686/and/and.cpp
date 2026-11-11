//liuyixi xi an shi han guang zhong xue SN-J00686
#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}
int main()
{

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	if(n <= 20 && m != 1 && m != n && m != 2 && m!=n-1)
	{
		int a[1010];
		for(int i = 1;i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a+1,a+1+n,cmp);
		int ans = a[1];
		for(int i = 2; i <= m; i++)
		{
			ans = ans&a[i];
		}
		cout << ans;
		return 0;
	}	
	else if(m == 1)
	{
		int maxn = INT_MIN;
		for(int i = 1; i<=n;i++)
		{
			int x;
			cin >> x;
			maxn = max(maxn,x);
		}
		cout << maxn;
		return 0;
	}
	else if(m == n)
	{
		int x;
		cin >> x;
		for(int i = 2; i<=n;i++)
		{
			int xx;
			cin >> xx;
			x = x&xx;
		}
		cout << x;
		return 0;
	}
	else if(m == 2)
	{
		int ans = INT_MIN;
		int a[2500];
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i+1; j <= n; j++)
			{
				int x = a[i] & a[j];
				ans = max(ans,x);
			}
		}
		cout << ans;
		return 0;
	}
	else if(m == n-1)
	{
		int ans;
		int a[2500];
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int x = a[2];
		for(int i = 3; i <= n; i++)
		{
			x = x & a[i];
			//cout << x << " ";
		}
		ans = max(ans,x);
		//cout << ans;
		x = a[1];
		for(int i = 2; i <= n; i++)
		{
			for(int j = 2; j <= n; j++)
			{
				if(j == i) continue;
				else 
				{
					x = x&a[j];
				}
			}
			ans = max(ans,x);
		}
		cout << ans;
		return 0;
	}
	else
	{
		cout << 1;
	}
	return 0;
}
