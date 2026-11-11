#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n,a[N],ans,m,res;
int main()
{
	freeopen("and.in","r",stdin);
	freeopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(a[i],ans);
		}	
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		long long res=a[2];
		for(int i=2;i<=n;i++) res=res&a[i];
		cout<<res<<endl;
		ans=max(res,ans);
		for(int i=2;i<=n;i++)
		{
			long long res1=a[1];
			for(int j=1;j<=n&&j!=i;j++)
			{
				res1=res1&a[j];
			}
			ans=max(ans,res1);
			cout<<res1<<endl;
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		long long res=a[1];
		for(int i=1;i<=n;i++) res=res&a[i];
		cout<<res;
		return 0;
	}
	return 0;
}
