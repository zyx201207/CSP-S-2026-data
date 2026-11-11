#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int a[maxn][maxn];
int num = 0;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= n;i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            num+=a[i][j];
        }
    }
    int ans = num/2;
    cout << num << endl;
    cout << ans << endl;
    return 0;
}
