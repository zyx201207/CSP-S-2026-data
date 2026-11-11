#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=0;
	if(n<5000)
	{
		for(int i=1;i<=n;i++)
		{
			long long cnt=1,tm=m;
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]-a[j]<=tm)tm-=a[i]-a[j],cnt++;
			}
			ans=max(cnt,ans);
		}
		cout<<ans<<endl;
		return 0;
	}
	bool f1=1,f=1;
	for(int i=1;i<=n&&f1;i++)if(a[i]!=i)f1=0;
	for(int i=2;i<n&&f;i++)if(a[i]-a[i-1]!=a[i+1]-a[i])f=0;
	if(f1)
	{
		for(long long i=1;i<=n;i++)
		{
			if(m<i*(i+1)/2)
			{
				ans=i;
				break;
			}
		}
	}
	else if(f)
	{
		for(long long i=1;i<=n;i++)
		{
			if(m<i*(i+1)/2*(a[i]-a[i-1]))
			{
				ans=i;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
