#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	int cnt[n], ccc = 0;
	char c[n];
	for (int i = 0; i < n; i++){
		cin >> cnt[i] >> c[i];
	}
	
	for (int i = 0; i < n; i++)  ccc += cnt[i];
	
	//char s[ccc] = {0};
	int mem = 0;
	/*for (int i = 0; i < n; i++){
		for (int j = 0; j < cnt[i]; i++){
			s[j + mem] = c[i];
		}
		mem += cnt[i];
	}*/
	
	//for (int i = 0; i < ccc; i++)  cout << s[i];
	cout << ccc;
	return 0;
}

















































































// ???
// LLL
