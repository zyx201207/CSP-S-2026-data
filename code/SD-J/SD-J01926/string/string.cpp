#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		char c;
		cin >> c;
		for(int i = 1; i <= n; i ++)
			s = s + c;
		
	}
	s = " " + s;
	int ans = 0;
	int l = s.size() - 1;
	for(int i = l / 2 + 1; i <= l; i ++){
		if(s[i] != s[l - i + 1])
			ans ++; 
	}
	cout << ans;
	
	
	
	
	return 0;
}

