#include<bits/stdc++.h>
using namespace std;
long long a[200005],maxn;
int n, m;
int main () {
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1) {
        cout << maxn;
        return 0;
    } else if(m==2) {
        maxn=0;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                long long x=int (a[i]) && int (a[j]);
                maxn=max(maxn,x);
            }
        }
        cout << maxn;
        return 0;
    } else {
        cout << a[m];
    }
}
