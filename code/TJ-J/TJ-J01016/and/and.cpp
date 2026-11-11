#include <bits/stdc++.h>
using namespace std;

long long ans;

long long ij(long long ai,long long m,long long ai2)
{
	return ans += ai and ij(ai2,m - 1,ai2+1);
}

int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	
	long long n,m,a[20005],nowmax = 0;
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		long long now = ij(i,m,i + 1);
		if(now > nowmax)
		{
			nowmax = now;
		}
	}
	return 0;
}
