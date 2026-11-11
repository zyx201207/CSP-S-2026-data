#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6,M = 10;
int c,t,n,k,ans;
bool ch[M + 5],vis[M + 5];
vector<int> G[N + 5];

int dfs2(int x,int fa){
    if(ch[x])
        return 0;
    int mi = 1e16;
    for(auto y : G[x]){
        if(y == fa)
            continue;
        mi = min(dfs2(y,x),mi);
    }
    return mi + 1;
}

void dfs1(int x,int fa){
    vis[x] = true;
    for(auto y : G[x]){
        if(y == fa || ch[y] == false)
            continue;
        dfs1(y,x);
    }
}

bool check(){
    int tot = 0;
    for(int i = 1;i <= n;i++){
        if(ch[i] && vis[i] == false){
            dfs1(i,0);
        }
    }
    if(tot > 2)
        return false;
    else
        return true;
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    for(int i = 1;i <= t;i++){
        ans = 0;
        cin >> n >> k;
        for(int j = 1;j <= n;j++){
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(k == n){
            ans = 0;
        }
        else if(c == 13 || c == 14){
            int m = n / 2;
            if(k == 1)
                ans = m / 2;
            else
                ans = max((m - k) / 4,(int)1) + 2; 
        }
        else if(c <= 3){
            ans = 1e16;
            for(int j = 0;j < (1 << n);j++){
                memset(ch,false,sizeof(ch));
                memset(vis,false,sizeof(vis));
                int num = 0;
                for(int l = 0;l < n;l++){
                    if((j & (1 << l)) != 0){
                        num++;
                        ch[l + 1] = true;
                    }
                }
                if(num != k)
                    continue;
                if(check()){
                    int t = 0;
                    for(int l = 1;l <= n;l++){
                        ans = max(dfs2(l,0),t);
                    }
                    ans = min(ans,t);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}