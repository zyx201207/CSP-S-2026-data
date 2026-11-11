#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 8;
ll n, m, ans;
ll a[N];
bool flag = 1;

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(flag == 1 && a[i] != i-1) flag = 0;
	}
	sort(a+1, a+n+1, cmp);
	
//	if(n <= 20) {
//		for(int i=1)
//	}
	
	if(m == 1) {
		cout<<a[n];
		return 0;
	}
	
	if(m == 2) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	
	if(m == n) {
		ans = a[1];
		for(int i=1; i<=n; i++) {
			ans = ans & a[i];
		}
		cout<<ans;
		return 0;
	}
	
	if(flag == 1) {
		cout<<n - m;
		return 0;
	}
	
	cout<<a[m];
//	for(int i=1; i<=n; i++) {
//		cout<<a[i]<<endl;
//	}
	return 0;
}
