#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,a[N],k,ans = 0,vis[2010][2010];

void dfs(int id,int cnt,int x){
    if(x == k){
        cout << id << ' ' << cnt << "\n";
        ans = max(ans,cnt);
        return;
    }
    if(id > n)return;
    vis[id][x] = cnt;
    dfs(id + 1,cnt == -1?a[id]:(cnt & a[id]),x + 1);
    dfs(id + 1,cnt,x);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(vis,-1,sizeof(vis));
    cin >> n >> k;
    for(int i = 1;i <= n;i++)cin >> a[i];
    dfs(1,-1,0);
    cout << ans << "\n";
    return 0;
}