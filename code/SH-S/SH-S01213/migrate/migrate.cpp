#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, t;
int n, d;
int x[2000005];

int min_dis = INT_MAX, cnt = 0;

void dfs(int l, int r, int pre, int cur, int dis){
//	cout << l << " " << r << " " << pre << " " << cur << " " << dis << "\n";
	if(cur == r){
		int lst_dis = dis + 1;
		if(lst_dis < min_dis){
			min_dis = lst_dis;
			cnt = 1;
//			cout << "lower! " << min_dis << "\n";
		} else if(lst_dis == min_dis){
			cnt++;
//			cout << "equal! " << min_dis << "\n";
		}
		return;
	}

	if(x[cur + 1] - x[pre] <= d) dfs(l, r, pre, cur + 1, dis);
	if((cur != l) && (x[cur + 1] - x[cur] <= d)) dfs(l, r, cur, cur + 1, dis + 1);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	if(c == 1 || c == 2){
		for(int times = 1; times <= t; times++){
			cin >> n >> d;
			for(int i = 1; i <= n; i++){
				cin >> x[i];
			}
			int ans = 0;
			for(int i = 1; i <= n; i++){
				for(int j = i + 2; j <= n; j++){
					dfs(i, j, i, i, 0);
					if(cnt == 2){
	//					cout << i << " " << j << "\n";
						ans++;
					}
					min_dis = INT_MAX;
					cnt = 0;
				}
			}
			cout << ans << "\n";
		}
	} else if(c == 11 || c == 12){
		for(int times = 1; times <= t; times++){
			cin >> n >> d;
			for(int i = 1; i <= n; i++){
				cin >> x[i];
			}
			int ans = 0;
			for(int i = 1; i + 2 <= n; i++){
//				for(int j = i + 3; j <= n; j += 2){
//					int r_mid = i + (j - i + 1) / 2;
//					if(x[r_mid] - x[i] <= d && x[r_mid + 1] - x[i] > d){
//						ans++;
//					}
//				}
				if(!(x[i+2] - x[i] > d) && !(x[i + (n - i - 1) / 2 * 2 + 1] - x[i] <= d)){
					ans++;
//					cout << i << "\n";
				}
			}
			
			cout << ans << "\n";
		}
	}

	return 0;
}


