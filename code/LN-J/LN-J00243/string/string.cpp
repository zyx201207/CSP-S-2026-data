#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,ans = 0;
	cin >> n;
	int a[n];
	char b[n];
	for(int i = 0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	string s;
	for(int i = 0;i<n;i++){
		for(int j = 0;j < a[i];j++) s += b[i];
	}
	int l = 0,r = s.size()-1;
	while(l != r){
		if(s[l] != s[r]) ans++;
		l++;
		r--;
	}
	cout << ans;
	return 0;
}
