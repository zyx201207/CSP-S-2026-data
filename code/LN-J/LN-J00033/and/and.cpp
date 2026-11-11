#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans = 0,sum;
bool vis[200005];
void dfs(long long u){
    if (u == m+1){
        ans = max(ans,sum);
        return;
    }
    if (u == 1){
        for (int i = 1;i <= n;i++){
            sum = a[i];
            vis[i] = true;
            dfs(2);
            vis[i] = false;
        }
    }
    if (u > 1){
        for (int i = 1;i <= n;i++)
        if (!vis[i]){
            vis[i] = true;
            long long x = sum;
            sum &= a[i];
            dfs(u+1);
            vis[i] = false;
            sum = x;
        }
    }
    return;
}
int main(){
    freopen("and,in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    if (m == 1)
        for (int i = 1;i <= n;i++)
            ans = max(ans,a[i]);
    else if (m == 2)
        for (int i = 1;i <= n;i++)
            for (int j = i+1;j <= n;j++)
                ans = max(ans,a[i]&a[j]);
    else if (m == n-1){
        long long cnt;
        for (int i = 1;i <= n;i++){
            if (i != 1)
                cnt = a[1];
            else
                cnt = a[2];
            for (int j = 2;j <= n;j++)
                if (j != i&&(j != 2&&i == 1))
                    cnt &= a[j];
            ans = max(ans,cnt);
        }
    }
    else if (m == n){
        ans = a[1];
        for (int i = 2;i <= n;i++)
            ans &= a[i];
    }
    else
        dfs(1);
    cout << ans;
    return 0;
}
