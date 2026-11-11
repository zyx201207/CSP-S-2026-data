#include<bits/stdc++.h>
using namespace std;
long long const MAXN=2e5+5;
long long n,a[MAXN],ans=0;
char c[MAXN];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	long long x1=1,x2=n;
	while(x1<=x2) {
		long long p=min(a[x1],a[x2]);
		if(c[x1]!=c[x2]) {
			ans+=p;
		}
		a[x1]-=p;
		a[x2]-=p;
		if(a[x1]<=0) {
			x1++;
		}
		if(a[x2]<=0) {
			x2--;
		}
	}
	cout<<ans;
	return 0;
}
