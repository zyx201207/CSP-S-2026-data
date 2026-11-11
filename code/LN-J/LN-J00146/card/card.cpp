#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
bool vis[100005];
int b[500005];
int c[100005];
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    if(n <= 500){
        for(int i = 1; i <= n; i ++){
            int p = 0;
            memset(vis, false, sizeof(vis));
            memset(b, 0, sizeof(b));
            for(int j = i; j <= n; j ++){
                if(!vis[a[j]]){
                    ++ p;
                    b[p] = a[j];
                    vis[a[j]] = 1;
                }
                else{
                    int pp = p;
                    for(int k = 1; k <= pp; k ++){
                        if(b[k] == a[j]){
                            for(int kk = k+1; kk <= pp; kk ++){
                                vis[b[kk]] = 0;
                                b[kk] = 0;
                                p --;
                            }
                        }
                    }
                }
            }
            for(int d = 1; d <= p; d ++){
                c[b[d]] ++;
            }
        }
        for(int i = 1; i <= m; i ++){
            cout << c[i] << " ";
        }
    }
    else{
        int l = a[1];
        for(int i = 2; i <= n; i ++){
            if(a[i] != l){
                l = a[i];
                cout << i-1 << " ";
            }
        }
        cout << n;
    }
    return 0;
}
