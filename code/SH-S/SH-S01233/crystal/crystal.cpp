#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],need,ans;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(long long i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    long long head = 1,tail = 1;

    while(tail <= n) {
        need = need + (tail - head + 1) * (a[tail+1] - a[tail]);
        tail++;
        while(need > m) {
            need -= (a[tail] - a[head++]);
        }
        ans = max(ans,tail - head + 1);
    }
    cout << ans;
    return 0;
}
