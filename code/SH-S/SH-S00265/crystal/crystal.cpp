#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

__int128 s = 0;
long long l = 0, r = 0;
long long cry[MAXN];
long long n, m, ans = 0;



int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i ++) cin >> cry[i];
	
	sort(cry, cry + n);
	
	
	for(l = 0; l < n; l ++){
		r = max(r, l);
		
		while(r < n - 1 && s + (cry[r + 1] - cry[r]) * (r - l + 1) <= m){
			s += (cry[r + 1] - cry[r]) * (r - l + 1);
			r ++;
		}
		
		ans = max(ans, r - l + 1);
		
		s -= cry[r] - cry[l];
	}
	
	cout << ans;
	
	return 0;
}
