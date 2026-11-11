#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],qian[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		qian[i]=qian[i-1];
		qian[i]-=a[i];
	}
	long long maxn=0,dai;
	for(int i=1;i<=n;i++)
	{
		long long l=1,r=i;
		while(l<r)
		{
			long long mid=(l+r)/2;
			dai=qian[i]-qian[mid-1]+a[i]*(i-mid+1);
			if(dai<=m)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn<<'\n';
	return 0;
}
