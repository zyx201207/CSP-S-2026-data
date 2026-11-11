#include <bits/stdc++.h>;
using namespace std;
int n,m,vis[500010],a[500010],ans[500010],maxn=-1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        vis[a[i]]=i;
    }
    for (int i = 1;i <= n;i++){
        maxn = -1;
        for (int j = i;j <= n;j++){
            if (vis[a[j]]!=j){
                maxn=max(maxn,j);
            }
        }
        for (int j = i;j <= n;j++){
            if (j>maxn){
                ans[a[j]]++;
            }
            else if (vis[a[j]]!=j){
                j=vis[a[j]];
                ans[a[j]]++;
            }
            else{
                ans[a[j]]++;
            }
        }
    }
    for (int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
