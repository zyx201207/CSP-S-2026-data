#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[600005];
long long b[600005];
long long mn=0x3f3f3f3f;
long long mx=-mn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	long long ans=0;
	for(int i=mn;i<=mx;i++)
	{
		long long m1=m;
		long long ans1=0;
		memset(b,0,sizeof(b));
		for(int j=0;j<n;j++)
		{
			if(i>=a[j])
			{
				b[j]=i-a[j];
			}
			else
			{
				b[j]=0x3f3f3f3f;
			}
		}
		sort(b,b+n);
		int j=0;
		while(m1>=b[j]&&j<n)
		{
			ans1++;
			m1-=b[j];
			j++;
		}
		ans=max(ans1,ans);
	}
	cout<<ans;
	return 0;
}
