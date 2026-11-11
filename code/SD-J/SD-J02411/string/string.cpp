#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int a;
string ss;
int len;
bool check(int mid){
	int cnt = 0;
	int l = 0, r = len - 1;
	while(l != r){
		if(s[l] != s[r]) cnt++;
		l++;
		r--;
	}
	if(cnt <= mid) return true;
	return false;
}
bool checkk(int mid){
	int cnt = 0;
	int l = 0, r = len - 1;
	while(l != len / 2){
		if(s[l] != s[r]) cnt++;
		l++;
		r--;
	}
	if(cnt <= mid) return true;
	return false;
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> ss;
		for(int j = 1; j <= a; j++){
			s += ss;
		}
	}
	len = s.size();
	int midd;
	if(len % 2){
		midd = len / 2 + 1;
		int l = 0, r = midd;
		while(l < r){
			int mid = (l + r) / 2;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l;
	}
	else{
		midd = len / 2;
		int l = 0;
		int r = midd;
		while(l < r){
			int mid = (l + r) / 2;
			if(checkk(mid)) r = mid;
			else l = mid + 1;
		}
	}
	return 0;
}
//Trick||Treat!
