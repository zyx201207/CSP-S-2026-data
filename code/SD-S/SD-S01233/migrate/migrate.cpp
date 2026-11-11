#include<bits/stdc++.h>
using namespace std;
const int mx=2e6;
long long xx[mx+10];
int hd[mx+10],bk[mx+10];
int ch[mx+10],cb[mx+10];
int pre[mx+10],suf[mx+10];
inline long long read()
{
	char ch=getchar();
	bool f=0;
	long long v=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		v=(v<<1)+(v<<3)+(ch^48);
		ch=getchar();
	}
	return f?-v:v;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int i,cc,tt,n,l,r,pos;
	long long d,ans;
	cc=read();tt=read();
	while(tt--)
	{
		n=read();d=read();ans=0;
		for(i=1;i<=n;++i) ch[i]=cb[i]=0;
		for(i=1;i<=n;++i) xx[i]=read();
		pos=1;
		for(i=1;i<=n;++i)
		{
			while(xx[i]-xx[pos]>d) ++pos;
			hd[i]=pos;ch[hd[i]]++;
		}
		pos=n;
		for(i=n;i>=1;--i)
		{
			while(xx[pos]-xx[i]>d) --pos;
			bk[i]=pos;cb[bk[i]]++;
		}
		pre[0]=0;
		for(i=1;i<=n;++i)
		{
			if(hd[i]==i) pre[i]=0;
			else if(bk[hd[i]]==i)
				pre[i]=pre[hd[i]]+cb[i];
			else pre[i]=cb[i];
		}
		suf[n+1]=0;
		for(i=n;i>=1;--i)
		{
			if(bk[i]==i) suf[i]=0;
			else if(hd[bk[i]]==i)
				suf[i]=suf[bk[i]]+ch[i];
			else suf[i]=ch[i];
		}
		for(i=1;i<n;++i)
		{
			if(hd[i]==i) continue;
			if(bk[i+1]==i+1) continue;
			if(bk[i]<=i+1) continue;
			if(hd[i+1]>=i) continue;
			if(bk[hd[i]]!=i+1) l=cb[i+1];
			else l=cb[i+1]+pre[hd[i]];
			if(hd[bk[i+1]]!=i) r=ch[i];
			else r=ch[i]+suf[bk[i+1]];
			ans+=(long long)l*r;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
