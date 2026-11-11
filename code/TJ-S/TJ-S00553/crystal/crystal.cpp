#include<bits/stdc++.h>
using namespace std;
//operator priority_queue unsigned
const int MAXN=5e5+5;
long long n,m;
long long a[MAXN];
long long len=0;
long long ans=LLONG_MIN;
bool flagA=true,flagB=true;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i) {
			flagA=false;
		}
		if(i>=2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) {
			flagB=false;
		}
	}
	sort(a+1,a+n+1);
	long long i=n-1;
	long long tmp_m=m;
	if(flagA) {
		long long l=1,r=n;
		while(l<r) {
			long long mid=(l+r+1)/2;
			long long check=(1+mid)*(mid-1+1)/2;
			if(check>m) {
				r=mid-1;
			} else {
				l=mid;
			}
		}
		cout<<l+1<<'\n';
		return 0;
	}
	if(flagB) {
		long long diff=a[2]-a[1];
		if(diff==0) {
			cout<<n<<'\n';
		} else {
			long long l=1,r=n;
			while(l<r) {
				long long mid=(l+r+1)/2;
				long long check=(diff+diff*mid)*(mid)/2;
				if(check>m) {
					r=mid-1;
				} else {
					l=mid;
				}
			}
			cout<<l+1<<'\n';

		}
		return 0;
	}
	for(long long j=n; j>=1; j--) {
		if(j<ans) {
			break;
		}
		for(; i>=1; i--) {
			long long diff=a[j]-a[i];
			if(diff<=tmp_m) {
				tmp_m-=diff;
			} else {
				break;
			}
		}
		len=j-i;
		ans=max(ans,len);
		tmp_m+=(len-1)*(a[j]-a[j-1]);
	}
	cout<<ans<<'\n';
	return 0;
}
