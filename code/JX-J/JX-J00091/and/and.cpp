#include <bits/stdc++.h>
using namespace std;
long long a[200010],vis[200010];
int n,m;long long ans = 0;
void dfs(int idx,long long val){
    if (idx == m+1){
        ans = max(ans,val);
    }
    for(int i = 1;i <= n;i++)
    {
        if (!vis[i]){
            if (idx == 1) val = a[i];
            vis[i] = 1;
            //cout << "choose" << i << ":"<<a[i]<<":" << val << ":" << (a[i]&val) <<"\n";
            dfs(idx+1,a[i]&val);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1,1);
    cout << ans;
}
