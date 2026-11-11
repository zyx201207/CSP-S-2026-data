#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
	Misty taste of moonshine,
	tear drops in my eyes.
	
	SPA only
*/




signed main(){
	
	ios :: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t; cin >> c >> t;
	
	while(t--){
		int n, k; cin >> n >> k;
		cout << (n / 2 + 1 - k)/4 + 1 << '\n';
	}
	
	
	return 0;
} 
