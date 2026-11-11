#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long dp[2][200005],a[200005],ans;
bool b=1;
void dfs(long long s,long long t,long long q){
    if(t==m){
        ans=max(ans,s);
        return ;
    }
    if(q>n&&t<m){
        return ;
    }
    for(long long i=q;i<=n-m+1+t;i++){
        dfs((s&a[i]),t+1,i+1);
    }
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n-m+1;i++){
        dfs(a[i],1,i+1);
    }
    cout<<ans;
    return 0;
}
