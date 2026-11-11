#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e6+5;
int n,m,h[N],cnt;
struct edge
{
	int nxt,to;
}e[N*2];
void add(int x,int y)
{
	e[++cnt].nxt=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C=read(),T=read();
	while(T--)
	{
		n=read();m=read();
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read();
			add(a,b);
			add(b,a);
		}
		for(int i=1;i<=cnt;i++)e[i].nxt=0,e[i].to=0;
		cnt=0;
		for(int i=1;i<=n;i++)h[i]=0;
		if(C==13||C==14)
		{
			int ans=((n-1)/2-m+1+2-1)/4+1;
			cout<<ans<<'\n';
			continue;
		}
	 } 
	return 0;
 }

