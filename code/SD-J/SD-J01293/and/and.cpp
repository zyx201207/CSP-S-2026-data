#include <bits/stdc++.h>
using namespace std;
int num[30],a[200005];
const int INF= 0x3f3f3f3f;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int maxj=-INF,maxx=-INF;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout <<maxx;
	}
	else if(m==2)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout <<maxx;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout <<ans;
	}
	else
	{
		long long xp=1<<n,ans=0;
		for(long long i=1;i<=xp;i++)
		{
			long long t=i,j=1,cnt=-1,sum=0;
			while(t)
			{
				if(t%2==1)
				{
					if(cnt==-1)
					{
						cnt=a[j]; 
					}
					else
					{
						cnt=cnt&a[j];
					}
					sum++;
				}
				j++;
				t/=2;
			}
			if(sum==m)
			{
				ans=max(ans,cnt);
			}
		 } 
		 cout <<ans;
	}
	return 0;
} 
