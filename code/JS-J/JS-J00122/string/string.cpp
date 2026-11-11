#include <iostream>
#include <cstdio>
#include <string>
#define int long long
using namespace std;
int n;
long long a[200002];
char c[200002];
string str;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for(int j = 0; j < a[i]; ++j){
			str += c[i];
		}
	}
	for(int i = 0; (i + i) < str.length(); i++){
		if(str[i] != str[str.length() - i - 1]) ans++;
	}
	cout << ans << "\n";
	return 0;
}
/* fo zu bao you    mei you bug */
