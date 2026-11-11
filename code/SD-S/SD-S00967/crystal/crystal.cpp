#include<bits/stdc++.h>
using namespace std;
long long a[500002];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=m,ans=0,j=n;
	for(long long i=n;i>=1;i--)
	{
		while(j>=1&&sum>=a[i]-a[j])
		{
			sum-=a[i]-a[j];
			j--;
		}
		ans=max(ans,i-j);
		sum+=(i-j-1)*(a[i]-a[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}
