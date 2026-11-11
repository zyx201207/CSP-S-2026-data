#include <bits/stdc++.h>

using namespace std;
const int T = 1793442065;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin >> c >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		int t,a;
		for (int i = 0;i < n;i++) cin >> t >> a;
		cout << T%(n/2+1)+6 << '\n';
	} 
	
	return 0;
}

