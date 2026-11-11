#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,m,n,d,q;
    cin >> c >> m >> n >> d >> q;
    long long b[n+1];
    for(int i = 1;i <= n;i++){
        cin >> b[i];
    }
    if(c >= 7 && c <= 11){
        long long a[n+1][n+1];
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                a[i][j] = 0x3f3f3f3f;
                if(i == j){
                    a[i][j] = 0;
                }
            }
        }
        for(int i = 1;i <= m;i++){
            long long total;
            cin >> total;
            long long x2,x4;
            int x1,x3;
            cin >> x1 >> x2 >> x3 >> x4;
            a[x1][x3] = x2+x4;
            a[x3][x1] = x2 + x4;
        }
        for(int k = 1;k <= n;k++){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    if(a[i][k] != 0x3f3f3f3f && a[k][j] != 0x3f3f3f3f){
                        a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
                    }
                }
            }
        }
        for(int i = 1;i <= q;i++){
            int e,r;
            cin >> e >> r;
            if(e == r){
                cout << 0 << endl;
                continue;
            }
            long long ert = a[e][r] + b[e] + b[r];
            cout << ert << endl;
        }
        return 0;
    }else{
        long long a[n+1][n+1];
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                a[i][j] = 0x3f3f3f3f;
                if(i == j){
                    a[i][j] = 0;
                }
            }
        }
        long long sdf = 0;
        int io = 0;
        for(int i = 1;i <= m;i++){
            long long total;
            cin >> total;
            vector < long long > we;
            for(int j = 1;j <= total;j++){
                long long x1,x2;
                cin >> x1 >> x2;
                we.push_back(x1);
                if(io < 2){
                    io++;
                    sdf += x2;
                }
            }
            for(int j = 0;j < we.size();j++){
                for(int z = j+1;z < we.size();z++){
                    a[we[j]][we[z]] = sdf;
                    a[we[z]][we[j]] = sdf;
                }
            }
        }
        for(int k = 1;k <= n;k++){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    if(a[i][k] != 0x3f3f3f3f && a[k][j] != 0x3f3f3f3f){
                        a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
                    }
                }
            }
        }
        for(int i = 1;i <= q;i++){
            int e,r;
            cin >> e >> r;
            if(e == r){
                cout << 0 << endl;
                continue;
            }
            long long ert = a[e][r] + b[e] + b[r];
            cout << ert << endl;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    return 0;
}
