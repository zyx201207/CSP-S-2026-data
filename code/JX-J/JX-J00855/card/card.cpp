#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int dp[100005];
int ans[100005];
void todo(){
    for(int i=1;i<=n;i++){
        cout<<ans[i]<< " ";
    }
    cout<<endl;
}
void dfs(int deep){
    if(deep>n){
        todo();
        return;
    }
    for(int i=1;i<=n;i++){
        if(dp[i]!=1){
            dp[i]=1;
            ans[i]=a[i];
            dfs(deep+1);
            dp[i]=0;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=1;
    dfs(n);
    return 0;
}
