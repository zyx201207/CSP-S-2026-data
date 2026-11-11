#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define endl'\n'
int n,m;
int a[2000005],sum[2000005];
bool check(int mid) {
	int cnt=0,kkk=LLONG_MAX,maxx=a[mid];
	for(int i=1; i<=mid; i++) {
		cnt+=(a[mid]-a[i]);
	}
//	cout<<"mid="<<mid<<" ";
	for(int i=1; i+mid-1<=2*n; i++) {
		if(a[i-1]==maxx) {
			maxx=min(maxx,a[i]);
		}
		maxx=max(maxx,a[i+mid-1]);
		cnt=maxx*mid-(sum[i+mid-1]-sum[i-1]);
//		cout<<cnt<<" ";
		kkk=min(kkk,cnt);
	}
//	cout<<endl;
	if(kkk<=m) {
		return 1;
	}
	return 0;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]+=1e12;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		a[i+n]=a[i];
	}
	for(int i=1; i<=2*n; i++) {
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=n,ans=LLONG_MIN;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid)) {
			ans=max(ans,mid);
			l=mid+1;
		} else {
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
