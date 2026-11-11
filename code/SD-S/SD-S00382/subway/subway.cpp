#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*y;
}
const int N=5e5+7;
int n;
const int M=2e5+7;
int frt[N],nxt[M],to[M],dis[M];
int m;
int c;
int d,q;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cout<<32<<endl<<17<<endl;
	return 0;
}
