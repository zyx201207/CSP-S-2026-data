#include <bits/stdc++.h>
namespace FastIO
{
	constexpr int BUF=1<<22;
	char inbuf[BUF],outbuf[BUF];
	char *p1=inbuf,*p2=outbuf;
	int outpos=0;
	char gc()
	{
		if(p1==p2)
		{
			p2=(p1=inbuf)+fread(inbuf,1,BUF,stdin);
			if(p1==p2) return EOF;
		}
		return *p1++;
	}
	template<class T>
	T read()
	{
		T x=0;
		bool f=false;
		char ch=gc();
		while(ch>'9'||ch<'0')
		{
			if(ch=='-') f=true;
			ch=gc();
		}
		while(ch>='0'&&ch<='9')
		{
			x=(x<<3)+(x<<1)+(ch^48);
			ch=gc();
		}
		return f?-x:x;
	}
	void flush()
	{
		fwrite(outbuf,1,outpos,stdout);
		outpos=0;
		return ;
	}
	template <class T>
	void write(T x,char endch=' ')
	{
		if(outpos>BUF-32) flush();
		if(x<0) outbuf[outpos++]='-',x=-x;
		if(x==0) outbuf[outpos++]='0';
		else
		{
			char tmp[64]={};
			int top=0;
			while(x)
			{
				tmp[top++]=(x%10)+48;
				x/=10;
			}
			while(top)
			{
				outbuf[outpos++]=tmp[--top];
			}
		}
		outbuf[outpos++]=endch;
		return;
	}
}


using namespace std;
using FastIO::read;
using FastIO::write;
using FastIO::flush;















int c,t;
int n;
long long d;
constexpr int MAXN=2e6+10;
typedef long long ll;
ll x[MAXN];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=read<int>(); t=read<int>();
	while(t--)
	{
		n=read<int>(); d=read<ll>();
		for(int i=1;i<=n;i++) x[i]=read<ll>();
		if(c==11||c==12)
		{
			ll gp=x[2]-x[1];
			if(gp*2>d) write<int>(0,'\n');
			else
			{
				if(gp*(n-1)<d) write<int>(0,'\n');
				else
				{
					write<int>(n-2*(d/gp)+1,'\n');
				}
			}
		}
	}
	flush();
	fclose(stdin); fclose(stdout);
	return 0;
}