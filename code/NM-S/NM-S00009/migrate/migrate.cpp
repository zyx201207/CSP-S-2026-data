#include <bits/stdc++.h>
using namespace std;
int c, t, n;
int lu[2000010];
long long d, ans, pan;
long long a[2000010];
int zhj(long x, long y){
    if(x < 0){
       return (-y) - (-x);
    }else{
        return x - y;
    }
}
void dfs(int x, int y, int z){
    if(x == y){
        if(z < pan){
            pan = z;
            lu[y] = 1;
        }else if(z == pan){
            lu[y]++;
        }
        return;
    }
    int ji = x+1;
    while(zhj(a[ji], a[x]) <= d and ji <= y){
        dfs(ji, y, z+1);
        ji++;
    }
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        pan = 2000010;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j < i-1;j++){
                //ans = 0;
                memset(lu, 0, sizeof(lu));
                pan = 2000010;
                dfs(j, i, 0);
                for(int x = 1;x <= n;x++){
                    if(lu[x] == 2){
                        ans++;
                    }
                }
            }
        }
        cout  << ans << endl;
    }
    return 0;
}
