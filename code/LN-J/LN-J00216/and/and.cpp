#include <bits/stdc++.h>
using namespace std;
int n,a[200005],m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int maxn = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)cin >> a[i];
    if (m == 1){
        for (int i = 1;i <= n;i++)maxn = max(maxn,a[m]);
        cout << maxn;
        return 0;
    }
    if (m == 2){
        for (int i = 1;i <= n;i++)for (int j = i+1;j <= n;j++)maxn = max(maxn,a[i]&a[j]);
        cout << maxn;
        return 0;
    }
    else if (m ==n){
        maxn = a[1];
        for (int i = 2;i <= n;i++)maxn &= a[i];
        cout << maxn;
        return 0;
    }
    return 0;
}
