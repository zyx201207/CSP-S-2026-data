#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

namespace FastIO
{
	char buf[1<<20],*p1=buf,*p2=buf;
	#define gc() (p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p2==p1)?EOF:*p1++)
	inline LL read()
	{
		LL x=0,f=1; char c=gc();
		while (c<'0'||c>'9') if (c=='-') f=-1,c=gc(); else c=gc();
		while (c>='0'&&c<='9') x=x*10+c-'0',c=gc();
		return x*f;
	}
}
using FastIO::read;

const int N=5e5+10;

int n,m;
LL a[N];

bool check(int x)
{
	LL sum=0;
	for (int i=1;i<x;i++) sum+=a[i];
	for (int l=1;l+x-1<=n;l++)
	{
		int r=l+x-1;
		sum+=a[r];
		LL L=a[r]*x;
		if (L-sum<=m) return true;
		sum-=a[l];
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	int l=1,r=n,ret=1;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)) l=mid+1,ret=mid;
		else r=mid-1;
	}
	printf("%d\n",ret);
	return 0;
}
