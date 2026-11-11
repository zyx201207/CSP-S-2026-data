#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,t,c,lf[1000001],pt,ri[1000001];
long long a[1000001],m,ans,dp[500001],dp2[500001],s[500001],dx,dt;
long long read() {
	long long ret=0,sgn=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9') {
		sgn=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		ret*=10;
		ret+=c-48;
		c=getchar();
	}
	return ret*sgn;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--) {
		ans=0;
		pt=1;
		for(int i=1; i<=n; i++)a[i]=0;
		n=read();
		m=read();
		for(int i=1; i<=n; i++) {
			a[i]=read();
			while(pt<i&&a[i]-a[pt]>m)pt++;
			lf[i]=pt;
		}
		if(n<=2||a[n]-a[1]<=m){
			printf("0\n");
			continue;
		}
		if(c==11||c==12) {
			dx=a[2]-a[1];
			dt=m/dx;
			if(dt<=1){
				ans=0;
			}else{
				ans=n-2*dt+1;
			}
		} else {
			for(int i=1; i<=n; i++) {
				dp[i]=0;
				dp2[i]=1;
				s[i]=1;
				s[i-1]=0;
				ri[0]=i;
				for(int j=i+1; j<=n; j++) {
					if(lf[j]==j)break;
					dp[j]=dp[max(lf[j],i)]+1;
					ri[dp[j]]=j;
					dp2[j]=s[ri[dp[j]-1]]-s[max(lf[j],i)-1];
					ans+=(dp2[j]==2);
					s[j]=s[j-1]+dp2[j];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
