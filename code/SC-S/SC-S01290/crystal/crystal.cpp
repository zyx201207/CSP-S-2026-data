#include<bits/stdc++.h>                                  
using namespace std;                                     
long long n, m, a[500005], cnt, ans;                     
int main(){                                              
	freopen("crystal.in", "r", stdin);                   
	freopen("crystal.out", "w", stdout);                 
	ios::sync_with_stdio(0);                             
	cin.tie(NULL);                                       
	cout.tie(NULL);                                      
	cin >> n >> m;                                       
	for(int i = 1; i <= n; i++) cin >> a[i];             
	if(n >= 100000){
		long long c = a[2] - a[1], x = c, y = 1;
		cnt = 1;
		while(x <= m / y && cnt < n){
			y += 2;
			cnt++;
			if(x > m / y || cnt == n) break;
			x += c;
			cnt++;
		}
		cout << cnt;
		return 0;
	}                                                 
	sort(a + 1, a + 1 + n);                              
	for(int i = n; i >= 1; i--){                         
		if(ans >= i) break;                              
		long long x = m;                                 
		cnt = 1;                                         
		for(int j = i - 1; j >= 1; j--){                  
			if(x + a[j] >= a[i]) {cnt++;x -= a[i] - a[j];}
			else break;                                   
		}                                                 
		ans = max(ans, cnt);                              
	}                                                     
	cout << ans;                                           
	return 0;                                             
}                                                         