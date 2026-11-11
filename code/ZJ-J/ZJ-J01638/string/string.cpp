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

const int N=4e5+10;

int a1[N],c1[N];
int a2[N],c2[N];
int n;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	LL l1=0;
	for (int i=1;i<=n;i++)
	{
		char c;
		cin>>a1[i]>>c;
		c1[i]=c-'a';
		l1+=a1[i];
	}
	int m=0;
	LL l2=0;
	for (int i=n;i>=1;i--)
	{
		if (l2>=l1/2) break;
		if (l2+a1[i]>l1/2)
		{
			m++;
			a2[m]=l1/2-l2;
			c2[m]=c1[i];
			a1[i]-=a2[m];
			l2+=a2[m];
			break;
		}
		m++,n--;
		a2[m]=a1[i];
		c2[m]=c1[i];
		l2+=a2[m];
	}
	l1/=2;
	LL tmp=0;
	for (int i=1;i<=n;i++) tmp+=a1[i];
	if (tmp>l1) a1[n]--;
	if (!a1[n]) n--;
	int i=1,j=1;
	LL ans=0;
	while (i<=n&&j<=m)
	{
		int t=min(a1[i],a2[j]);
		if (c1[i]!=c2[j]) ans+=t;
		a1[i]-=t,a2[j]-=t;
		if (a1[i]==0) i++;
		if (a2[j]==0) j++;
	}
	printf("%lld\n",ans);
	return 0;
}
