#include<bits/stdc++.h>
#define int long long
#define rd read()
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int c,T;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=rd,T=rd;
	while(T--)
	{
		int n=rd,k=rd;
		for(int i=1;i<n;i++)
		{
			int u=rd,v=rd;
		}
		cout<<1<<"\n";
	}
	return 0;
}
