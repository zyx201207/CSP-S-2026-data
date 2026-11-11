//SN-S00485 张子茗 西安铁一中滨河高级中学
#include <bits/stdc++.h>
using namespace std;
long long a[500005];
bool cmp(long long x,long long y) {
	return x<y;
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt,u;
	cin>>n>>m;
	for (long long i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (long long i=n;1<=i;i--) {
		u=i;
		cnt=0;
		for (long long j=1;j<=i-1;j++) {
			cnt+=a[i]-a[j];
		}
		if (m>=cnt) {
			cout<<u;
			return 0;
		}
	}
	return 0;
}
