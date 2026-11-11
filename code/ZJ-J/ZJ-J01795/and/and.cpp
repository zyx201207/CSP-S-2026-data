#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
void write(ll x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
ll n,m,j=-1,ans,a[200010];
vector<ll>v[40],s,ss;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		for(int j=0;j<30;j++)
			if((a[i]>>j)&1)v[j].push_back(a[i]);
	}
	for(int i=29;i>=0;i--)
	{
		if(j!=-1)
		{
			ll k=0;
			for(ll x:s)
				if((x>>i)&1)k++;
			if(k>=m)
			{
				ss=s;
				s.clear();
				for(ll x:ss)
					if((x>>i)&1)s.push_back(x);
				j=i;
				ans+=1<<j;
			}
		}
		else if(v[i].size()>=m)
		{
			j=i;
			ans+=1<<j;
			s=v[i];
		}
	}
	write(ans);
	return 0;
}
