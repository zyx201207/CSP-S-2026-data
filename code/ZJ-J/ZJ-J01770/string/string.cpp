#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
long long n,a[MAXN],l,r,s[MAXN],ans;
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
		r+=a[i];
		do{
			c[i]=getchar();
		}while(c[i]<'a'||c[i]>'z');
	}
	l=1;
	while(l<=r){
		long long strl,strr,nl=1,nr=n,nmid;
		while(nl<nr){
			nmid=((nl+nr)>>1);
			if(s[nmid]>=l)nr=nmid;
			else if(s[nmid]<l)nl=nmid+1;
		}
		strl=nl;
		nl=1,nr=n;
		while(nl<nr){
			nmid=((nl+nr)>>1);
			if(s[nmid]>=r)nr=nmid;
			else if(s[nmid]<r)nl=nmid+1;
		}
		strr=nl;
		if(strr==strl)break;
		long long lcha=s[strl]+1-l;
		long long rcha=r-s[strr-1];
		long long mincha=min(lcha,rcha);
		l+=mincha;
		r-=mincha;
		if(c[strl]!=c[strr]){
			ans+=mincha;
		}
	}
	printf("%lld\n",ans);
	return 0;
}