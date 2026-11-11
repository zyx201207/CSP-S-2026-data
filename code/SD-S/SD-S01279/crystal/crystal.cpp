#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],n,l,r,m,ans;
unsigned long long s;
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')
	{
		ch=getchar();
	}
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+int(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	l=1;
	r=1;
	s=0;
	ans=1;
	while(r<n)
	{
		while(s<=m&&r<n)
		{
			r++;
			s+=(r-l)*(a[r]-a[r-1]);
		}
		if(r-l>ans)
		{
			ans=r-l;
		}
		if(s<=m&&r-l+1>ans)
		{
			ans=r-l+1;
		}
		while(s>m&&l<r)
		{
			s-=(a[r]-a[l]);
			l++;
		}
		if(s<=m&&r-l+1>ans)
		{
			ans=r-l+1;
		}
	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
awsl
*/

