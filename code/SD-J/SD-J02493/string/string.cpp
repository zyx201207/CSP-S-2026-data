#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct jjs{
	ll sh;
	char e;
};
bool check(string s){
	string s1 = s;
	reverse(s.begin(), s.end());
	if(s == s1) return 1;
	return 0;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, ans = 0, c = 0;
	string s;
	cin >> n;
	jjs a[n];
	cin >> a[0].sh>> a[0].e;
	c += a[0].sh;
	bool b = 1;
	for(int i = 1; i < n; i++){
		cin >> a[i].sh >> a[i].e;
		c += a[i].sh;
		if(a[i].e != a[i - 1].e)
		b = 0;
	}
	if(b == 1){
		cout << 0 << endl;
		return 0;
	}
	string wjw;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= a[i].sh; j++){
			wjw += a[i].e;
		}
	}
	ll l, r;
	if(c % 2 == 0){
		l = c / 2;
		r = (c + 1) / 2;
	}
	else{
		l = c / 2;
		r = c / 2;
	}
	bool fd = 1, t = 1;
	while(fd != 0 && t != 0){
		if(l == 0){
			fd = 0;
		}
		if(r == n){
			t = 0;
		}
		if(fd != 0){
			l--;
		}
		if(t != 0){
			r++;
		}
		string s1;
		for(int i = l; i < r; i++){
			s1 += s[i];
		}
		if(check(s1) == 0){
			s[r] = s[l];
			ans++;
		}
	}
	cout << ans;
	return 0; 
}
