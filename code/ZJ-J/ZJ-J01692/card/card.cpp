#include<bits/stdc++.h>
using namespace std;
int n, m, a[500001], tj[300001], t[300001], tt[300001];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i], tj[a[i]] ++, t[a[i]] ++;
	for(int i = 1; i <= n; i ++){
		for(int j = i; j <= n; j ++){
			tj[a[j]] --;
		}
		for(int j = 1; j <= m; j ++){
			if(tj[j] > 0) tt[j] ++;
			tj[j] = t[j];
		}
	}
	for(int i = 1; i <= m; i ++) cout << tt[i] << " ";
;	return 0;
} 
