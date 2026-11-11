#include<bits/stdc++.h>
using namespace std;

long long n, a[100005], cnt = 0, d = 0;
string s, c;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c;
		for(int j = 1; j <= a[i]; j++){
			s += c;
		}
		d+= a[i];
	}
	for(int i = 0; i < (d+1)/2; i++){
		if(s[i] != s[d-i-1] && s[i] + s[d-i-1] > max(s[i], s[d-i+1])){
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
