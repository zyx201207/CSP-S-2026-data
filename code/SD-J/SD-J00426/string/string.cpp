#include <bits/stdc++.h>
using namespace std;

int T;
string sum = "";
int cnt = 0;

bool check(string s) {
	string ss = s;
	reverse(s.begin(), s.end());
	if(s == ss) return true;
	else return false;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> T;
	
	for (int i = 1; i <= T; i++){
		string s1 = "";
		int t;
		char ch;
		cin >> t >> ch;
		for (int i = 0; i < t; i++)
			s1 += ch;
		sum += s1;
	}
	
	if(check(sum)) cout << 0;
	
	else {
		int l = 0, r = sum.size();
		int mid = l + (r + l) / 2;
		for (int i = 1; i <= mid; i++) {
			if(sum[l] != sum[r]){
				cnt++;
				l++;
				r--;
			}
		}
	}
	cout << cnt;
	return 0;
}
