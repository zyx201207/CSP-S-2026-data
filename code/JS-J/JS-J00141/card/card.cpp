#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[300010];
int a[500010], ans[300010];
stack <int> s;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int k = 1; k <= m; k++){
            vis[k] = 0;
        }
        while(!s.empty()){
            s.pop();
        }
        for (int j = i; j <= n; j++){
            if(vis[a[j]]){
                while(s.top() != a[j]){
                    vis[s.top()] = 0;
                    s.pop();
                }
            } else {
                s.push(a[j]);
                vis[a[j]] = 1;
            }
        }
        for (int j = 1; j <= m; j++){
            if(vis[j]){
                ans[j]++;
            }
        }
    }
    for (int i = 1; i <= m; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
