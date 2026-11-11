#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N],c[N],sum;
int flag1 = 1;
signed main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        c[a[i]]++;
        if(a[i] < a[i - 1])
            flag1 = 0;
    }
    if(flag1) {
        for(int i = 1;i <= m;i++) {
            sum += c[i];
            cout << sum << " ";
        }
    }
    if(m == 1)
        cout << n;
    if(m == 2) {
        cout << (c[2] + 1) / 2 << " " << n;
    }
    return 0;
}
