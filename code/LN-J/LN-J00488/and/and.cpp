# include<bits/stdc++.h>
using namespace std;
# define int long long
int n,m,ans;
int a[200005];
void dfs(int x,int cnt,int k){
    if(x>n){
        if(k==m){
            ans = max(ans,cnt);
        }
        return;
    }
    dfs(x+1,cnt&a[x],k+1);
    dfs(x+1,cnt,k);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n<=8) dfs(1,a[1],0);

    else{
        sort(a+1,a+n+1);
        int ans = a[n];
        for(int i=n;i>=n-m+1;i--) ans &= a[i];
    }
    cout << ans;
    return 0;
}
