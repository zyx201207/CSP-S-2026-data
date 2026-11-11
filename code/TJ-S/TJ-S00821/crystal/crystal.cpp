#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+3;
int n, arr[MAXN], l, r;
long long m, ans, dl, dr, tmp, fans;
bool cmp(int x, int y) {
    return x < y;
}

// if Ai is i
inline bool chk(){
    for (int i = 1; i <= n; i++){
        if (arr[i] != i) return false;
    }
    return true;
}

inline void solve1() {
    // select target
    for (int i = 1; i <= n; i++) {
        // in it
        l = i-1, r = i+1, tmp = m, ans = 0;
        // add crystal
        while (tmp >= 0){
            // get delta
            // FIX if l or r is over 1 or n
            if (l < 1 && r > n) break;  // both out
            if (l >= 1) dl = arr[i] - arr[l];
            else dl = m + 1;
            if (r <= n) dr = arr[r] - arr[i];
            else dr = m + 1;

            // calculate rest

            if (dl < dr) {
                tmp -= dl;
                if (tmp < 0) break;
                ans++;

                tmp -= dr;
                if (tmp < 0) break;
                ans++;
            } else {
                tmp -= dr;
                if (tmp < 0) break;
                ans++;

                tmp -= dl;
                if (tmp < 0) break;
                ans++;
            }

            l--, r++;
        }
        fans = max(fans, ans);
    }
    // add target self
    cout << fans + 1 << endl;
}

inline void solve2() {
    ans = fans = 1;
    for (int i = n - 1; i >= 1; i--){
        ans = arr[n] * (n-i+1) - ((arr[n] + arr[i]) * (n - i + 1) / 2);
        if (ans <= m) fans = ans;
        else break;
    }
    cout << fans;
}

inline void solve3() {
    for (int i = 1; i <= n; i++)
        if ((1 + (i - 1)) * (i - 1) / 2 > m) {
            cout << i - 1 << endl;
            break;
        }
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];


    if (n <= 5000) {
        sort(arr+1, arr+n+1, cmp);
        solve1();
    } else if (chk()) {
        solve3();
    } else {
        sort(arr+1, arr+n+1);
        solve2();
    }
    return 0;
}
