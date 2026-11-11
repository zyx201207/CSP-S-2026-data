#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 4;
int n,m,a[N],ans,nmax;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        nmax = max(nmax,a[i]);
    }
    if (m == 1) {
        cout << nmax;
        return 0;
    }
    sort(a + 1,a + n + 1);
    ans = a[n];
    for (int i = n - 1;i >= n - m + 1;i--){
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
//The world without this problem.
//Please give me some scores.
