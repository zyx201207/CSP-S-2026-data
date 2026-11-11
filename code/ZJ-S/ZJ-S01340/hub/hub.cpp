#include<bits/stdc++.h>
//#define int long long
using namespace std;

inline int read()
{
	int val=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		val=val*10+(ch-'0');
		ch=getchar();
	}
	return val*k;
}
inline void write(int val)
{
	if(val<0) putchar('-'),val=-val;
	if(val>9) write(val/10);
	putchar(val%10+'0');
}
int c,T;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--)
	{
		int n=read(),k=read();
		for(int i=1;i<n;i++) int x=read(),y=read();
		write(n-k),putchar('\n');
	}
	return 0;
}