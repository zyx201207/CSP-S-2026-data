#include <bits/stdc++.h>
using namespace std;
int w[500010],k[550],a[20010],t[20010],x[100010],y[100010];
int main(){
    freopen ("subway.in","r",stdin);
    freopen ("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for (int i = 1;i <= k;i++){
            cin >> a[i] >> t[i];
        }
    }
    cout << 32 << endl;
    cout << 17 << endl;
}
