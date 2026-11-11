#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
long long n = 1e6, m = 1e18 + 5, ans = 0;
long long a[N], op[N] = {0};
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(long long i = 1; i <= n; i ++)
	{
		cin>>a[i];
	}
	if(n > 5000)
	{
		int flag = 1;
		for(int i = 2; i <= n; i++)
			if(a[i] != a[i - 1])
			{
				flag = 2;
				break;
			}
		if(flag == 1)
		{
			cout<<n<<endl;
			return 0;
		}
		int id = a[2] - a[1];
		for(int i = 2; i <= n; i++)
		{
			if(a[i] - a[i - 1] != id)
			{
				flag = 3;
				break;
			}
		}
		if(flag == 2)
		{
			cout<<m / id + 1;
			return 0;
		}
	}
	op[1] = 0, op[2] = a[2] - a[1];
	for(long long i = 3; i <= n; i ++)
	{
		op[i] = op[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	 } 
	for(long long i = 1; i <= n; i ++)
	{
		for(long long k = i; k <=n; )
		{
			int sum = (op[k] - op[i]) / i;
			if(sum <= m)
			{
				ans = max(k - i + 1, ans);
				k ++;
			}
			else
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
 } 
