#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n;
long long d;
long long a[2000005];
int lt[5005], rt[5005];
int num[5005], dis[5005];
long long ans;
queue<int> q;
void bfs(int st){
	memset(num, 0, sizeof(num));
	memset(dis, 0x3f, sizeof(dis));
	q.push(st);
	num[st] = 1, dis[st] = 0;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = lt[x]; i <= rt[x]; i++)
			if (!num[i]){
				q.push(i);
				num[i] = num[x];
				dis[i] = dis[x] + 1;
			} else if (dis[x] + 1 == dis[i]){
				num[i] += num[x];
			}
	}
//	cout << "x = " << st << '\n';
	for (int i = 1; i <= n; i++){
//		cout << num[i] << ' ';
		ans += (num[i] == 2);
	}
//	cout << '\n';
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	if (c <= 10){
		while (t--){
			cin >> n >> d;
			a[0] = -(long long)5e18;
			for (int i = 1; i <= n; i++)
				cin >> a[i];
			a[n+1] = (long long)5e18;
			if (d == 1){
				cout << 0 << '\n';
				continue;
			}
			for (int i = 1; i <= n; i++){
				lt[i] = lower_bound(a+1, a+n+1, a[i]-d) - a;
				rt[i] = upper_bound(a+1, a+n+1, a[i]+d) - a - 1;
			}
			for (int i = 1; i <= n; i++)
				bfs(i);
			cout << ans / 2 << '\n'; 
			ans = 0;
		}
	} else if (c == 11 || c == 12){
		while (t--){
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> a[i];
//			cout << t << '\n';
			if (n == 1){
				cout << 0 << '\n';
				continue;
			}
			d = d / (a[2] - a[1]);
			if (d == 0 || d == 1){
				cout << 0 << '\n';
				continue;
			}
			cout << max(0ll, n - 2 * d + 1) << '\n';
		}
	}
	return 0;
}

