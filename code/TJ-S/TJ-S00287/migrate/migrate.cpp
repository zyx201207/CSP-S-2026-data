#include<bits/stdc++.h>
using namespace std;

namespace migrate {
	typedef long long ll;
	const int N=1e6+5;
	const int INF=0x3f3f3f3f;
	ll n,d;
	ll a[N];
	ll g1[N],g2[N];
	ll ans;
	void init() {
		ans = 0;
		memset(a,0,sizeof(a));
		memset(g1,0,sizeof(g1));
		memset(g2,0,sizeof(g2));
	}
	void solve() {
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
//		if(n==10) {
//			for(int j=1;j<=4;j++) {
//				cout<<j<<":\n";
//				for(int i=1;i<=n-j;i++) {
//					if(a[i+j]-a[i]<=d)
//						cout<<1;
//					else
//						cout<<0;
//				}
//				cout<<'\n';
//			}
//		}
		for(int i=2;i<=n;i++)
			if(a[i]-a[i-1]<=d&&a[i+1]-a[i-1]>d)
				g1[i] = g1[i-1]+1;
		for(int i=n-1;i>0;i--)
			if(a[i+1]-a[i]<=d&&a[i+1]-a[i-1]>d)
				g2[i] = g2[i+1]+1;
		for(int i=2;i<n-1;i++) {
			if(a[i+1]-a[i-1]<=d&&a[i+2]-a[i]<=d&&a[i+2]-a[i-1]>d) {
//				if(n==10)
//					cout<<i<<'\n';
				ans += 1ll*(g1[i-1]+1)*(g2[i+2]+1);
			}
		}
//		if(n==10) {
//			for(int i=1;i<=n;i++)
//				cout<<g1[i]<<' ';
//			cout<<'\n';
//			for(int i=1;i<=n;i++)
//				cout<<g2[i]<<' ';
//			cout<<'\n';
//		}
		cout<<ans<<'\n';
	}
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) {
		migrate::init();
		migrate::solve();
	}
	return 0;
} 
