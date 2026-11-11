//#include <bits/stdc++.h>
#include <iostream>
#define int long long
using namespace std; 

const int N = 2e5 + 5;
int a[N], n, m, f[N], maxx;
bool b[N];

void dfs(int pos)
{
	if(pos > m) {
		int cnt = f[1] & f[2];
		for(int i = 3; i <= m; i ++) 
			cnt = cnt & f[i];
			
		maxx = max(cnt, maxx);
		return ;
	}
	
	for(int i = pos; i <= n; i ++) {
		if(!b[i]) {
			b[i] = 1;
			f[pos] = a[i];
			dfs(pos + 1); 
			b[i] = 0; 
		}
	}
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
 
	cin >> n >> m;  
	
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		maxx = max(a[i], maxx);
	} 
	
	if(m == 1) return cout << maxx, 0;
	else if(m == 2) {
		maxx = 0;
		
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1; j <= n; j ++)  
				maxx = max(maxx, a[i] & a[j]); 
		}
		
		return cout << maxx, 0;
	}
	else maxx = 0;
	
	dfs(1);
	
	return cout << maxx, 0;
} 
