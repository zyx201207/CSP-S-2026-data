#include<bits/stdc++.h>
using namespace std;
int a[200010];
int vis[200010];
int n;
int ans = 0;
void dfs(int k){
    if(k == 0){
        int x;
        int b = 0;
        for(int i = 1;i <= n;i++){
            if(vis[i]){
                if(!b){
                    x = a[i];
                    b= 1;
                }
                else{
                    x &= a[i];
                }
            }
        }
        ans = max(ans,x);
        return;
    }
    else{
        for(int i = 1;i <= n;i++){
            if(!vis[i]){
                vis[i] = 1;
                dfs(k-1);
                vis[i] = 0;
            }
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(k);
    cout << ans;
    return 0;
}
