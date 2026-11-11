#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N],sum[N];
bool cmp(long long a,long long b)
{
	return a < b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	//A
	if(a[1] == a[n]) 
	{
		cout << n;
		return 0;
	}
	
	//B
	int d = a[2] - a[1];
	bool flag = true;
	for(int i = 3; i <= n; i ++)
	{
		if(a[i] - a[i - 1] != d)
		{
			flag = false;
			break;
		}
	}
	
	if(flag)
	{
		int ans;
		for(int i = 1; i <= n; i ++)
		{
			if(m - d * (i - 1) >= 0)
			{
				m -= d * (i - 1);
			}
			else
			{
				ans = i - 1;
				break;
			}
		}
		cout << ans;
		return 0;
	}
	
	for(int i = 1; i <= n; i ++)
	{
		sum[i] = sum[i - 1] + a[i];
		//cout << sum[i] << ' ';
	}
	int ans = 1;
	for(int i = n; i >= 1; i --)
	{
		for(int j = i - 1; j >= 1; j --)
		{
			long long target = a[i] * (i - j + 1);
			if(target <= sum[i] - sum[j - 1] + m)
			{
				ans = max(ans,i - j + 1);
				//cout << target << "%%" << i << "%%%" << j << '\n';
			}
		}
	}
	cout << ans;
	return 0;
}
