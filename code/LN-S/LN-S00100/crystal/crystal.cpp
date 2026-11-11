#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m, a[N];
int dp[10010][10010];
int ans = 0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> a[i];

    sort(a, a + n);

    for (int i = 0; i < n; i ++) {
        int mm = m;
        for (int j = 0; j < n; j ++) {
            dp[i][j] = 1;
            if (a[j] > a[i] || a[i] - a[j] > mm) continue;
            int num = a[i] - a[j], cnt = dp[i][j];
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
            if (dp[i][j] != cnt) mm -= num;
        }
    }

    int ii,jj;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if (ans < dp[i][j]){
                ans = dp[i][j];
                ii = i;
                jj = j;
            }
        }
    }

    cout << ans;

    return 0;
}
