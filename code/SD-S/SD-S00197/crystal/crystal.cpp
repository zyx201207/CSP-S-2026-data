#include<bits/stdc++.h>
#define int __int128
#define endl '\n'
using namespace std;
int a[500005];
int read()
{
	int n=0,x=getchar();
	while(x!=' '&&x!='\n')
	{
		bool b=0;
		if(x=='-')
		{
			x=getchar();
			b=1;
		}
		if(b) n=n*10-(x-'0');
		else n=n*10+x-'0';
		x=getchar();
	}
	return n;
}
void write(int x)
{
	string s;
	while(x)
	{
		s+=(char)(x%10+'0');
		x/=10;
	}
	for(int i=s.size()-1;i>=0;i--) putchar(s[i]);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	n=read();m=read();
	bool b=1;
	a[1]=read();a[2]=read();
	if(n==2)
	{
		cout<<2;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		a[i]=read();
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) b=0;
	}
	if(b)
	{
		write(m/(a[2]-a[1])+1);
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int mm=m,cnt=1,l=i-1,r=i+1;
		while(l>=1&&mm>=0)
		{
			mm-=a[i]-a[l];
			if(mm<0) break;
			l--;
			cnt++;
		}
		while(r<=n)
		{
			if(a[r]==a[i]) cnt++,r++;
			else break;
		}
		ans=max(ans,cnt);
	}
	write(ans);
	return 0;
}
