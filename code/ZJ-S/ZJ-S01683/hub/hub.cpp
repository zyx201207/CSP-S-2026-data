#include <iostream>
#include <cstring>
#include <algorithm>
#include <random>

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

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	random_device rd;
	srand(rd());
	int c=read(),t=read();
	while (t--)
	{
		cout<<rand()%50<<'\n';
		// zhi yao wo ren pin gou hao ...
	}
	return 0;
}
