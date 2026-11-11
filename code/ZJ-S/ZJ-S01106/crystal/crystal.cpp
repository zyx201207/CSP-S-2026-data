#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,t,w,bao,mid,a[500010];
bool check(int k) {
	int s,i,j,mi=9e18;
	for(i=1; i<=n-k+1; i++) {
		s=0;
		for(j=i; j<=i+k-2; j++) {
			s+=a[i+k-1]-a[j];
		}
		mi=min(mi,s);
	}
	return mi<=m;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	cin>>n>>m;
	for(i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+1+n);
	t=1;
	w=n;
	while(t<=w) {
		mid=(t+w)/2;
		if(check(mid))bao=mid,t=mid+1;
		else w=mid-1;
	}
	cout<<bao;
	return 0;
}/*45pts*/
