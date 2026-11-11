#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
int n, m;
long long a[N], pre[N], del[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    // for (int i=1; i<=n; i++) cout << a[i] << " ";
    // cout << endl;

    for (int i=1; i<=n; i++){
        pre[i] = pre[i-1] + a[i];
        del[i] = a[1] * i - pre[i];
    }
    

    int ans = -1;
    // del[n+1] = 0x3f3f3f3f3f3f3f3f;

    for (int i=1; i<=n; i++){
        // for (int i=1; i<=n; i++) cout << del[i] << " ";
        int res = upper_bound(del+i, del+n+1, m)-del-i;
        int delta = a[i] - a[i+1];
        for (int j=1; j<=n-i; j++){
            del[i+j] -= j * delta;
        }
        ans = max(ans, res);
        // cout << res << endl;
    }
    
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}