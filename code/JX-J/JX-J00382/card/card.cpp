#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 3e5 + 5, N = 5e5 + 5;
int n, m, tsa = 1;
int a[N], c[M], l[M], ans[M], mp[M];
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        if(a[i] < a[i-1])
            tsa = 0;
    }
    if(tsa == 1){
        for(int i = 2;i <= n; i++){
            if(a[i] != a[i-1])
                cout << i - 1 << ' ';
        }
        cout << n;
        return 0;
    }
    for(int i = 1;i <= n; i++){
        memset(l, 0, sizeof l);
        memset(mp, 0 ,sizeof mp);
        for(int j = 1;j <= n;j++){
            if(mp[a[j]] == 0){
                mp[a[j]] = i;
                l[a[j]] = 1;
            }
            else{
                for(int k = mp[a[j]];k < j;k++)
                    l[a[k]] = 0;
                mp[a[j]] = j;
                l[a[j]] = 1;
            }
        }
         for(int j = 1;j <= m; j++)
            if(l[j] == 1)
                ans[j]++;
    }
    for(int i = 1;i <= m - 1; i++)
        cout << ans[i] - 1<< ' ';
    cout << ans[m];
    return 0;
}
