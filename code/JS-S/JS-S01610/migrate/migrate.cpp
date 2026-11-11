#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[10005];
int vis[10005];
int ans,cnt;
int l;
void dfs(int cur,int en,int dep,int T){
    if(cur == en){
        cout << 1 << '\n';
        if(dep < ans)
            ans = dep,cnt = 1;
        else if(dep == ans)
            cnt++;
        return;
    }
    for(int i = 1;i <= n;i++){
        if(vis[i] == T || x[i] - x[cur] > d || i == cur)
            return;
        vis[i] = T;
        dfs(i,en,dep + 1,T);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
            cin >> x[i];
        int sum = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                ans = LONG_LONG_MAX;
                cnt = 0;
                dfs(i,j,1,++l);
                if(cnt == 2){
                    sum++;
                }
            }
        }
        cout << 0 << '\n';
    }
}