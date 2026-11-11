#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, cnt, ans, cmt = 0;
int a[N];
bool b;
int main()
{
	string v, s;
	char d;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		cin >> v[i];
		if(v[i] != v[i - 1] && i != 0){
			b = 1;
		}
	}
	if(b == 0){
		cout << 0;
		return 0;
	}
	for(int i = 0, u = 0; i < n; i ++){
		for(int j = 0; j < a[i]; j ++, u ++){
			s[u] = v[i];
			ans ++;
		}
	}
	cnt = 0;
	for(int g = 0, r = ans / 2 + 1; g < ans / 2, r < ans; g ++, r ++){
		if(s[g] != s[r]){
			cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}


