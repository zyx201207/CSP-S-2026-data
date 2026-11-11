#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	bool bz=false;
	char ch=getchar();
	long long ans=0;
	while(ch!=EOF&&ch!='-'&&(ch<'0'||ch>'9'))
		ch=getchar();
	if(ch=='-')
	{
		bz=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=(ans<<3)+(ans<<1)+(ch^48);
		ch=getchar();
	}
	if(bz)
		return -ans;
	return ans;
}
void wrt(long long x)
{
	int numn[40],cnt=0,i;
	long long y=x;
	if(y<0)
	{
		putchar('-');
		y=-y;
	}
	do
	{
		numn[++cnt]=y%10;
		y/=10;
	}while(y);
	for(i=cnt;i>=1;--i)
		putchar(numn[i]^48);
	return;
}
const int maxn=2e6;
int lst[maxn+10],nxt[maxn+10];
int c,n,t,lt,rt,p;
long long f[maxn+10],g[maxn+10];
long long ff[maxn+10],gg[maxn+10];
long long x[maxn+10];
long long d,sumn,xx,yy;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int i;
	c=rd();
	t=rd();
	while(t--)
	{
		n=rd();
		d=rd();
		for(i=1;i<=n;++i)
			x[i]=rd();
		lt=1;
		for(i=1;i<=n;++i)
		{
			while(lt<=i-1&&x[i]-x[lt]>d)
				++lt;
			lst[i]=lt;
			f[i]=g[i]=0;
		}
		rt=n;
		for(i=n;i>=1;--i)
		{
			while(rt>=i+1&&x[rt]-x[i]>d)
				--rt;
			nxt[i]=rt;
		}
		sumn=0;
		for(i=1;i<=n;++i)
		{
			if(nxt[i]!=i)
				++f[nxt[i]];
			if(lst[i]!=i)
				++g[lst[i]];
		}
		for(i=1;i<=n;++i)
		{
			p=lst[i];
			if(p!=i&&nxt[p]==i)
				ff[i]=ff[p]+f[i];
			else ff[i]=0;
		}
		for(i=n;i>=1;--i)
		{
			p=nxt[i];
			if(p!=i&&lst[p]==i)
				gg[i]=gg[p]+g[i];
			else gg[i]=0;
		}
		for(i=2;i<=n;++i)
		{
			xx=f[i];
			yy=g[i-1];
			if(nxt[i-1]==i)
				--xx;
			if(lst[i]==i-1)
				--yy;
			p=lst[i-1];
			if(p<i-1&&nxt[p]==i)
				xx+=ff[p];
			p=nxt[i];
			if(p>i&&lst[p]==i-1)
				yy+=gg[p];
			sumn+=xx*yy;
		}
		wrt(sumn);
		putchar('\n');
	}
	return 0;
}
