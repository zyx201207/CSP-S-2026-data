#include <bits/stdc++.h>
using namespace std;
string s = "";
int main(){
	freopen("string.in", "r" ,stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long len = 0;
	for (int i = 1; i <= n; i++){
		int num;
		char c;
		cin >> num >> c;
		len += num* 1ll;
		while(num--){
			s+=c;
		}
	}
	//cout << s;
	int cnt = 0;
	for (long long i =1; i <= (len+1) / 2; i++){
		long long l = i-1;
		long long r = len - l - 1;
		if (s[l] != s[r]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
