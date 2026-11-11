#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
long long ans,s[N];
char c[N];
int k(long long x){
	return lower_bound(s+1,s+n+1,x)-s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %c",&a[i],&c[i]),s[i]=s[i-1]+a[i];
	long long l=1,r=s[n];
	int kl=1,kr=n;
	while(kl<kr){	
		int d=min(s[kl]-l,r-s[kr-1])+1;
		if(c[kl]!=c[kr])ans+=d;
		l+=d,r-=d,kl=k(l),kr=k(r);
	}
	printf("%lld",ans);
	return 0;
}