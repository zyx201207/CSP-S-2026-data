#include <bits/stdc++.h>
using namespace std;
int n,d;
int x[2000005];
int a[2000005];
int c[2000005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    int res = 0;
    for(int i = 1; i <= m; i ++){
        int w;
        cin >> w;
        a[i] = a[i - 1] + w;
    }

    int k;
    cin >> k;
    for(int i = 1; i <= k; i ++){
        int p,g;
        cin >> p >> g;
        c[i] = c[i - 1] + g;
    }
    for(int i = 1; i <= q; i ++){
        int x,y;
        cin >> x >> y;
        cout << a[y] - a[x - 1] + c[y] - c[y - 1] << endl;
    }
    return 0;
}
