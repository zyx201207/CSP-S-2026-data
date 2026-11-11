#include<bits/stdc++.h>
using namespace std;

namespace wsrCSPS {
	using ll=long long;
	const int N=5e5+9;
	int n;
	ll m,a[N],sum[N];
	
	int main() {
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			sum[i] = sum[i-1]+a[i];
		int ans=0;
		for(int i=1;i<=n;i++) {
			int l=1,r=i,x=i;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) {
					x = mid;
					r = mid-1;
				} else l = mid+1;
			}
			ans = max(ans,i-x+1);
		}
		cout<<ans;
		return 0;
	}
}

int main() { return wsrCSPS::main(); }

