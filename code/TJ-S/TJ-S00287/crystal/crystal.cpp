#include<bits/stdc++.h>
using namespace std;

namespace crystal {
	typedef long long ll;
	const int N=5e5+5,INF=0x3f3f3f3f;
	int n,m,ans;
	ll a[N],s[N];
	void solve() {
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) {
			s[i] = s[i-1]+a[i];
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=i;j++) {
				if(s[j-1]-j*a[i]<=-(i+1)*a[i]+s[i]+m) {
					ans = max(ans,i-j+1);
					break;
				}
			}
		}
		cout<<ans;
	}
}
namespace crystal2 {
	typedef long long ll;
	const int N=5e5+5,INF=0x3f3f3f3f;
	int n,m,ans;
	ll a[N],s[N];
	void solve() {
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) {
			s[i] = s[i-1]+a[i];
		}
		for(int i=1;i<=n;i++) {
			int l=1,r=i;
			while(l<r) {
				int mid=(l+r)>>1;
				if(s[mid-1]-1ll*mid*a[i]<=s[i]+m-(i+1)*1ll*a[i]) {
					r = mid;
				} else
					l = mid+1;
			}
			ans = max(ans,(i-l+1));
		}
		cout<<ans;
	}
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	crystal2::solve();
	return 0;
} 
