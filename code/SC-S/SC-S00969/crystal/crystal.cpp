#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long m1=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int mx=0;
	for(int j=2;j<=n;j++)
	{
		int ans=1;
		for(int i=j;i<=n;i++)
		{
			if(m>=(a[i]-a[i-1])*ans)
			{
				m-=((a[i]-a[i-1])*ans);
				ans++;
			}
			else
			{
				break;
			}
		}
		mx=max(mx,ans);
		m=m1;
	}
	cout<<mx;
	return 0;
}