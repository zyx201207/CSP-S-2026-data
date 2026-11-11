#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll m, a[500005], s[500005];
bool check(int x){
	for(int i = x; i <= n; i++){
		if(a[i] * x - s[i] + s[i - x] <= m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1; 
	}
	cout << l;
	return 0;
}
/*

胡乱编造着催人泪下的故事
虚情假意后不幸已如期而至
——放 & 诗岸 《二十九分之一的幼稚犯》 

*/
