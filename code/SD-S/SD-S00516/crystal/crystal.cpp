#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3F3F3F3F;
void Solve(){
	ll n,m;cin >> n >> m;
	vector<ll> arr(n + 1,0),d(n + 1,0);
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int ans = -INF;ll cnt = 0,sum = 0;
	for(int l = 1,r = 1;r <= n;r++){
		cnt += arr[r];
		sum = (r - l + 1) * arr[r] - cnt;
		while(sum > m && l < r){
			sum -= cnt - (r - l + 1) * arr[l];
			cnt -= arr[l + 1];l ++;
		}
		//cout << l << " " << r << "\n";
		ans = max(ans,r - l + 1);
	}
	cout << ans;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	Solve();
	return 0;
}

