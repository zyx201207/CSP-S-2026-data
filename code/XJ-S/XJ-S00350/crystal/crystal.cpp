#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	int n;
	cin>>n>>m;
	long long a[n+2]={},b[n+2]={},flagA=1,flagB=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[0])
		{
			flagA=0;
		}
		if(i>1)
		{
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])
			{
				flagB=0;
			}
		}
	}
	if(flagA)
	{
		cout<<n;
	}
	else if(flagB)
	{
		cout<<"1";
		long long zhi=a[1]-a[0];
		long long ansB=1,lingshi=0;
		for(int i=0;i<n;i++)
		{
			lingshi+=zhi*i;
			if(lingshi>m)
			{
				break;
			}
			else
			{
				ansB++;
			}
		}
		cout<<ansB-1;
	}
	else
	{
		sort(a,a+n);
		long long max=a[n-1];
		for(int i=0;i<n;i++)
		{
			b[i]=max-a[i];
		}
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				int zhi=0,cnt=0,flag=0;
				for(int z=i;z<j;z++)
				{
					zhi+=b[z]-b[j];
					cnt++;
					if(zhi>m)
					{
						flag=1;
						break;
					}
				}
				if(cnt==0||flag)
				{
					continue;
				}
				zhi-=cnt*b[j];
				if(zhi<=m&&cnt>ans)
				{
					ans=cnt;
				}
			}
		}
		if(ans==-1)
		{
			cout<<"1";
		}
		else
		{
			cout<<ans+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	
	return 0;
}
