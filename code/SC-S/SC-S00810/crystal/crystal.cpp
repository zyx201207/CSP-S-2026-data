#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using pii = pair<int,int>;
#define inf 1e18
using ull = unsigned long long;
using lf = double;
const int MAXN = 5e5 + 5;

ll n,m;
ll arr[MAXN];
ll sum[MAXN];
ll ans = -inf;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>arr[i];
	sort(arr + 1,arr + 1 + n);
	for (int i=1;i<=n;i++) {
		sum[i] = sum[i-1] + (i-1) * abs(arr[i] - arr[i-1]);
	}
	sort(sum + 1,sum + 1 + n);
	if (n >= 5000) {
		for (int right = 1;right <= n;right++) {
			ll left = lower_bound(sum + 1,sum + 1 + right,sum[right] - m) - sum;
			ans = max(ans,right - left + 1);
		}
		cout<<ans<<endl;
	}
	else {
		for (int i=0;i<=n;i++) {
			for (int j=i;j<=n;j++) {
				if (sum[j] - sum[i] <= m) {
					ans = max(ans,0LL+j - i);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}