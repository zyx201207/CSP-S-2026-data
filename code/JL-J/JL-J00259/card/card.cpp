#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in", "std.in", stdin);
	freopen("card.out", "std.out", stdout);
	int n, m;
	cin >> n >> m;
	int a[100000], s[100000] = {0}, p = 1, q = 1, x = 1;
	for(int i = 1; i <= n; i++) cin >> a[i];
	while(x <= n){
		p = x, q = x;
		for(; q <= n; q++){
			if(a[p] == a[q]) p = q;
		}
		for(int i = p; i <= q; i++){
			s[a[i]]++;
		}
		x++;
	}
	for(int i = 1; i <= m; i++){
		cout << s[i] << " ";
	}
}
