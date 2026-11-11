#include <bits/stdc++.h>
using namespace std;
long long m,n,ma=-1,mi=1e12,cnt=0,ci=1,t=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+2];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>ma)
		{
			ma=a[i];
		}
		if(a[i]<mi)
		{
			mi=a[i];
		}
	}
	long long c[ma-mi+2]={0};
	for(int i=1;i<=n;i++)
	{
		c[a[i]-mi+1]++;
	}
	ci=mi;
	for(int i=1;i<=ma-mi+1;i++)
	{
		if(c[i]>cnt)
		{
			cnt=c[i];
			ci=i;
		}
	}
	if(ci=mi)
	{
		while(m>0&&ci<=ma-mi)
		{
			m-=c[ci];
			cnt+=c[ci+1];
			c[ci+1]+=c[ci];
			ci++;
		}
	}
	else
	{
		while(m>0)
		{
			if(ci+t<=ma-mi&&ci-t>=1)
			{
				if(c[ci]<=m&&c[ci-t]*t>c[ci])
				{
					m-=c[ci];
					c[ci+1]+=c[ci];
					c[ci]=0;
					ci++;
					cnt+=c[ci+1];
				}
				else if(c[ci]>c[ci-t]*t)
				{
					m-=c[ci-t]*t;
					c[ci]+=c[ci-t];
					c[ci-t]=0;
					t++;
					cnt+=c[ci-t];
				}
			}
			else if(ci+t<=ma-mi)
			{
			    m-=c[ci];
			    cnt+=c[ci+1];
			    c[ci+1]+=c[ci];
			    ci++;
			}
		}
	}
	if(m%t==0&&m<0)
	{
		cnt+=m/t;
	}
	else if(m<0)
	{
		cnt+=(m/t-1);
	}
	cout<<cnt;
	return 0;
 } 
