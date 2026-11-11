#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
LL read()
{
	char c=getchar();
	LL f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
void print(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const int N=5e5+5;
int n;
LL m,a[N],S[N];
bool check(int l,int r)
{
	LL val=a[r]*(r-l+1)-(S[r]-S[l-1]);
	return val<=m;
}
int main()
{
//	freopen("crystal4.in","r",stdin);
//	freopen("cdo.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cout<<sizeof(a)*2/1024/1024;
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) S[i]=S[i-1]+a[i];
	int l=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(l<=i&&!check(l,i)) l++;
		ans=max(ans,i-l+1);
	}
	print(ans);
	return 0;
}