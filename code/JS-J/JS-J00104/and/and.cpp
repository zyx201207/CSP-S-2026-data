#include<bits/stdc++.h>
using namespace std;
int m;
int n;
long long a[200010];
long long ans;
void dfs(int now,int k,long long sum){
    if(k==m){
        ans=max(ans,sum);
        return;
    }
    if(n-now+1<m-k||now>n){
        return;
    }
    dfs(now+1,k,sum);
    if(k==0){
        dfs(now+1,k+1,a[now]);
    }
    else{
        dfs(now+1,k+1,(sum&a[now]));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
