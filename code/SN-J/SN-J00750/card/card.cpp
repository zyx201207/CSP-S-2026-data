//齐君豪 西安市含光中学 SN-J00750
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500010;
const int M = 300010;

int n, m;
int a[N];
int lst[M];
int cnt[M];
int pre[N];
int lst_alive[N], lst_alive_id[M];
int dp[N];
int l[M], r[M];
int ans[M];
int die[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	bool flag = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		if(a[i - 1] > a[i]) flag = 0;
	}
	if(flag) {
		for(int i = 1; i <= m; i++)
			cnt[i] = cnt[i - 1] + cnt[i];
		for(int i = 1; i <= m; i++)
			printf("%d ", cnt[i]);
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		if(lst[a[i]] != 0)
			pre[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	dp[n + 1] = 0;
	lst_alive[n + 1] = n + 1;
	for(int i = n; i >= 1; i--) {
		if(lst_alive_id[a[i]] != 0 && dp[lst_alive_id[a[i]]] <= i) {
			if(!lst_alive[a[i]])
				lst_alive[a[i]] = lst_alive_id[a[i]];
			dp[i] = max(dp[lst_alive[a[i]] + 1], pre[i]);
			lst_alive_id[a[i]] = i;
			//cout<<i<<":"<<lst_alive[i]<<"\n";
		} else {
			lst_alive_id[a[i]] = i;
			dp[i] = max(dp[i + 1], pre[i]);
		//	cout<<i<<":"<<lst_alive[i + 1]<<"\n";
		}
		//cout<<i<<":"<<dp[i]<<"\n";
	}
	for(int i = n; i >= 1; i--) {
		if(l[a[i]] == r[a[i]] && l[a[i]] == 0) {
			l[a[i]] = dp[i] + 1, r[a[i]] = i;
		} else {
			if(i >= l[a[i]])
				l[a[i]] = dp[i] + 1;
			else {
				ans[a[i]] += r[a[i]] - l[a[i]] + 1;
				l[a[i]] = dp[i] + 1, r[a[i]] = i;
			}
		}
	}
	for(int i = 1; i <= m; i++)
		if(r[i] && l[i])
			ans[i] += r[i] - l[i] + 1;
	for(int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
} 
