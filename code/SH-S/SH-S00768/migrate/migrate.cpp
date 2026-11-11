#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
constexpr int N=2e6+10;
int c,T,n,d,x[N],ans;
inline void solve() {
	cin>>n>>d;
	ans=0;
	cout<<d<<endl;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n-3;i++) {
		for(int j=i+1;j<=n-2;j++) {
			for(int k=j+2;k<=n;k++) {
				if(x[k]-x[i]>d&&x[k]-x[j]<=d&&x[j+1]-x[i]<=d&&x[k]-x[j-1]>d&&x[j+2]-x[i]>d) {
					int lcnt=1,rcnt=1;
					for(int s=i-1;s>=1;s--) {
						if(x[s+2]-x[s]>d&&x[s+1]-x[s]<=d) lcnt++;
						else break;
					}
					for(int t=k+1;t<=n;t++) {
						if(x[t]-x[t-2]>d&&x[t]-x[t-1]<=d) rcnt++;
						else break;
					}
					ans=ans+lcnt*rcnt;
				}
			}
		}
	}
	cout<<ans<<endl;
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
