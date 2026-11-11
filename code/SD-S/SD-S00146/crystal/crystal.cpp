#include<bits/stdc++.h>
#include<cstdio>
#define int long long
#define endl '\n'
#define Fre
#define Ct

const int N=5e5+10;

using namespace std;

typedef pair<int,int> PII;

int a[N];
int c[N];
int sum[N];

void solve() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++) {
		c[i]=abs(a[i]-a[i-1]);
	}
	for(int i=2; i<=n; i++) {
		sum[i]=sum[i-1]+(i-1)*c[i];
	}
	int ans=0;
	int cnt=0;
	for(int l=1,r=1; l<=r&&r<=n;) {
		if(sum[r]-sum[l]>m) {
			l++;
			ans=max(ans,cnt);
			cnt--;
			cnt=max(0LL,cnt);
		}
		else{
			r++;
			cnt++;
		}
	}
	cout<<ans<<endl;
}

signed main() {

#ifdef Fre
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif

#ifdef Ct
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif

	int _=1;
	//cin>>_;
	while(_--) solve();

	return 0;
}//Oct31==Dec25?
