#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repb(i, a, b) for(int i = (a); i >= (b); --i)

typedef long long ll;
const int N = 2e5 + 5;

int n;
int a[N];
char c[N];
ll ans = 0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	rep(i, 1, n){
		cin >> a[i] >> c[i];
	}
	
	int l = 1, r = n;
	while(l < r){
		int mn = min(a[l], a[r]);
		a[l] -= mn;
		a[r] -= mn;
		ans += mn * (c[l] != c[r]);
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	
	cout << ans << '\n';
	
	return 0;
}