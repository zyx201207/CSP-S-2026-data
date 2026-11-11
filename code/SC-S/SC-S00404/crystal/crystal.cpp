#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5+5;
int n;
ll m;
ll a[maxn];
ll diff[maxn];
ll sum[maxn];
bool check(int x){
	for (int i = 1;i+x-1<=n;i++){
		int nxt = i+x-1;
		if (sum[i]-sum[nxt+1]-(a[n]-a[nxt])*x<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i<=n;i++){
		diff[i] = a[i]-a[i-1];
	}
	for (int i = n;i>=1;i--){
		sum[i] = sum[i+1]+diff[i+1];
	}
	for (int i = n;i>=1;i--){
		sum[i] += sum[i+1];
	}
	int l = 1,r = n,ans=1;
	while (l<=r){
		int mid = (l+r)/2;
		if (check(mid)){
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout<<ans<<"\n";
	return 0;
}