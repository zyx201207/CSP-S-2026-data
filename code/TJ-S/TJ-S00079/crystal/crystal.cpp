#include<bits/stdc++.h>
using namespace std;
int a[1000000+5],cnt[1000000+5];
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool fl=true; 
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
    /*for(int i=n;i>=1;i--)
    {
		int x=a[i];
		for(int j=n-(n-i+1);j>1;j--)
		{
			if(m-=x-a[j]>=0||a)
			{
				m-=x-a[j];
				cnt[i]++;
			}
		}
		int sum=i-1;
		while(m>0)
		{
			if(a[sum]==x)
			{
				sum++;
				cnt[i]++;
			}
			a[sum]++;
			m--;
		}
	}*/
	int l=1,r=n;
	for(int i=n;i>=1;i--)
	{
		if(i==n)
		{
			for(int j=n;j>=1;j--)
			{
				if(a[j]!=a[i])
				{
					if(m-a[j]>=0)
					{
						cnt[i]++;
					}
				}
				else
				{
					cnt[i]++;
				}
			}	
		}
		else if(i==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]!=a[i])
				{
					if(m-a[j]>=0)
					{
						cnt[i]++;
					}
				}
				else
				{
					cnt[i]++;
				}
			}
		}
		else
		{
			l=i-1;
			r=i+1;
			while(true)
			{
				int x=min(a[i]-a[l],a[r]-a[i]);
				if(m-=m<=0)
				{
					break;
				}
				else
				{
					m-=m<=0;
					cnt[i]++;
				}
				if(a[l]+x==a[i]&&l>=0)
				{
					l--;
				}
				else
				{
					if(a[r]-x==a[i]&&r<=n)
					{
						r++;
					}	
				}
				if(a[r]-x==a[i]&&r<=n)
				{
					r++;
				}
				else
				{
					if(a[l]+x==a[i]&&l>=0)
					{
						l--;
					}
				}
				if(l==0&&r==n)	
				{
					break;
				}
			}
		}	
	}
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		maxn=max(cnt[i],maxn);
	}
	cout<<maxn-1;
	return 0;
}/*5 8
//-3 -1 2 2 7
//4

5
8
-3
-1
2
2
7
0 0 1 2 3 3*/

