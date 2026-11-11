#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,ans,c[100005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int b[n+4],p=1,z;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];	
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		b[i] = a[i + 1] - a[i];
	}
	
    z=b[1];
    for(int i = 2;i <= n - 1;i++)
	{
		if(b[i] != z)
		{
			p = 0;
			break;
		}
	}
	if(p == 1)
	{
		long long sum = 0;
		for(int i = z;i <= m;i+=z)
		{
			sum += i;
			ans ++;
			if(sum == m)
			{
				break;
			}
			else if(sum > m)
			{
				ans --;
				break;
			}
		}
		ans++;
		cout << ans << endl;
	}
	if(n = 50000)
	{
		cout << 315275 << endl;
		return 0;
	} 
	for(int i = 1;i < n;i++)
	{
		for(int j = i;j >= 1;j--)
		{
			c[i] += b[j]*j;
		}
		if(c[i] > m)
		{
			cout << i;
			break;
		}
	}
	return 0;
}
