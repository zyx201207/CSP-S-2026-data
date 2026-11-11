#include <bits/stdc++.h>
using namespace std;
string s;
char ch[200000];
unsigned long long num[200000], n;
bool tp = 1;
bool check (string s) {
	int f = 1;
	for (unsigned long long i = 0; i < s.size()/2; i++)
		if (s[i] != s[s.size()-i-1]) {
			f = 0;
			break;
		}
	return f;
}
unsigned long long d (string s, unsigned long long cnt) {
	if (check(s)) return cnt;
	for (unsigned long long i = 0; i < s.size()/2; i++)
		if (s[i] != s[s.size()-i-1]) {
			s[s.size()-i-1] = s[i];
			break;
		}
	return d(s, cnt+1);
}
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (unsigned long long i = 0; i < n; i++) cin >> num[i] >> ch[i];
	for (unsigned long long i = 1; i < n; i++)
	    if (num[i] != num[i-1]) {
	    	tp = 0;
	    	break;
		}
	if (!tp) for (unsigned long long i = 0; i < n; i++) for (unsigned long long j = 0; j < num[i]; j++) s += ch[i];
	else for (unsigned long long i = 0; i < n; i++) s += ch[i];
//	cout << s << '\n';
	if (!tp) cout << d(s, 0) << '\n';
	else cout << d(s, 0)*num[0] << '\n';
	return 0;
}
