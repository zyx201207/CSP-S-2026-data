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

const int N=5e5+10;
const int M=3e5+10;

int n,m;
int a[N];
int lst[M];
int ans[M];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),lst[a[i]]=i;
	bool flag=false;
	for (int i=1;i<=n;i++)
		if (a[i]<a[i-1])
		{
			flag=true;
			break;
		}
	if (!flag)
	{
		for (int i=1;i<=n;i++)
			if (a[i]!=a[i+1])
				ans[a[i]]=i;
		for (int i=1;i<=m;i++)
			printf("%d ",ans[i]);
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j=lst[a[j]]+1)
			ans[a[j]]++;
	for (int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
