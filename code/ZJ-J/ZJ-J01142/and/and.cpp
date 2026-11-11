#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,r,s,k,t,da,a[200005],b[200005][45];
bool f=1,flag,v[200005],vv[200005],vis[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		x=a[i];
		k=0;
		while(x)
		{
			r=x%2;
			b[i][++k]=r;
			x/=2;
		}
	}
	flag=1;
	for(int i=35;i>=1;i--)
	{
		memset(v,0,sizeof v);
		s=0;
		if(flag)
		{
			for(int j=1;j<=n;j++) 
				if(b[j][i]) s++,v[j]=1;
			if(s>=m)
			{
				flag=0;
				for(int j=1;j<=n;j++) 
					if(v[j]) vis[j]=1;
			}
		}
		else
		{
			
			for(int j=1;j<=n;j++) 
				if(b[j][i]&&vis[j]) s++,v[j]=1;
			if(s>=m)
				for(int j=1;j<=n;j++) if(vis[j]&&(!v[j])) vis[j]=0;
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]&&f) f=0,da=a[i],t++;
		else if(vis[i]) da&=a[i],t++;
		if(t==m) break;
	}
	cout<<da;
	return 0;
}
