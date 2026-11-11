#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],qj[500010];
long long pj,tot,ans;
int main() {
	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1; i<=n; i++) qj[i]=qj[i-1]+a[i];
	for(int i=1; i<=n; i++) {
		long long l=1,r=i;
		bool f=0;
		while(l<r) {
			long long mid=(l+r)/2;
			long long sj=qj[i]-qj[mid-1];
			long long need=a[i]*(i-mid+1);
//			cout<<i<<" "<<l<<" "<<r<<" "<<mid<<" "<<ans<<" "<<need<<" "<<sj<<" "<<i-mid+1<<" "<<(m>=(need-sj))<<endl;
			if(m>=(need-sj)) {
				f=1,ans=max(ans,i-mid+1);
			}
			if(f) r=mid-1;
			else l=mid;
//			cout<<endl;
		}

	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 6
-1000000000 1 2 1000000000 3


*/

