#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a,b,c,d,i,ans[500001],sul[500001];
ll fa[500001],nm[500001];
inline ll read() {
	ll nmb=0;short flag=1;char zf=getchar();
	while(zf<'0'||zf>'9'){if(zf=='-')flag=-1;zf=getchar();}
	while('0'<=zf&&zf<='9'){nmb=(nmb<<1)+(nmb<<3)+(zf^48);zf=getchar();}return nmb*flag;
}
inline void write(ll nmb){if(nmb>9)write(nmb/10);putchar((nmb%10)^48);}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for (i=1;i<=n;++i) ans[i]=read();
	sort(ans+1,ans+n+1);
	for (i=n;i>0;--i) ans[i]=ans[i]-ans[i-1];
	for (i=1;i<=n;++i) sul[i]=sul[i-1]+ans[i];
	fa[1]=1;
	for (i=2;i<=n;++i) {
		a=fa[i-1];c=ans[i]*(i-a)+nm[i-1];
		while (c>m) {
			c-=(sul[i]-sul[a]);
			++a;--d;
		}
		nm[i]=c;fa[i]=a;
	}
	a=0;
	for (i=1;i<=n;++i) a=max(i-fa[i]+1,a);
	write(a);
	return 0; 
}
