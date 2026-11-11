#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],n,m,ans,maxn,maxn2;
bool flag1=0,flag2=0;

int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn2=max(a[i],maxn2);
	}
	
		
	
	for(int i=2;i<n;i++)
	{
		if(a[i+1]-a[i]==a[i]-a[i-1]) flag2=1;
		else flag2=0;
		if(a[i]==i) flag1=1;
		else flag1=0;
	}
    
	if(flag1)
	{
		for(int i=1;i<n;i++)
		{
			ans+=i;
			if(ans>m) 
			{
				cout<<i;
				return 0;
			}
		}
		cout<<ans;
	}
	else if(flag2)
	{
		ans=0;
		ll cur=a[2]-a[1];
		for(int i=1;i<n;i++)
		{
			ans+=cur*i;
			if(ans>m) 
			{
				cout<<i;
				return 0;
			}
		}
	}
	else if(maxn2<=100)
	{
		cout<<n;
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			long long sum=m,cnt=1;
			for(int j=i+1;j<=n;j++)
			{
				if((sum-((a[j]-a[j-1])*(j-i)))>=0)
				{
					cnt++;
					sum-=(a[j]-a[j-1])*(j-i);
				}
				else break;
    		} 
    		maxn=max(maxn,cnt);
    	}
    	cout<<maxn;
	}
	
	
	return 0;
 } 
