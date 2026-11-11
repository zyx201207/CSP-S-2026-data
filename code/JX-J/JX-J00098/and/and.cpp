#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {return a > b;}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m, l[100005];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> l[i];
    sort(l, l+n, cmp);
    long long num = l[0];
    for (int i = 0; i < m; i++) {
        num = num&l[i];
    }
    cout << num;
}
