#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[500005],maxn = -2e9;
void st1()
{
	//sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		int cnt = m,ans = 0;
		for(int j = i;j >= 1;j--)
		{
			if(abs(a[i] - a[j]) <= cnt)
			{
				ans++;
				cnt = cnt - (a[i] - a[j]);
			}
			else
			{
				/*if(maxn < ans)
				{
					cout << a[i] << endl;
				}*/
				maxn = max(ans,maxn);
				break;
			}
			maxn = max(ans,maxn);
		}
	}
	cout << maxn;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m; 
	bool fla = 1,flb = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != i)fla = 0;
	}
	if(fla)
	{
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			if(cnt + i <= m)cnt += i;
			else
			{
				//cout << "aaaa";
				cout << i;
				return 0;
			}
		}
	}
	sort(a + 1,a + n + 1);
	int q = abs(a[2] - a[1]);
	for(int i = 3;i <= n;i++)
	{
		if(abs(a[i] - a[i - 1]) != q)flb = 0;
	}
	if(flb)
	{
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			//cout << "nm\n";
			if(cnt + (q * i) <= m)cnt += q * i;
			else
			{
				cout << i;
				//cout << "bbbb";
				return 0;
			}
		}
	}
	else
	{
		st1();
		//cout << "ccc";
		return 0;
	}
	return 0;
}

