#include <bits/stdc++.h>
using namespace std;
#define str string
#define ll long long
void io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int N = 5e5 + 10;
int n;
ll m;
ll a[N];
int main() {
    io();
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a + 1, a + 1 + n);
    while(m > 0) {
        auto pos = upper_bound(a + 1, a + 1 + n,a[1]);
        ll tmp = (*pos - a[1]) * (pos - a - 1);
        if(tmp <= m) {
            for(int i = 1; i <= (pos - a - 1); i++) a[i] = a[i] + (tmp / (pos - a - 1));
        }
        m = m - tmp;
    }
    cout<<upper_bound(a + 1,a + 1 + n,a[1]) - a - 1;
    return 0;
}
