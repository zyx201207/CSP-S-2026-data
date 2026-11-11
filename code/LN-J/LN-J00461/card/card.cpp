#include <bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        map<int,bool> vis;
        for(int j = i;j <= n;j++){
            if(!vis[a[j]]){
                vis[a[j]] = true;
                continue;
            }else{
                for(int k = 1;k < j;k++){
                    vis[a[k]] = false;
                    vis[a[j]] = true;
                }
            }
        }
        for(int j = 1;j <= n;j++){
            if(vis[a[j]]) {
                cnt[a[j]]++;
                vis[a[j]] = false;
            }
        }
    }
    for(int i = 1;i <= 500005;i++){
        if(cnt[i]>0) cout << cnt[i] << ' ';
    }
}
