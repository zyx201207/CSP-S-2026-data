#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int n, m;
int a[500002];
int s[500002];
int cnt;
int pos[300002];
int ans[300002];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cnt = 0;
		memset(pos, 0xFF, sizeof(pos));
		for(int j = i; j <= n; j++){
			if(pos[a[j]] != -1){
				for(int k = pos[a[j]] + 1; k < cnt; k++){
					pos[s[k]] = -1;
				}
				cnt = pos[a[j]];
			}
			s[cnt] = a[j];
			pos[a[j]] = cnt;
			cnt++;
			//
			// for(int k = 0; k < cnt; k++){
			// 	cerr << s[k] << " ";
			// }
			// cerr << "\n";
			//
		}
		for(int j = 0; j < cnt; j++){
			ans[s[j]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
/* fo zu bao you   mei you bug */
