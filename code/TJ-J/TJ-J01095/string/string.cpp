#include<bits/stdc++.h> 
using namespace std;

	
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a[100006], cnt = 0;
	string s;
	char c[100006];
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	for(int i = 0; i <= n; i++){
		for(int j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}
	for(int i = 1; i <= floor(s.size()/2)+1; i++){
		if(s[i-1] != s[s.size()-1]){
			s[s.size()-1] = s[i-1];
			cnt++;
		}
	} 
	cout << cnt;
	return 0;
}
