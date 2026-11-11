#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,a;
	long long ans = 0;
	char c;
	string s,s1;
	cin>> n;
	for(int i = 1; i <= n; i++){
		cin>> a >> c;
	}
	for(int i = 1; i <= a; i++){
		s += c;
	}
	for(int i = a; i >= 1; i--){
		s1 += c;
	}
	if(s == s1){
		cout<< 0;
		return 0;
	}else{
		for(int i = 1; i <= 2 * 1e5; i++){
			if(s[i] != s1[i]){
				ans++;
			}else{
				i += 1;
			}
		}
	}
	cout<< ans;
	return 0;
}