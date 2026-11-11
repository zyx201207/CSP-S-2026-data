#include<bits/stdc++.h> 
using namespace std;
const int N = 550000;
const int M = 330000;
int n, m, a[N], pos[M], ans[M]; 

signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i=1; i<=n; ++i) cin >> a[i];
	
	int t;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j) pos[j] = -1;
		for(int j=i; j<=n; ++j){
			t = pos[a[j]];
			if(t!=-1){
				for(int i=1; i<=n; ++i){
					if(pos[i]>t) pos[i] = -1; 
				}
			}
			pos[a[j]] = j;
//			for(int j=1; j<=m; ++j) cout << pos[j] << ' ';
//			cout << '\n';

		}
//		cout << i << ':';
		for(int j=1; j<=m; ++j){
//			cout << pos[j] << ' ';
			if(pos[j]!=-1) ans[j]++;
		} 
//		cout << '\n' << "-------------------\n";
	}
	
	for(int i=1; i<=m; ++i) cout << ans[i] << ' ';
	
	return 0;
}
