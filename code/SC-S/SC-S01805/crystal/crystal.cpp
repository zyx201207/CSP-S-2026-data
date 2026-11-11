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















int n;
constexpr int MAXN=5e5+10; typedef long long ll;
ll m;
ll a[MAXN];
ll pre[MAXN];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read<int>(); m=read<ll>();
	for(int i=1;i<=n;i++) a[i]=read<ll>();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int r=n,l=1;
	int ans=1;
	while(r>l)
	{
		int mid=(l+r)>>1;
		for(int i=1;i+mid<=n;i++)
		{
			int j=i+mid-1;
			ll cost=a[j]*mid-pre[j]+pre[i-1];
			if(cost<=m)
			{
				ans=mid;
			}
		}
		if(ans==mid)
		{
			l=mid+1;
		}
		else r=mid;
	}
	write<int>(ans);
	
	flush(); 
	fclose(stdin); fclose(stdout);
	return 0;
}