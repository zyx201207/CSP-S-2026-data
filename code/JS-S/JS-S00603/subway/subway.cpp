#include <bits/stdc++.h>
using namespace std;
int a[500005],n,m,t[500005],x,d,q,nn;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> x >> n >> m >> d >> q;
    if (n == 1){
        for (int i = 1;i <= m;i++){
            cin >> t[i];
        }
        cin >> nn;
        for (int i = 1;i <= nn;i++){
            int y;
            cin >> x >> y;
            a[x] = y;
        }
        for (int i = 1;i <= q;i++){
            int y;
            cin >> x >> y;
            int sum = t[x] + t[y];
            for (int i = x;i <= y;i++){
                if (a[i] != 0){
                    sum += a[i];
                }
            }
            cout << sum;
        }
    }
}
