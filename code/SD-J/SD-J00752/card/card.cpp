#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int vis[200005];
int last[200005];
bool viss[200005];
int ans[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			vis[j] = 0;
			last[j] = 0;
		}
		memset(viss,1,sizeof(viss));
		for(int j = i;j <= n;j++){
			if(vis[a[j]]){
				for(int k = last[a[j]];k < j;k++){
//					cout << k << ' ';
					if(!viss[k]){
						continue;
					}
					viss[k] = false;
					vis[a[k]]--;
				}
//				cout << endl;
				last[a[j]] = j;
			}
			last[a[j]] = j;
			vis[a[j]]++;
		}
//		for(int k = 1;k <= n;k++){
//			if(k < i){
//				cout << '?' << ' ';
//				continue;
//			}
//			cout << viss[k] << ' ';
//		}
//		cout << endl;
		for(int j = i;j <= n;j++){
			if(viss[j] == 1){
				ans[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
