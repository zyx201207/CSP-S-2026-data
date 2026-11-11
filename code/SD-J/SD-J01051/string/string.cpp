#include <bits/stdc++.h>
using namespace std;
bool check(string s){
	int l = 0 , r = s.size() - 1;
	while(l <= r){
		if(s[l] != s[r]) return false;
		l++ , r--;
	}
	return true;
}
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >>n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	string s = "";
	while(n--){
		int k ;
		char a; 
		cin >> k >> a;
		for(int i = 1; i <= k ;i++){
			s += a;
		}
	}
	if(check(s)){
		cout << 0; 
		return 0;
	}
	int len = s.size() / 2;
	int ans = 0;
	for(int i = 0 , j = s.size() - 1; i < len; i++ , j--){
		if(s[i] != s[j]){
			ans++;
		}
	}
	cout << ans;
		


	return 0;
}

