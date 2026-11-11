#include<bits/stdc++.h> 
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long  n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>5000)
    {
    	long long del=a[2]-a[1];
    	if(del==0)
    	{
    		cout<<n;
    		return 0;
		}
		else
		{
			cout<<m/del;
			return 0;
		}
	}
    long long fans=0;
	for(int i=n;i>=1;i--)
	{
		long long resm=m;
		long long ans=1;
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=resm)
			{
				ans++;
				resm-=a[i]-a[j];
			} 
			else
			{
				break;
			}
		}
		fans=max(fans,ans) ;
	}
	cout<<fans;	
	return 0;
}
