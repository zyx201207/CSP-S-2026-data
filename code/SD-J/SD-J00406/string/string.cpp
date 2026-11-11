#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,zong=0;
	cin>>n;
	long long shu[n+5],l=1,r=n;
	char fu[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>shu[i];
		cin>>fu[i];
	}
	while(l<r)
	{
		if(fu[l]==fu[r])
		{
			if(shu[l]>shu[r])
			{
				shu[l]-=shu[r];
				r--;
			}
			else if(shu[l]<shu[r])
			{
				shu[r]-=shu[l];
				l++;
			}
			else
			{
				l++;
				r--;
			}
			continue;
		}
		if(shu[l]>shu[r])
		{
			shu[l]-=shu[r];
			ans+=shu[r];
			r--;
		}
		else if(shu[r]>shu[l])
		{
			shu[r]-=shu[l];
			ans+=shu[l];
			l++;
		}
		else 
		{
			ans+=shu[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0; 
}
