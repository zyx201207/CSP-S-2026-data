#include<bits/stdc++.h>
using namespace std;
long long a[N],n,m;
unsigned long long dp[N],f[N];
int main()
{
	preopen("crystal.in","r"stdin)
	preopen("crystal.out","w"stdout) 
	cin >> n >> m;
	for(long long i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(long long i = 1 ; i <= n ; i++)
	{
		b[i] = a[a + 1] - a[i];
		cout << b[i] << " ";
	}
	cout << "\n";
	for(long long i = 1 ; i <= n ; i++)
	(
		int sum = 0;
		for(long long j = 1 ; j <= n ; j++)
		{
			sum += b[j]*(j - i + 1);
			if(sum > n)
			{
				ans = max(ans,j - i + 1);
				break;
			}
		}
	}
	
	cout << ans;
	return 0;
}
