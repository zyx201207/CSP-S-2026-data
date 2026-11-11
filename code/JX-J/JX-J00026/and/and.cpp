#include<bits/stdc++.h>
using namespace std;

int a[200005],b[200005];

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,t = 0,sum = 0;
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++) {
        t = n - 1;
        for(int j = 0;j < t;j++) {
            b[j] = a[i] & a[j + 1];
        }
    }
    int maxn = 0;
    for(int i = 0;i < t;i++) {
        sum = max(maxn,b[i]);
    }
    cout << sum;
    return 0;
}
