#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], vis[100010];
int M[100010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        int tmp[100010] = {0};
        int k = 0;
        for(int j = i; j <= n; j++){
            for(int s = 1; s <= k; s++){
                if(tmp[s] == a[j]){
                    for(int v = s; v <= k; v ++){
                        tmp[v] = 0;
                    }
                    k = s;
                    break;
                }
            }
            tmp[ ++ k] = a[j];
        }
        for(int j = 1; j <= k; j++){
            M[tmp[j]] ++;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << M[i] << " ";
    }
    return 0;
}
