#include<bits/stdc++.h>
using namespace std;

inline long long read();

const int N=5e5+10;

int n;
long long m,a[N],s[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1,j=1;i<=n;++i)
	{
		while(a[i]*(i-j)-s[i-1]+s[j-1]>m&&j<i)
		{
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

inline long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
