#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 3e5 + 5;
int a[maxn], nxt[maxn], mp[maxm];
int cnt[maxm], ans[maxm], vis[maxm];
int n, m;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = n; i >= 1;i--){
        nxt[i] = mp[a[i]];
        if(mp[a[i]] == 0)nxt[i] = i;
        mp[a[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        if(vis[a[i]])continue;
        int p = i;
        ans[a[i]] += cnt[a[i]];
        while(p < n){
            while(p < n && nxt[p] != p)p = nxt[p];
            if(p < n){
                p++;
                ans[a[p]] += cnt[a[i]];
            }
        }
        vis[a[i]] = 1;
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
