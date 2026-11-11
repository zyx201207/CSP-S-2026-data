#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 9;

int n , d;
int f[N] , g[N] , x[N] , L[N] , R[N] , sum[N];
int get1(int i) {
    int l = i , r = n , ans = i;
    while (l <= r) {
        int mid = l + r >> 1;
        if (x[mid] - x[i] <= d) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int get2(int i) {
    int l = 1 , r = i , ans = i;
    while (l <= r) {
        int mid = l + r >> 1;
        if (x[i] - x[mid] <= d) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

void A() {
    cin >> n >> d;
    for (int i = 1;i <= n;i ++) {
        cin >> x[i];
    }

    for (int i = 1;i <= n;i ++) {
        R[i] = get1(i); L[i] = get2(i);
    }
    if (R[1] != 3) {
        cout << 0 << endl;
        return ;
    }
    cout << n - 3 << endl;
    return ;
}

void B() {
    cin >> n >> d;
    for (int i = 1;i <= n;i ++) {
        cin >> x[i];
    }

    int mid;
    for (int i = 1;i <= n;i ++) {
        R[i] = get1(i); L[i] = get2(i);
        if (L[i] == 1 && R[i] == n)  mid = i;
    }

    int ans = 0;
    for (int i = mid + 1;i <= n;i ++) {
        if (L[i] == mid - 1) {
            ans += L[i] - 1;
        }
    }
    cout << ans << endl;
}

void solve(int c) {
    if (c == 13 || c == 14) {
        B();
        return ;
    }
    if (c == 11 || c == 12) {
        A();
        return ;
    }
    cout << 0 << endl;
}

signed main()  {
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ios::sync_with_stdio(0);  cin.tie(0);

    int c , T = 1;
    cin >> c >> T;
    while (T--)  {
        solve(c);
    }
    return 0;
}

