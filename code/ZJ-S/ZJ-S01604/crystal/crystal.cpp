#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=(int)5e5+5;
void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
void file() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
ll a[N];
int main() {
	fastIO();
	file();
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	int n,ans=0;
	ll m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	ll sum=0;
	while(r<=n) {
		r++;
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m) {
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}