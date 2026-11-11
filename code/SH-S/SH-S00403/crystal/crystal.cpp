#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct cc {
	ll v; int q;
	cc(ll v, int q) {
		this->v = v;
		this->q = q; 
	}
};

const int INF = 1e9;

vector<ll> a;
vector<cc> nums;

int main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);


	int n; ll m;
	cin >> n >> m;
	a.assign(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	
	map<ll, int> disc;
	for(int i = 1; i <= n; i++) {
		disc[a[i]]++;
	}
	for(
		auto p = disc.begin();
		p != disc.end(); p++
	) {
		nums.push_back(cc(p->first, p->second));
	}
	int len = nums.size();
	
	
	ll kBeg =
		len % 2 == 0 ?
		(len - 1) * 0.5 :
		len * 0.5;
	           
	ll kEnd = len * 0.5;
	
	int ans = -INF;
	for(ll k = 0; k < len; k++) {
		
		// nums[k].v - nums[i].v

		int remain = m, ansCur = 0;
		for(int i = k; i >= 0; i--) {
			int v = nums[k].v - nums[i].v;
			if(v < 0) {
				break;
			}
			int q;
			if(v == 0) {
				q = nums[i].q;
			}
			else {
				q = min(nums[i].q, remain / v);
			}
			if(q == 0) {
				break;
			}
			remain -= v * q;
			ansCur += q;
		}

		ans = max(ans, ansCur);
		//cout << ansCur << '\n';
	}
	
	
	cout << ans << '\n';
	
	
//	for(int k = 1; k <= 10; k++) {
//		int sum = 0;
//		for(int i = 1; i <= n; i++) {
//			sum += a[i] - k > 0 ? a[i] - k : k - a[i];
//		}
//		cout << "k=" << k << ' ' << sum << '\n';
//	}
				
	
	return 0;
}
