#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
long long n,m,a[200010],maxn,ans;
int t[200010];
bool f;
char c;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]>4)
			f=1;
	}
	if(m==1)
	{
		cout<<maxn<<'\n';
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(!f)
	{
		for(int i=1;i<=n;i++)
		{
			t[a[i]]++;
		}
		if(t[4]>=m)
		{
			cout<<4<<'\n';
			return 0;
		}
		if(t[3]>=m)
		{
			cout<<3<<'\n';
			return 0;
		}
		if(t[2]>=m || t[2]+t[3]>=m)
		{
			cout<<2<<'\n';
			return 0;
		}
		if(t[1]>=m ||t[1]+t[3]>=m)
		{
			cout<<1<<'\n';
			return 0;
		}
	}
	cout<<maxn<<'\n';
	return 0;
}