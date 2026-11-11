#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],i,c[100005],k,z,x=1,a1,b1,q;
int fun(int a,int b)
{
	int x=1,z=0,k=0,q[100005];
	string c;
	while(a!=0&&b!=0)
	{
		if(a%10==1&&b%10==1)
		c+='1';
		else
		c+='0';
		a/=10;b/=10;
		k++;
	}
	for(i=1;i<=k;i++)
	{
		q[i]=c[i]+'0';
	}
	while(k!=0)
	{
		z+=q[k]*x;
		x*=2;
		k--;
	}
	return z;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		while(a[i]!=0)
		{
			c[i]+=a[i]%2*x;
			a[i]/=2;
			x*=10;
		}
		x=1;
	}
	int o=0;
	for(i=1;i<=m;i++)
	for(k=1;i<=n;k++)
	for(z=k+1;z<=n;z++)
	{
		if(c[k]!=0&&c[z]!=0)
		{
		a1=c[k];
		b1=c[z];
	    }
	    else
	    break;
		q=fun(a1,b1);
		if(q>o)
		{
		o=q;
		c[k]=0;
		c[z]=0;
	    }
	}
	cout<<o;
	return 0;
}