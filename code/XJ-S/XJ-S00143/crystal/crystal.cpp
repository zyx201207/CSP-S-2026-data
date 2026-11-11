#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=5e5+8;
int n;
long long m;
long long a[maxn];
long long pre[maxn];

bool check(int st, int ed) {
	long long base = pre[ed] - pre[st-1];
	long long targ = 1ll*a[ed]*(ed-st+1);
	return targ - base <= m;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	
	sort(a+1, a+n+1);
	for (int i=1; i<=n; ++i) pre[i] = pre[i-1] + a[i];

	int ans = 1; // a[1] along, cost nothing
	
	for (int i=2; i<=n; ++i) {
		int l=1, r=i;
		while (l<r) {
			int mid = (l+r)>>1;
			if (check(mid, i)) {
				r = mid;
			} else l = mid+1;
		}
		ans = max(ans, i-l+1);
	}
	
	cout << ans <<'\n';
	return 0;
}
