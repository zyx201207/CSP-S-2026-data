#include<bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long a[500005];
long long ans=0;

bool check(int x,int y) {
	long long sum=0;
	for(int i=x;i<=y;i++) {
		sum+=a[y]-a[i];
	}
	return sum>m;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		int l=1,r=i;
		while(l<r) {
			int mid=(l+r)>>1;
			if(check(mid,i)) {
				l=mid+1;
			}
			else {
				r=mid;
			}
		}
		ans=max(ans,i-l+1ll);
	}
	cout<<ans;
	return 0;
}
