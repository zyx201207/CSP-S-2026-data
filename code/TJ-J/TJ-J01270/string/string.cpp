#include <bits/stdc++.h>
using namespace std;
string s,x;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	cin >> n;
	char c;
	for(int i = 0;i < n;i++){
		cin >> a >> c;
		for(int j = 0;j < a; j++){
			s[i] = c;
		}
	}
	for(int i = s.size();i >= s.size()/2;i--){
		x[i] = s[i];
	}
	int ans = 0;
	for(int i = 0;i < s.size()/2;i++){
		if(s[i] == x[i]){
			b[i] = s[i];
		}
		else{
			x[i] = s[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
