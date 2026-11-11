#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring> 
using namespace std;
int n,m;
long long a[200005],ans=0,t=0,p;
int main()
{
	freopen("and.in","r",stdin)
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t=max(t,a[i]);
	}
	if(m==1)
	{
	    cout<<t;
    }
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}
	else if(m==n)
	{
		p=a[1];
		for(int i=2;i<=n;i++)p&=a[i];
		cout<<p;
	}
	else if(n<=20)
	{
		if(m==3)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					for(int z=j+1;z<=n;z++)
					{
						ans=max(ans,((a[i]&a[j])&a[z]));
					}
				}
			}
			cout<<ans;
		}
		else if(m==4)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					for(int z=j+1;z<=n;z++)
					{
						for(int o=z+1;o<=n;o++)
						{
							ans=max(ans,(((a[i]&a[j])&a[z])&a[o]));
						}
					}
				}
			}
			cout<<ans;
		}
		else if(m==5)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					for(int z=j+1;z<=n;z++)
					{
						for(int o=z+1;o<=n;o++)
						{
							for(int k=o+1;k<=n;k++)
							{
								ans=max(ans,((((a[i]&a[j])&a[z])&a[o])&a[k]));
							}
						}
					}
				}
			}
			cout<<ans;
		}
		else if(m==6)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					for(int z=j+1;z<=n;z++)
					{
						for(int o=z+1;o<=n;o++)
						{
							for(int k=o+1;k<=n;k++)
							{
								for(int e=k+1;e<=n;e++)
								{
									ans=max(ans,(((((a[i]&a[j])&a[z])&a[o])&a[k])&a[e]));
								}
							}
						}
					}
				}
			}
			cout<<ans;
		}
		else if(m==7)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					for(int z=j+1;z<=n;z++)
					{
						for(int o=z+1;o<=n;o++)
						{
							for(int k=o+1;k<=n;k++)
							{
								for(int e=k+1;e<=n;e++)
								{
									for(int g=e+1;g<=n;g++)ans=max(ans,((((((a[i]&a[j])&a[z])&a[o])&a[k])&a[e])&a[g]));
								}
							}
						}
					}
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
