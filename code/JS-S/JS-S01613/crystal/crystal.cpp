#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int n,m,a[N + 5],ans = 1,dis[N + 5];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int last = 1;
    for(int i = 2;i <= n;i++){
        dis[i] = dis[i - 1] + (i - last) * (a[i] - a[i - 1]);
        while(dis[i] > m){
            dis[i] -= (a[i] - a[last]);
            last++;
        }
        ans = max(ans,i - last + 1);
    }
    cout << ans << "\n";
    return 0;
}