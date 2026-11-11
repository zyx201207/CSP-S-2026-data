#include<bits/stC++.h>
#define int long long
using namespace std;
int read()
{
	int k=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int c,n,m,d,q,w[maxM];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	return 0;
}
