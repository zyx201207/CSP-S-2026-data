#include <bits/stdc++.h>
using namespace std;
long long n,a[35][210000],b[210000],k[100],m,p[210000],s,z[100];
void dfs(int x,int deep)
{
	if(x==m+1)
	{
	   	memset(k,0,sizeof(k));
	   	long long d=b[p[1]];
	   	for(int i=1;i<=b[p[1]];i++) k[i]=a[p[1]][i];
	   	for(int i=2;i<=x-1;i++)
	   	{
	   		for(int j=1;j<=min(b[p[i]],d);j++)
	   		{
	   			if(a[p[i]][j]==1&&k[j]==1) k[j]=1;
	   			   else k[j]=0;
			   }
			d=min(d,b[p[i]]);
		}
		long long l=1,r=0;
		for(int i=d;i>=1;i--) r+=l*k[i],l=l*2;
		s=max(s,r);
		return ;
    }
    if(deep>n) return ;
    p[x]=deep;
    dfs(x+1,deep+1);
    p[x]=0;
    dfs(x,deep+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	long long x,kk=0;
    	memset(z,0,sizeof(z));
    	cin>>x;
    	while(x)
    	{
    		z[++kk]=x%2;
    		x/=2;
		}
		for(int j=1;j<=kk;j++) a[i][j]=z[kk+1-j];
		b[i]=kk;
	}
	if(n<=20)
	{
		dfs(1,1);
		cout<<s;
		return 0;
	}
	if(n<=2000)
	{
		if(m==1) cout<<0;
		  else if(m==n)
		  {
		  		   	memset(k,0,sizeof(k));
	   	    long long d=b[1];
	   	for(int i=1;i<=b[1];i++) k[i]=a[1][i];
	   	for(int i=2;i<=n;i++)
	   	{
	   		for(int j=1;j<=min(b[i],d);j++)
	   		{
	   			if(a[i][j]==1&&k[j]==1) k[j]=1;
	   			   else k[j]=0;
			   }
			d=min(d,b[i]);
		}
		long long l=1,r=0;
		for(int i=d;i>=1;i--) r+=l*k[i],l=l*2;
		cout<<r;
		  }
		    else 
		    {
		      dfs(1,1);
		      cout<<s;
		      return 0;
	      }
}
}