#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N = 5e5 + 10;
int n; ll m, a[N], s[N]; 

/*
a[i~j]  ==>  a[j]

a[j]  找到一个最前面的i，a[j]*(j-i+1)-(s[j]-s[i-1]) 
i--  +a[j]  -a[i]   
*/

void solve() {
	
	cin >> n >> m; 
	for(int i=1;i<=n;i++) 
		cin >> a[i]; 
	
	sort(a+1, a+n+1); 
	for(int i=1;i<=n;i++)
		s[i] = s[i-1] + a[i]; 
	
	int mx = 1; 
	for(int j=1;j<=n;j++) {
		int L = 1, R = j, pos = -1; 
		while(L <= R) {
			int mid = (L+R)/2; 
			if(a[j]*(j-mid+1) - (s[j]-s[mid-1]) <= m) 
				pos = mid, R = mid - 1; 
			else L = mid + 1; 
		} if(pos == -1) continue; 
		mx = max(mx, j-pos+1); 
	}
	
	cout << mx; 
	
}

signed main() {

  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);

//  int _; cin >> _; while(_--)
	solve();
	
	return 0;
	
}

