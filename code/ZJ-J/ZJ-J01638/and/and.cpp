#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

namespace FastIO
{
	#define gc() getchar()
	inline LL read()
	{
		LL x=0,f=1; char c=gc();
		while (c<'0'||c>'9') if (c=='-') f=-1,c=gc(); else c=gc();
		while (c>='0'&&c<='9') x=x*10+c-'0',c=gc();
		return x*f;
	}
}
using FastIO::read;

const int N=2e5+10;

int n,m;
int a[N];
bool f[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int ans=0;
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=30;i>=0;i--)
	{
		int cnt=0;
		for (int j=1;j<=n;j++)
			if (!f[j]&&((a[j]>>i)&1)) cnt++;
		if (cnt>=m)
		{
			ans+=1<<i;
			for (int j=1;j<=n;j++)
				if (((a[j]>>i)&1)==0) f[j]=true;
		}
	}
	printf("%d\n",ans);
	return 0;
}
