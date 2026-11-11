#include <bits/stdc++.h>
using namespace std;

string s, a1, a2;
int n, cnt;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a;
		string b;
		cin >> a >> b;
		for (int j = 1; j <= a; j++){
			s += b;
		}
	}
	a1 = s;
	a2 = s;
	if (n = 1){
		cout << 1;
	}
	else {
		cout << 2;
	}
	
	return 0;
}
