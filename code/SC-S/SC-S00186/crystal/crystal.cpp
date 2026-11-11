#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,a[N];

inline int check(int now) {
	int res=0,need=0;
	int p[n+1];
	for(int i=1;i<=n;i++) {
		p[i]=a[now]-a[i];
		if(p[i]<0) p[i]=m+1;
	}
	sort(p,p+n);
	for(int i=1;i<=n;i++) {
		if(need>m) break;
		if(need+p[i]<=m) {
			need+=p[i];
			++res;
		} else break;
	}
	return res;
}

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		int k=check(i);
		if(k>ans) {
			ans=k;
		}
	}
	cout<<ans;
	return 0;
}