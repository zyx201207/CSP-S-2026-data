#include <bits/stdc++.h>

using namespace std;
int c,t,n,d;
int a[2000005];
int cnt[2000005];
int dis[2000005];
void dfs(int x,int c){
    for (int i = x+1;i <= n;i++){
        if(abs(a[x] - a[i]) > d)continue;
        if (c + 1 < dis[i]){
            dis[i] = c+1;
            cnt[i] = 1;
            dfs(i,c+1);
        }
        else if (c + 1 == dis[i]){
            cnt[i]++;
            dfs(i,c+1);
        }
    }
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >>c>>t;
    while(t--){
        cin >>n>>d;
        for (int i = 0;i < n;i++){
            cin >>a[i];
        }
        int ans = 0;
        for (int k = 0;k < n;k++){
            memset(cnt,0,sizeof(cnt));
            memset(dis,0x7f,sizeof(dis));
            dfs(k,0);
            for (int i = k+1;i < n;i++){
                if (cnt[i] == 2){
                    ans++;
                }
            }
        }
        cout <<ans<<endl;
    }
    return 0;
}
