#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2000010;
int a[N];
int n, d;
int c;

int mdist = 1e18;
int sum = 0;

int solveA(){
    if (a[2]-a[1] > d) return 0;
    int cnt = d/(a[2]-a[1]);
    if (cnt >= n-1) return 0;
    if (cnt+cnt > n) return 0;
    int ans = n-2*cnt+1;
    return ans;
}

void dfs(int u, int v, int dist){
    if (u == v){
        if (dist < mdist){
            mdist = dist;
            sum = 1;
            return;
        }

        if (dist == mdist){
            sum++;
            return;
        }
        return;
    }

    for (int i = u+1; i <= v; i++){
        if (a[i]-a[u] <= d)
            dfs(i, v, dist+1);
    }
}

int subtask1(){ // n <= 9
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            mdist = 1e18;
            sum = 0;
            dfs(i, j, 0);
            if(sum == 2) cnt++;
        }
    }
    return cnt;
}

int solve(){
    if (n == 1) return 0;
    if (c == 1 || c == 2) return subtask1();
    if (c == 11 || c == 12) return solveA();
    //if (c == 13 || c == 14) return solveB();
    //if (c >= 15 && c <= 18) return solveC();

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("migrate.in", "r", stdin);
    //freopen("migrate.out", "w", stdout);

    int t;
    cin >> c >> t;
    while(t--){
        for (int i = 1; i <= n; i++){
            a[i] = 0;
        }
        cin >> n >> d;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cout << solve() << '\n';
    }

    return 0;
}
