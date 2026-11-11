#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5000 + 10;
int n,m,a[N],ans[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int len = 0;
        int g[N] = {0};
        for(int j = i;j <= n;j++){
            g[++len] = a[j];
            for(int k = 1;k < len;k++){
                if(g[len] == g[k]){
                    for(int l = k + 1;l <= len;l++){
                        g[l] = 0;
                    }
                    break;
                }
            }
        }
        for(int j = 1;j <= m;j++){
            for(int k = 1;k <= len;k++){
                if(g[k] == j){
                    ans[j]++;
                }
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
