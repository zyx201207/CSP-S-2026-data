#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,l,a[N],c[N],ans=0,s,st=1,flag=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(long long i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1; i<=n; i++) {
		c[i]=a[1]-a[i];
	}
	flag=1;
	for(long long i=3; i<=n; i++) {
		if((a[i-2]-a[i-1])!=(a[i]-a[i-1])) {
			flag=0;
			break;
		}
	}
	if(flag==1) {
		l=m,s=0;
		for(long long j=n; j>=1; j--) {
			if(l>=c[j]||c[j]==0) {
				cout<<1;
				s++;
				l-=c[j];
			} else {
				cout<<s;
				return 0;
			}
		}
	}
	for(long long i=1; i<=n; i++) {
		l=m,s=0;
		for(long long j=i; j>=1; j--) {
			if(l>=c[j]||c[j]==0) {
				s++;
				l-=c[j];
			} else {
				break;
			}
		}
		ans=max(s,ans);
		for(int j=1; j<=n; j++) {
			c[j]+=a[i+1]-a[i];
		}
	}
	printf("%lld",ans);
	return 0;
}

