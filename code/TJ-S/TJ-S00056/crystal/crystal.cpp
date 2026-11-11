#include <bits/stdc++.h>
using namespace std;
long long n;
long long m,ans=-1e12;
int a[500005],flag;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
			flag=1;
	}
	if(!flag)
	{
		long long mid=n/2+1,cnt=1;
		for(int i=mid-1;i>=1;i--)
		{
			long long c=a[mid]-a[i];
			if(m>=c)
			{
				m-=c;
				++cnt;
			}
			else
			{
				ans=max(ans,cnt);
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++)
	{
		long long m1=m,cnt=1;
		for(int j=i-1;j>=a[1];j--)
		{
			int c=a[i]-a[j];
			if(m1>=c)
				m1-=c,++cnt;
			else
				break;		
		}
		ans=max(ans,cnt);
	}
	
	cout<<ans;
	return 0;
}                             

