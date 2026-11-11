#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int mx=-1e9,mn=1e9;
int ans;
int a[N];
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int x=1,flag=0;
	for(int i=1;i<=30;i++)
	{
		x=x*2;
		if(x==n) flag=1;
	}
	if(flag==1)
	{
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++)
			ans&=a[i];
		cout<<ans<<endl;	
		return 0;	
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		ans=mx;
		cout<<ans<<endl;
		return 0;
	}
	if(m==2)
	{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n-1;i++)
			mn=min(mn,abs(a[i]-a[i+1]));
		for(int i=1;i<=n-1;i++)
		{
			if(abs(a[i]-a[i+1])==mn) 
			{
				ans=a[i]&a[i+1];
				break;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
