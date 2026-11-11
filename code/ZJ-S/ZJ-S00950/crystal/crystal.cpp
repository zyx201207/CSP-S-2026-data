#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long n,m,a[500050],s[500050],ans,pos;
bool check(long long right,long long left)
{
	if((right-left+1)*a[right]-(s[right]-s[left-1])<=m) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(long long i=1;i<=n;i++)
	{
		a[i]=read();		
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long l=1,r=i;
		pos=r;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if(check(i,mid))
			{
				pos=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<endl;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7