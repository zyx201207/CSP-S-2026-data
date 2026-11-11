#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=5e3+100;
ll c, t, n, d, pos[MAXN];

int dfs(int start, int lst, int depth){
    // printf("%d %d %d\n", start, lst ,depth);
    if (start==lst) return 1;
    if (depth==0) return 0;
    // if (start==n) return;
    int idx=start;
    int ans=0;
    while (pos[idx]-pos[start]<=d && idx<=n){
        // if (rmd[idx][depth-1]==-1)rmd[idx][depth-1]=dfs(idx, depth-1);
        ans+=dfs(idx, lst, depth-1);
        if (ans>2) break;
        idx++;
    }
    return ans;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        memset(pos, 0, sizeof(pos));
        for (int i=1;i<=n;i++){
            cin>>pos[i];
        }
        int ans=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                for (int mind=1;mind<=n;mind++){
                    if (dfs(i, j, mind)==2){
                        ans++; break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
