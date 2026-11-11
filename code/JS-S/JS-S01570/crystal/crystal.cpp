#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int a[N];
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    long long n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort (a+1, a+1+n);

    int l = 1;
    long long now = 0;
    for (int i = 1; i <= n; ++i) {
        now += (a[i]-a[i-1]) * (i-l);
        if(now <= m) {
            ans = max(ans, i-l+1);
        }  else {
            while (now > m){
                now += a[l] - a[i];
                ++l;
            }
            ans = max(ans, i-l+1);
        }
    }
    cout << ans;
    return 0;
}
