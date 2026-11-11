#include <bits/stdc++.h>
using namespace std;
int g[2005];
int f[2005];
int h[2005][2005];
int a[2005];
int s[2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	int w=0;
	if(m==1)
	{
		int t=-1;
		for(int i=1;i<=n;i++)
		{
			t=max(t,a[i]);
		}
		cout<<t;
	}
	if(m==n)
	{
		int r=-1;
		int t=0;
		for(int i=1;i<=n;i++)
		{
			g[i]=a[i]
			while(a[i]>0)
			{
				g[i]/=2;
				s[i]++;
			}
			for(int j=s[i];j>=1;j--)
			{
				h[i][j]=a[i]%2;
				a[i]/=2;
			}
			r=min(r,s[i]);
		}
		for(int i=1;i<=r;i++)
		{
			f[i]=1;
		}
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=n;j++)
			{
			    if(h[j][s[j]-r+i]==0)	
			    {
			    	f[i]=0;
				}
			}
		}
		for(int i=1;i<=r;i++)
		{
			t+=f[i]*2^(r-i) ;
		}
		cout<<t;
	}
	return 0;
}
