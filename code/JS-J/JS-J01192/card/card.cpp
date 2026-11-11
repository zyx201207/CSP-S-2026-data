#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005];
bool vis[300005];
stack<int> s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(!vis[a[j]]){
                s.push(a[j]);
                vis[a[j]] = 1;
            }
            else{
                while(s.empty()){
                    if(s.top() == a[j]){
                        break;
                    }
                    s.pop();
                }
            }
        }
        while(s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
