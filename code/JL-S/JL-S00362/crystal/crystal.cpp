#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N], b[N];
long long n, m, l, r=1, k, maxn=-1;
//
int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i = 1; i < n; i++) {
        b[i] = a[i] - a[i-1];
    }
    while(r < n) {
        if(k > m) {
            k -= (a[r-1]-a[l]);
            l++;
            continue;
        }
        maxn = max(maxn, r-l);
        k += ((b[r])*(r-l));
        r++;
    }
    if (maxn==-1) maxn = n;
    if (b[1] > m) maxn = 0;
    cout << maxn;
}
