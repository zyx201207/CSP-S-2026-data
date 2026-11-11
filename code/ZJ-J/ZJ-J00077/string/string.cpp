#include <iostream>
#define ll long long
using namespace std;
const int maxn = 200005;
ll n, a[maxn], len = 0, ans = 0, mid;
char c[maxn];
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		len += a[i];
	}
	if(len >= 10000) {
		mid = len / 2;
		//cout << mid << '\n'
		ll i = 1, j = 1, k = n, f = 1;
		while(i < mid) {
			f = 0;
			ll _aj;
			if( mid + 1 - i >= a[j] )
				_aj = a[j];
			else
				_aj = mid+1-i;
			//cout << _aj << ' ';
			while(_aj > 0) {
				f = 1;
				int flag = (c[k] != c[j]);
				if(a[k] <= _aj) {
					if(flag)
						ans += a[k];
					_aj -= a[k];
					i += a[k];
					k--;
				} else {
					if(flag)
						ans += _aj;
					a[k] -= _aj;
					i += _aj;
					_aj -= _aj;
				}
				//cout << _aj << ' ';
			}
			j++;
			//cout << i << '\n';
		}
	} else {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= a[i]; ++j) {
				s += c[i];
			}
		}
		for(int i = 0; i < len; ++i)
			if( s[i] != s[ len-1-i ] )
				ans++;
	}
	cout << ans;
	return 0;
}
