#include<bits/stdc++.h>
using namespace std;
long long n;
string s = "";
long long cnt;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		long long t;
		string x;
		cin >> t >> x;
		while(t--) s += x;
	}
	int len = s.size();
	if(len % 2 == 0) {
		for(int i = 0; i < len / 2; i ++) {
			if(s[i] != s[len-i-1]) {
				cnt ++;
			}
		}
	} else {
		for(int i = 0; i <= len / 2; i ++) {
			if(s[i] != s[len-i-1]) {
				cnt ++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
// T2:±©Á¦TLE qwq  Ô¤ÆÚ70 
