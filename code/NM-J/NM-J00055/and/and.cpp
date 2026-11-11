#include<bits/stdc++.h>
using namespace std;
int a[200005],maxn = 0;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    for (int i =1;i<=n;i++) {
        cin >> a[i];
    }
    for (int i =1;i<=n;i++) {
        for (int j =1;j<=n;j++) {
            if (a[i] == a[j]&&maxn < a[i]) {
                maxn = a[i];
            }
        }
    }
    cout < manx;
    return 0;
}