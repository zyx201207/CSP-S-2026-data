#include <bits/stdc++.h>
using namespace std;
int n,maxn;
long long a[500005],m;
bool cmp(long long a,long long b)
{
	return a<b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1,cmp);
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			int sum=0,m1=m;
			for(int j=i;j>0;j--)
			{
				if(m1>=(a[i]-a[j]))
				{
					sum++;
					m1=m1-(a[i]-a[j]);
				}
				else
					break;
			}
			maxn=max(maxn,sum);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(m<(a[i]-a[1])*i/2)
			{
				maxn=i-1;
				break;
			}
		}
	}
	cout << maxn;
	return 0;
} 