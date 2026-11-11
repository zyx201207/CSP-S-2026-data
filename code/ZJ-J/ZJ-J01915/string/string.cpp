#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5; 
int n;
ll len, d[N], ans, mlen;
int a[N];
char ch[N];
ll nxt (ll pos, ll i1, ll in) { 
	ll p;
	if (i1 == in) p = mlen + 1;
	else p = (d[i1] >= mlen) ? min(mlen, pos + len - d[in - 1]) : min(d[i1], pos + len - d[in - 1]); 
	if (p == pos) return mlen + 1;
}
int main() { 
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> ch[i];
		d[i] = d[i - 1] + a[i];
		len += a[i];
	}
	mlen = (len % 2 == 1) ? (len + 1) >> 1 : len >> 1;/*
	int i = 1;
	ll last = 0, l = 0;
	int li = 1;
	while (1) {
		l = (d[i] > mlen) ? mlen : d[i];
		if (l > mlen) break;
		if (l == mlen) {
			if (ch[i] != ch[n - i + 1]) {
				ans += max(mlen - last + 1, a[n - i + 1])
			} else {
				
			}
			break;
		} else {
			if (ch[i] != ch[n - i + 1]) {
				ans += min(a[i] - ((li == 2) ? last : -last), a[n - i + 1]);
				if (d[i] - ((li == 2) ? last : - last) <= len - d[n - i]) {
					last = d[i];
					li = 1;
				} else {
					last = len - d[n - i];
					li = 2;
				}
			} else {
				last = 
			}
		}
		i++;
	}*/
	ll i1 = 1, in = n;
	for (ll i = 1; i <= mlen; i++) {
//		cout << i << " "  << i1 << " "<< ch[i1] << " " << len - i + 1 << " "<< in << " " << ch[in] << "\n";
		if (ch[i1] == ch[in]) continue;
		ans++;
		if (i == d[i1]) i1++;
		if (len - i + 1 == d[in - 1]) in--;
	}
	cout << ans;
	return 0;
}
