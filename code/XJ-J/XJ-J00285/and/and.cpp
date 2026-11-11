#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<ll> a;
vector<bool> vis;

/* 测试用 
输出该数的二进制 
void two(ll x, ll t) {
	for(ll k=t-1; k>=0; k--) {
		cout<<((x>>k)&1);
	} cout<<endl;
}
*/
// O(n* log max_a) <= 2*10^5 * 30
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m;
	ll maxa=0;
	cin>>n>>m;
	a.resize(n+1);
	vis.resize(n+1, true);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxa=max(maxa, a[i]);
	}
	int t=0; // a_max 的位数 
	while(maxa>0) {
		maxa>>=1;
		t++;
	}

	ll ans=0;
	for(int k=t-1; k>=0; k--) {
		int cnt=0; // 当前位 1 出现的次数 
		for(int i=1; i<=n; i++) {
			if(vis[i] && (a[i]>>k)&1) {
				cnt++;
			}
		}
		// 1 的个数足够答案当前位就为 1
		if(cnt>=m) {
			ans=(ans<<1)+1;
			// 当前位为 0 的数都不要 
			for(int i=1; i<=n; i++) {
				if(vis[i] && !((a[i]>>k)&1)) {
					vis[i]=false;
				}
			}
		} else {
			ans<<=1;
		}
	}
	cout<<ans<<endl;

	return 0;
}
