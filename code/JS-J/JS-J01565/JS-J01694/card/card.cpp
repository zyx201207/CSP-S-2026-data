#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, j, r;
int a[N], b[N], c[M], ans[M];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        memset(c, 0, sizeof c);
        r = 1;
        for(int j = i;j <= n;j++){
            if(c[a[j]]){
                for(int k = c[a[j]] + 1;k < r;k++){
                    c[b[k]] = 0;
                }
                r = c[a[j]] + 1;
            } else {
                c[a[j]] = r;
                b[j - i + 1] = a[j];
                r++;
            }
        }
        for(int j = 1;j <= m;j++){
            if(c[a[j]]){
                ans[j]++;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
