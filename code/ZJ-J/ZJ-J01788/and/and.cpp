#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans,da;
long long work(long long x,long long y) {
	long long q=1,zhs=0;
	while(true) {
		if(x==0 || y==0) break;
		if(x%2==1 && y%2==1) zhs=zhs+q;
		x=x/2;
		y=y/2;
		q=q*2;
	}
	return zhs;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	ans=a[1];
	for(int i=2;i<=m;i++) {
		da=work(a[i],ans);
		ans=da;
	}
	cout<<ans;
	return 0;
}
