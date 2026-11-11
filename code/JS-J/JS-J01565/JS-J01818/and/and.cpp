#include <bits/stdc++.h>
using namespace std;
int n,m,maxn = -1,sum,a[200005],ans = -1;
void dfs(int k,int cnt,int p){
    if(k > n){
        if(cnt == m) ans = max(ans,p);
        return ;
    }
    dfs(k+1,cnt,p); dfs(k+1,cnt+1,p & a[k]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    sum = a[1];
    for(int i = 1;i <= n;i++) sum &= a[i];
    if(m == 1){
        cout << maxn;
        return 0;
    }else if(m == n){
        cout << sum;
        return 0;
    }
    for(int i = 1;i <= n;i++) dfs(i,0,a[i]);
    cout << ans;
    return 0;
 }
