#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	for(int i = 1;i <= n;i++){
		int a;
		char c;
		cin >> a >> c;
		for(int j = 1;j <= a;j++){
			s += c;
		}
	}
	int len = s.size()-1;
	long long ans = 0;
	int f = 1;
	if((len + 1) % 2 == 0)f = 0;
	for(int i = 0;i < len / 2 + f;i++){
		if(s[i] != s[len-i])ans++;
	}
	cout << ans;
	return 0;
}

