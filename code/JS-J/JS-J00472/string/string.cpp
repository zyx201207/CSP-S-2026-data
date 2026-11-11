#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct Node{
    long long num;
    char c;
} a[N];
int n;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 1;i <= n;i++) {
        cin >> a[i].num >> a[i].c;
    }

    int l = 1, r = n;
    long long ans = 0;
    Node x = a[l], y = a[r];
    while(l < r) {
        if (x.c == y.c) {
            int mn = min(x.num, y.num);
            x.num -= mn;
            y.num -= mn;
        } else {
            int mn = min(x.num, y.num);
            ans += mn;
            x.num -= mn;
            y.num -= mn;
        }
        if (x.num == 0) {
            l++;
            x = a[l];
        }
        if (y.num == 0) {
            r--;
            y = a[r];
        }
    }


    cout << ans;

    return 0;
}
