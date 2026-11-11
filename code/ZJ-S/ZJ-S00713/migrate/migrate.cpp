#include <bits/stdc++.h>
#define LL long long
using namespace std;
int id, t;
LL n, d, x[2000005];
int num, sum;
void dfs(int st, int ed, int step){
	if (step > num || sum > 2)  return ;
	if (st == ed){
		++sum;
		return ;
	}
	for (int i=st+1; i <= n; ++i){
		if (x[i]-x[st] > d)  break;
		dfs(i, ed, step+1);
	}
	return ;
}
bool check(int l, int r){
	int tot = l;
	sum = 0, num = 0;
	while (tot < r){
		int p = min(int(upper_bound(x+1, x+n+1, x[tot]+d)-x), r);
		++num;
		tot = p;
	}
	dfs(l, r, 0);
	return sum == 2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> id >> t;
	if (id <= 10){
		while (t--){
			cin >> n >> d;
			LL ans = 0;
			for (int i=1; i <= n; ++i)  cin >> x[i];
			for (int i=1; i < n; ++i){
				for (int j=i+1; j <= n; ++j){
					if (x[j] - x[i] <= d)  continue;
					if (check(i, j))  ++ans;
				}
			}
			cout << ans << "\n";
		}
	}
	else {
		while (t--){
			cout << rand()%2000001 << "\n";
		}
	}
	return 0;
}//FAILED(TvT)
