#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+8;

int n,m,a[N];
int k = pow(2,21)-1;
int ans;

void dfs(int step,int sum,int cnt){
    if(cnt > m) return;
    if(step > n){
        if(cnt == m)
            ans = max(ans,sum);
        return;
    }
    dfs(step+1,sum,cnt);
    dfs(step+1,sum&a[step],cnt+1);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1,k,0);
    cout << ans;
}
