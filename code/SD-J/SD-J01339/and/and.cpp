#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=2e5+10;
int n,m,k,ans;
int a[N];
ll p[N];
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1) 
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
	    ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		ans=-100;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]); 
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=32;j++)
		{
			if(a[i]&(1<<j)) p[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
	    while(m--)
	    {
		    for(int j=30;j>=0;j--)
		    {
			    if(a[i]&(1<<j)==0) 
			    {
				    a[i]+=1<<j;
				    break;
			    }
		    }
		    ans=max(ans,a[i]);
	    }
	}
	cout<<ans;
	return 0;
}
