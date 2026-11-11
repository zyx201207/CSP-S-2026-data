#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int c, t;
int n, d;
int x[N], used[N], flag[1000][1000];

void dfs(int k) {
    if(k == n) {
        if(d < abs(x[k] - x[k - 1])) return ;
        used[k - 1]++;
        if(used[k - 1] < 3) dfs(k - 1);
    }
    else if(k == 1) {
        if(d < abs(x[k] - x[k + 1])) return ;
        used[k + 1]++;
        if(used[k + 1] < 3) dfs(k + 1);
    }
    else if(abs(x[k] - x[k - 1]) < abs(x[k] - x[k + 1]) && d >= abs(x[k] - x[k + 1])) {
        used[k - 1]++;
        if(used[k - 1] < 3) dfs(k - 1);
    }
    else if(abs(x[k] - x[k - 1]) > abs(x[k] - x[k + 1]) && d >= abs(x[k] - x[k - 1])) {
        used[k + 1]++;
        if(used[k + 1] < 3) dfs(k + 1);
    }
    else if(abs(x[k] - x[k - 1]) == abs(x[k] - x[k + 1]) && d >= abs(x[k] - x[k + 1])) {
        if(flag[k + 1][k - 1] == 1) return ;
        flag[k + 1][k - 1] = flag[k - 1][k + 1] = 1;
        used[k - 1]++;
        used[k + 1]++;
        if(used[k + 1] < 3) dfs(k + 1);
        if(used[k - 1] < 3) dfs(k - 1);
    }
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x[i]);
            used[i] = 0;
        }
        dfs(1);
        /*for(int i = 1; i <= n; i++) {
            for(int i = 1; i <= n; i++) {
                used[i] = 0;
            }
            dfs(i);
        }*/
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                ans += flag[i][j];
            }
        }
        printf("%d\n", ans / 2);
    }

	return 0;
}
