#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
	Shall I compare thee to a summer's day?
	Thou art more lovely and more temprate.
	
	1st Trial 
	- Special Property A & cut down
*/

const int N = 2e6 + 10;
int a[N];

signed main(){
	
	ios :: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t; cin >> c >> t;
	
	while (t--){
		
		int n, d; cin >> n >> d;
		
		int real_n = n;
		bool spA = true;
		bool failed = false;
		int diff;
		for(int i = 1; i<=n; i++){
			cin >> a[i];
			
			//cout << a[i] - a[i-1] << '\n';
			
			if(a[i] - a[i-1] > d || failed){
				real_n--;
				failed = true;
				continue; 
			}
			if(i == 2) diff = a[2] - a[1];
			else if(i > 2 && a[i] - a[i-1] != diff) spA = false;
		}
		
		if(spA){
			if(a[3] - a[1] > d || a[4] - a[1] <= d){
				cout << 0 << '\n';
				continue;
			}
			else{
				cout << real_n-3 << '\n';
				continue;
			}
		}
		
		cout << "Not spA\n";
		
	}
	return 0;
}




