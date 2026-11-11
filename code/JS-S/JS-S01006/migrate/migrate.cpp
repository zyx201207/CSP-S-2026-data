#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int c,t;
int n,d;
int x[N], y[N];
int sum,mx;
long long ans;

void dfs(int s,int t,int u,int dep) {
    if(u>t) return;
    if(dep>mx) return;
    if(u==t) {
        if(dep<mx) {
            mx=dep;
            sum=0;
        }
        sum++;
        return;
    }
    for(int i=u+1;x[i]<=x[u]+d&&i<=n;i++){
        dfs(s,t,i,dep+1);
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t --) {
        cin >> n >> d;
        for (int i = 1; i <= n; i ++) {
            cin >> x[i];
            y[i] = 0;
        }
        ans = 0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                sum=0,mx=10000000;
                dfs(i,j,i,0);
                if(sum==2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
