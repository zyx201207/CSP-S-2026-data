#include <bits/stdc++.h>
using namespace std;

int a[200022], vis[200022];
vector <int> v[50];

int main(){
    //10:50:36 finish(all tasks correct)
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 0;i <= 30;i++){
        for(int j = 1;j <= n;j++){
            if(a[j] & (1 << i)){
                v[i].push_back(j);
            }
        }
    }
    int ans = 0, t = 0;
    for(int i = 30;i >= 0;i--){
        if(v[i].size() >= m){
            int cnt = 0;
            for(auto x : v[i]){
                if(vis[x] == t) cnt++;
            }
            if(cnt >= m){
                t++;
                ans |= (1 << i);
                for(auto x : v[i]){
                    if(vis[x] == t - 1) vis[x] = t;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
