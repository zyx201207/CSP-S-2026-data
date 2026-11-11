#include <bits/stdc++.h>
using namespace std;
int t;
int ct;
int l = 1,r = 1;
long long dis[2000010];
long long c[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> ct >> t;
    for (int qt = 1;qt <= t;qt++){
        int n,d;
        long long ans = 0;
        cin >> n >> d;
        dis[l-1] = 0;
        r = r + n - 1;
        for (int i = l;i <= r;i++){
            cin >> dis[i];
            c[i] = dis[i] - dis[i-1];
        }
        int pt = l;
        while (pt + 2 <= n){
            if (c[pt+1] - c[pt] <= d && c[pt+2] - c[pt] <= d){
                ans++;
            }
            pt++;
        }
        l = r + 1;
        r = l;
        cout << ans << endl;
    }
    return 0;
}
