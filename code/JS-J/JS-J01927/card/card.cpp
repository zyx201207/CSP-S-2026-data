#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005],ans[500005];
int vis[500005];
stack<int> q;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n>> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int k=1;k<=n;k++){
        fill(vis+1,vis+m+1,0);
        for (int i=k;i<=n;i++){
            if (vis[a[i]]){
                for (int j=1;j<=(q.size()-vis[a[i]]);j++) {
                    vis[q.top()] = 0;
                    q.pop();
                }
            } else {
                q.push(a[i]);
                vis[a[i]] = q.size();
            }
        }
        fill(vis+1,vis+m+1,0);
        while (!q.empty()){
            if (!vis[q.top()]){
                ans[q.top()]++;
                vis[q.top()] = 1;
            }
            q.pop();
        }
    }
    for (int i=1;i<=m;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}