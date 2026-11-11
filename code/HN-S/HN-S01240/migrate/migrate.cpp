#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll Maxn=1e18+1;
ll a,b,c,t,n,d,xl[2000001],i,j,dp[2000001],l[2000001],summ;
inline ll read() {
	ll nmb=0;short flag=1;char zf=getchar();
	while(zf<'0'||zf>'9'){if(zf=='-')flag=-1;zf=getchar();}
	while('0'<=zf&&zf<='9'){nmb=(nmb<<1)+(nmb<<3)+(zf^48);zf=getchar();}return nmb*flag;
}
inline void write(ll nmb) {
	if(nmb<0){putchar('-');nmb=-nmb;}
	if(nmb>9)write(nmb/10);putchar((nmb%10)^48);
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	t=read();t=read();
	while (t--) {
		n=read();d=read();summ=0;
		for (i=1;i<=n;++i) {
			xl[i]=read();
			l[i]=Maxn;
			dp[i]=0;
		}
		for (j=1;j<n;++j) {
			l[j]=0;dp[j]=1;
			for (i=j;i<n;++i) {
				if (l[i]==Maxn) break;
				a=i+1;b=l[i]+1;c=dp[i];
				while (a<=n&&xl[a]-xl[i]<=d) {
					if (b<l[a]) {
						l[a]=b;
						dp[a]=c;
					}
					else if (b==l[a]) dp[a]+=c;
					++a;
				}
			}
			for (i=j;i<=n;++i) {
				if (dp[i]==2) ++summ;
				l[i]=Maxn;
				dp[i]=0;
			}
		}
		write(summ);
		putchar('\n');
	}
	return 0;
}
//暴力只能这样了 
//RP++ 
