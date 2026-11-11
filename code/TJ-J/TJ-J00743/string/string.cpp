#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	int a[200005];
	string s = "";
	string t;
	for(int i = 1; i <= n; i++){
		char c;
		cin >> a[i] >> c;
		for(int j = 1; j <= a[i]; j++){
			s += c;
		}
	}
	t = s;
	reverse(t.begin() , t.end());
	if(t == s){
		cout << 0;
		return 0;
	}
	int cnt = 0;
	if(s.size() % 2 == 0){
		int l = 0 , r = s.size() - 1;
		while(r > l){
			if(s[l] != s[r]){
				cnt++;
				l++;
				r--;
			}
		}
	}else{
		int l = 0 , r = s.size() - 1; 
		while(r != (s.size() - 1) / 2){
			if(s[l] != s[r]){
				cnt++;
				l++;
				r--;
			}
		}
	}
	cout << cnt;
	return 0;
}
