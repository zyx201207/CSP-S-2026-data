#include<bits/stdc++.h>
using namespace std;
int a[500], l[500][500];
int cnt(int x, int y, int val, int now){
    int sum = 0;
    if( x == y ){
        if( now == val ) return 1;
        else return 0;
    }
    for(int i=x+1; i<=y; i++){
        sum += cnt(i, y, val, now+a[i]-a[x]);
    }
    return sum;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    if( c > 6 ) while( t-- ) cout << "0\n";
    while(t--){
        int n, d, ans = 0;
        cin >> n >> d;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if( a[j] - a[i] < d ) l[i][j] = a[j] - a[i];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                for(int k=j+1; k<=n; k++){
                    if( a[k] - a[j] < d && a[j] - a[i] < d ) l[i][k] = min(l[i][k], l[i][j] + l[j][k]);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if( cnt(i, j, l[i][j], 0) == 2 ) ans ++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
