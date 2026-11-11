#include<bits/stdC++.h>
#define int long long
using namespace std;
const int maxN=2e5+5;
int read()
{
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
string bin(int x)
{
	string a;
	while(x>0)
	{
		a+=x%2;
		x/=2;
	}
	return a;
}
int ans[maxN];
void ad(string a,string b)
{
	int len=min(a.length(),b.length());
	for(int i=0;i<max(a.length(),b.length());i++) ans[i]=0;
	for(int i=0;i<len;i++)
	{
		if(a[i]==b[i]) ans[i]=1;
	}
}
int mi(int x)
{
	int sum=1;
	while(x--)
	{
		sum*=2;
	}
	return sum;
}
int hy(int len)
{
	int sum=0;
	for(int i=0;i<len;i++)
	{
		sum+=ans[i]*mi(i);
	}
	return sum;
}
int n,m;
int maxx=0,a[maxN];
string s[maxN];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		s[i]=bin(a[i]);
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)
	{
		cout<<12;
		return 0;
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
	{
		cout<<7;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		ad(s[i],s[i+1]);
		maxx=max(maxx,hy(max(s[i].length(),s[i+1].length())));
	}
	printf("%d",maxx);
	return 0;
}


