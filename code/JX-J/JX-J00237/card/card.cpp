#include<bits/stdc++.h>
using namespace std;
int a[600005];
int vis[400005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        int d[m + 1] = {0};
        int k = i;
        while(a[k] != a[n]){
            vis[a[k]]++;
            k++;
            if(d[a[k]]){
                for(int j = 1; j <= m; j++){
                    if(d[a[j]] > d[a[k]]){
                        vis[a[j]]--;
                        d[a[j]] = 0;
                    }
                }
            }
            vis[a[k]]--;
            d[a[k]] = k;
        }
    }
    vis[a[n]] = n;
    for(int i = 1; i <= m; i++){
        cout << vis[i] << " ";
    }
    return 0;
}
