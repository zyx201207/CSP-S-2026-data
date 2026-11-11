#include <bits/stdc++.h>
using namespace std;

string s;
int n;
long long len;
long long ans;
int main (){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a;
		string c;
		cin >> a >> c;
		for (int i = 1; i <= a; i++){
			s += c;
			len ++;
		}
	}
	//cout << s << endl;
	for (long long i = 0; i < (len + 1) / 2; i++){
		long long j = len - 1 - i;
		if (s[i] != s[j]){
			//cout << i << ' ' << j << endl;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
