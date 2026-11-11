#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,cnt = 0,l = 0;
	string s;
	cin >> a;
	for(int i = 0;i < a;i++){
		int b;
		char c;
		cin >> b >> c;
		l += b;
		for(int i = 0;i < b;i++){
			s += c;
		} 
	}
	if(l % 2 != 0){
		for(int i = floor(l * 1.0 / 2)-1;i >= 0;i--){
			if(s[i] != s[i+2*(floor(l * 1.0 / 2)-i)])
			cnt++;
		}
	}else{
		for(int i = floor(l * 1.0 / 2)-1;i >= 0;i--){
			if(s[i] != s[i+2*(floor(l * 1.0 / 2)-i)-1])
			cnt++;
		}
	} 
	cout << cnt;
	return 0;
} 
