#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long da = 0;
int n;
void dfs(int x, int m, long long d){
    if(m == 0)da = max(da, d);
    if(x==0){
        for(int i = 1;i<=n-m;i++){
            dfs(i, m-1, a[i]);
        }
    }else{
        for(int i = x+1;i<=n-m;i++){
            dfs(i, m-1, d & a[i]);
        }
    }
    
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m; cin>>n>>m;
    long long ans = 0, ans1;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        ans = max(ans, a[i]);
        if(i==1)ans1 = a[i];
        ans1 &= a[i];
    }
    long long maxn = 0;
    if(m == 1)cout<<ans;
    else if(m == n)cout<<ans1;
    else if(m == 2){
        for(int i = 1;i<n;i++){
            for(int j = i+1;j<=n;j++){
                maxn = max(maxn, a[i]&a[j]);
            }
        }
        cout<<maxn;
    }else{
        dfs(0, m, 0);
        cout<<da;
    }
    return 0;
}
