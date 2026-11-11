#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int fff=0,ff=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)fff=1;
		
	}
	for(int i=2;i<n;i++)
	{
		if(a[i+1]-a[i]!=a[i]-a[i-1])ff=1;
	}
	if(fff==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(m>=a[i])
			{
				m-=a[i];
			}
			else{ cout<<i;return 0;}
		}
		cout<<n;
	}
	else if(ff==0)
	{
		int sum=a[2]-a[1];
		for(int i=1;i<=n;i++)
		{
			if(m>=sum*i)
			{
				m-=sum*i;
			}
			else{ cout<<i;return 0;}
		}
		cout<<n;
	}
	else
    {
     	sort(a+1,a+n+1);
		long long maxx=-100000000000;
		for(int j=2;j<=n;j++)
		{
			long long f=1;
			int mm=m;
			for(int i=j;i<=n;i++)
			{
				if(a[i]-a[i-1]<=mm)
				{
					
					int k=i;
					while(a[i]-a[i-1]<=mm && k>1)
					{
						mm-=(a[i]-a[i-1]);
						k--;
					}
					if(k==1){f++;maxx=max(maxx,f);}
					
					else
					{
						maxx=max(maxx,f);
						break;
					}
					
				}
				else 
				{
					maxx=max(maxx,f);
					break;
				}
					
			}
		}
		long long f=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])f++;
			else
			{
				
				f=1;
			}
			maxx=max(maxx,f);
		}
		cout<<maxx;
	}
    return 0;
}
