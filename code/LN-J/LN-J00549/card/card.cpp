#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans[300010];
bool vis[500010];
deque<int> s;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int t = 0;
    while(t < n){
        for(int i = t; i <= n; ++i){
            if(!vis[a[i]]){
                vis[a[i]] = true;
                s.push_back(a[i]);
            }else{
                while(s.back() != a[i]){
                    s.pop_back();
                }
                s.pop_back();
            }
        }
        for(auto i:s){
            ans[i]++;
        }
        t++;
    }
    for(int i = 1; i <= m; ++i){
        cout << ans[i];
    }
    return 0;
}
