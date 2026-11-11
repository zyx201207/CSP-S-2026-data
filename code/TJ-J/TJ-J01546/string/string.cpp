#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	long long n, x[200005], cnt = 0, maxx = -1, maxi, sum = 0;
	cin >> n;
	char c[200005];
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> c[i];
		for(int j = 1; j <= x[i]; j++) s += c[i];
	}

	for(int i = 0; i < s.size() /2; i++){
		if(s[i] != s[s.size() - i -1]) sum++;
		
	}
	cout << sum;
	return 0;
} 
