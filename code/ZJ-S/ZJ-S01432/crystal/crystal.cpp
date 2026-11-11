#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define DEBUG

/* 
	2nd trial
	double pointer + Special properties
	
	Might be O(n^2)
*/

int n, m;
const int N = 5e5 + 10;
int a[N];

signed main(){
	
	ios :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	int ans = 0;
	
	bool the_same = true;
	
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		if(i > 1 && a[i] != a[i-1]) the_same = false;
	}

	if(the_same){
		// Special property A
		//cout << "HAHA, It's the same!\n";
		cout << n << '\n';
		return 0;
	}
	
	sort(a+1, a+1+n,greater<int>());
	// DEBUG
	#ifdef DEBUG
	for(int i=1; i<=n; i++){
		cout << "PRIMARY ai" << a[i] << '\n';
	}
	#endif
	
	// Special property B
	if(n == 1){
		cout << 1 << '\n'; return 0;
	}
	int diff = a[2] - a[1];
	bool spB = true;
	for(int i = 3; i<=n; i++){
		if(a[i] - a[i-1] != diff) spB = false;
	}

	if(spB){
		for(int i = 2; i<=n; i++){
			#ifdef DEBUG
			cout << "Entered for\n";
			cout << "Now i " << i << '\n';
			cout << "Now cost " << -diff*i*(i-1)/2 << '\n';
			#endif
			if(-diff*i*(i-1)/2 > m) {
				#ifdef DEBUG
				cout << "Now cost " << -diff*i*(i-1)/2 << '\n';
				cout << "This is spB\n";
				#endif
				cout << i-1 << '\n';
				return 0;
			}
		}
	}
	
	int i = 1, j = 1;
	for(; i<=n && j <= n;){
		int cost = 0;
		for(int k = i+1; k<=j; k++){
			cost += (a[i] - a[k]);
		}
		#ifdef DEBUG
		cout << cost << "cost\n";
		#endif
		if(cost > m){
			#ifdef DEBUG 
			cout << "debug:" << j << ' ' << i << '\n';
			cout << "debug:" << ans << '\n';
			#endif
			i ++;
			continue;
		}
		ans = max(ans, j-i+1);
		#ifdef DEBUG
		cout << "debug:" << i << ' ' << j << '\n';
		cout << "debug:" << ans << '\n';
		#endif
		j++;
	}
	
	cout << ans << '\n';
	
	return 0;
} 











