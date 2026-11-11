#include <bits/stdc++.h>
using namespace std;
int n, m, x[500005] = {}, cnt[500005] = {};
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; ++i){
        cin >> x[i];
    }
    int y[500005];
    for (int i=1; i<=n; ++i){
        y[i] = x[i];
    }
    for (int i=1; i<=n; ++i){
        for (int a=i; a<=n-1; ++a){
            for (int b=a+1; b<=n; ++b){
                if(x[a] == x[b]){
                    for (int j=a; j<b; ++j)x[j] = 0;
                }
            }
        }
        for (int v=i; v<=n; ++v){
            if (x[v] > 0)cnt[x[v]]++;
        }
        for (int k=1; k<=n; ++k){
            x[k] = y[k];
        }
    }
    for (int i=1; i<=m; ++i){
        cout << cnt[i] << " ";
    }

    return 0;
}
