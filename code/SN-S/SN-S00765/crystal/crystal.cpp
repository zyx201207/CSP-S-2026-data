#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,a[1000005],b[500005],sum2,sum1;
bool ch(long long t)
{
	for(int i = t;i <= n;i++)
	{
		if(abs(b[i] - b[i - t] - a[i] * t) <= m)
			return 1;	
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	l = 1;
	r = n + 5;
	for(int i = 1;i <= n;i++)
	{
		b[i] = b[i - 1] + a[i];
	}
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(ch(mid))
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}	
	}
	if(!ch(mid))
	{
		mid--;
	}
	cout << mid;
	return 0;
}	
