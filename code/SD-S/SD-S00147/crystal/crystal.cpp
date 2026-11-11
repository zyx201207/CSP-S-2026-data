#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mid (l+r>>1)
#define PII pair<int,int>
#define ll long long
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define lbt(x) ((x)&(-x))
#define pb push_back

const int N = 5e5 + 10;

int n;
ll m,a[N];
void solve(){
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	int ps=1,ans=0;
	ll s=0;
	rep(i,1,n){
		while(ps<i&&s>m)
			s-=a[i]-a[ps++];
		ans=max(ans,i-ps+1);
		s+=(i-ps+1)*(a[i+1]-a[i]);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	while (T--) solve();
	return 0;
}

