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

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,x,y; char p,q;
	cin>>a>>b>>p>>x>>y>>q;
	if (p=='F') p='E';
	if (q=='F') q='E';
	if (a==x)
	{
		printf("1");
		if (b==y)
		{
			printf("1");
			if ((p<='C'&&q<='C')||(p>='D'&&q>='D'))
			{
				printf("1");
				if (p-q==1||p-q==-1) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
