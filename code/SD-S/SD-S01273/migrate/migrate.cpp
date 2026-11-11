#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
#include <queue>
typedef unsigned long long ull;
typedef long long ll;
const ull N=2000010;
ull T;
ll x[N];
ull lf[N],rt[N];
ull f[N],g[N];
char buf[50000000];
char* pbuf=buf;
ull readull()
{
	ull x=0; char ch=*(pbuf++);
	while('0'>ch||ch>'9') ch=*(pbuf++);
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=*(pbuf++);
	return x;
}
ll readll()
{
	ull x=0; char ch=*(pbuf++); bool tp=0;
	while('0'>ch||ch>'9')
	{
		if(ch=='-') tp=1;
		ch=*(pbuf++);
	}
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=*(pbuf++);
	return tp?(-(ll)x):((ll)x);
}
int main()
{
	ull T;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	fread(buf,1,50000000,stdin);
//	scanf("%*u%llu",&T);
	readull();T=readull();
	while(T--)
	{
		ull n;ll d;
		ull ans=0;
//		scanf("%llu%lld",&n,&d);
		n=readull();d=readll();
		for(ull i(1);i<=n;++i) x[i]=readll();// scanf("%lld",&x[i]);
		for(ull i(1),j(1);i<=n;++i)
		{
			while(x[i]-x[j]>d) ++j;
			lf[i]=j;
		}
		for(ull i(1),j(1);i<=n;++i)
		{
			while(j<=n&&x[j]-x[i]<=d) ++j;
			rt[i]=j-1;
		}
		lf[n+1]=n+1;rt[0]=0;
		for(ull i(1);i<n;++i)
		{
			if(lf[i]!=i&&lf[i]!=lf[i+1]) f[i]=f[lf[i]];
			else f[i]=0;
			f[i]+=lf[i+1]-lf[i];
		}
		for(ull i(n);i>1;--i)
		{
			if(rt[i]!=i&&rt[i]!=rt[i-1]) g[i]=g[rt[i]];
			else g[i]=0;
			g[i]+=rt[i]-rt[i-1];
		}
		ans=0;
		for(ull i(1);i<n;++i)
		{
			if(lf[i+1]>=i||lf[i+1]==lf[i+2]||rt[i]<=i+1||rt[i]==rt[i-1]) continue;
			ull sf=(lf[i]==lf[i+1]?f[lf[i+1]]:0)+std::min(lf[i+2],i)-lf[i+1];
			ull sg=(rt[i+1]==rt[i]?g[rt[i]]:0)+rt[i]-std::max(rt[i-1],i+1);
			ans+=sf*sg;
		}
		printf("%llu\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

0 4
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
6 4
-3 0 1 2 3 4
7 5
-10 -5 -1 0 3 4 8

1-[1,2]
2-[1,4]
3-[2,6]
4-[2,6]
5-[3,7]
6-[3,7]
7-[5,7]



7
5
3
6
will only move right

maybe that only dis<=2 can be count?

case 1. dis=0, then u=v, invalid
case 2. dis=1, then only 1
case 3. dis=2, maybe ok
case 4. dis>=3, then let it is
u - p1 - p2 - ... - pm - v
u - q1 - q2 - ... - qm - v
and m=dis-1 => m>=2
let xp1<=xq1, then xp2<=xp1+d<=xq1+d
so
u - q1 - p2 - ... - pm - v
also ok
so invalid

only count dis=2

([d<xv-xu<=2d] sum{u<k<v} [xv-xk<=d][xk-xu<=d]) = 2

make each li<=i<=ri

valid <=> (d<xv-xu) & ([lu,ru]&[lv,rv]=2)
<=> (u<lv) & (lv+1=ru)

cnt_i: sum [u<=i-2][i=ru]
ans = sum cnt_(lv+1)

wait, if q2=p2?

will only make:
u - p1 - p2 - ... - pk - (x/y) - qt - ... - q1 - v
count for (pk,qt)'s unique path

[li,i]
[lli,l(li+1))
...

it's regularly

fi: ans - (i-li+1)

fi = fli + l(li+1)-lli

*/
