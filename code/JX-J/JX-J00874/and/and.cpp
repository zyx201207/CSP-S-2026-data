#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=2e5+10;
int a[N];
int dp[N];
int ans=INT_MIN;
void dfs(int i,int k,int res){
    if(i>n){
        if(k==m){
            ans=max(ans,res);
        }
        return;
    }
    if(k<m){
        dfs(i+1,k+1,(res&a[i]));
    }
    dfs(i+1,k,res);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(i+1,1,a[i]);
    }
    cout<<ans;
    return 0;
}
