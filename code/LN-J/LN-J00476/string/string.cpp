#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    ll nums;
    char c;
} a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].nums >> a[i].c;
    }
    ll l = 0, r = n - 1;
    ll ans = 0;
    while(l < r) {
        if (a[l].c != a[r].c) {
            ans++;
            a[l].nums--;
            a[r].nums--;
        } else {
            a[l].nums--;
            a[r].nums--;
        }
        if(a[l].nums == 0) l++;
        if(a[r].nums == 0) r--;
    }
    cout << ans << endl;
    return 0;
}
