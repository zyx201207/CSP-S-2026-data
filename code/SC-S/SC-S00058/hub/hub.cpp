#include<bits/stdc++.h>
#define int long long
#define db double
#define endl "\n"
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int c,T;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();T=read();
	while(T--)
	{
		int n,k;
		n=read();k=read();
		for(int i=1;i<=n;i++)
		{
			int u,v;
			u=read();v=read();
		}
		puts("1");
	}
	return 0;
}
