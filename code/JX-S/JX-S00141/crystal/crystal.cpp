#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long cnt = 0;
    sort(a + 1, a + n + 1);
    cout << ceil(1.0 * m / 2);
    return 0;
}
