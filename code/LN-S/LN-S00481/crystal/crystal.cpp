#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[5000005];
int cnt=0,ans=0,sum=0,s=0,maxn=0,num=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		num+=abs(a[i+1]-a[i])*i;
	}
	for(int p=1;p<=n;p++)
	{
		for(int i=p;i<=n;i++)
		{
			int r=i-p+1;
			cnt+=abs(a[i+1]-a[i])*r;
			ans+=1;
			if(cnt<m)
			{
				continue;
				
			}
			if(cnt==m)
			{
				for(int j=1;j<=n;j++)
				{
					if(a[i+1]==a[j])
					{
						sum++;
					}
				}
				s=sum+ans;
				break;
			}
			if(cnt>m)
			{
				s=ans;
				break;
			}
		}
		if(s>maxn)
		{
			maxn=s;
		}
		cnt=0;
		sum=0;
		ans=0;
		s=0;
	}
	if(num<m)
	{
		cout<<n;
	}
	else
	{
		cout<<maxn;
	}
	return 0;
	
}

