#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    long long maxn = 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    maxn = a[n];
    for (int i = n - 1;i >= n - m + 1;i--){
        maxn = maxn & a[i];
    }
    cout << maxn;
}
