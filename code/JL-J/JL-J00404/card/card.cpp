#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int a[n+1];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int c[m+1];
    memset(c,0,sizeof(c));
    for(int i = 1;i <= n;i++){
        int b[n+1];
        int u = 0;
        memset(b,0,sizeof(b));
        for(int j = i;j <= n;j++){
            bool v = 0;
            for(int z = 1;z <= u;z++){
                if(b[z] == a[j]){
                    v = 1;
                }
                if(v == 1){
                    b[z] = 0;
                    u--;
                }
            }
            u++;
            b[u] = a[j];
        }
        for(int j = 1;j <= u;j++){
            c[b[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << c[i] << " ";
    }
    return 0;
}
