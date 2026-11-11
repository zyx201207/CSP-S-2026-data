//#include <bits/stdc++.h>
#include <iostream> 
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N]; char c[N];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i ++) 
		cin >> a[i] >> c[i]; 
	
	int l = 1, r = n, ans = 0;
	
	while(l < r) {
		int nl = a[l], nr = a[r];
		char cl = c[l], cr = c[r];
		
		if(cl == cr) {
			if(nl == nr) l ++, r --;
			else if(nl < nr) l ++, a[r] -= nl;
			else r --, a[l] -= nr;
		}
		
		else {
			if(nl == nr) l ++, r --, ans += nl;
			else if(nl < nr) l ++, a[r] -= nl, ans += nl; 
			else r --, a[l] -= nr, ans += nr;
		}
	}
	
	return cout << ans, 0;
} 
