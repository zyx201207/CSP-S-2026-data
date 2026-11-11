#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	clock_t st = clock();
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	int ans[m+1],b[n+1];
	int cnt[m+1];
	for(int i = 1;i<=n;i++){
		cin >> b[i];
		ans[b[i]] = i;
	}
	for(int i = 1;i<=n;i++){
		if(cnt[b[i]] == 0){
			cnt[b[i]]++;
		} else {
			for(int j = i;j >= 0;j--){
				if(b[j] == b[i]){
					for(int k = j+1;k<i;k++) ans[b[k]]--;
				}
			}
		}
	}
	for(int i = 1;i<=m;i++) cout << ans[i] << " ";		
	
	cerr << '\n';
	clock_t et = clock();
	double sec = double(et-st) / CLOCKS_PER_SEC;
	double ms = sec*1000;
	cerr << "time:" << ms << "ms";
	return 0;
}
