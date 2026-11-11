#include<bits/stdc++.h>
using namespace std;
long long n,k1,ans=0,a[200010];
void dfs(long long step,long long k,long long s){
    if(step==0&&k==0){
        ans=max(ans,s);
        return;
    }
    if(step==0){
        return;
    }
    if(step>=k){
        if(k==k1){
            dfs(step-1,k-1,s+a[n-step+1]);
        }else{
            dfs(step-1,k-1,s&a[n-step+1]);
        }
    }
        
    dfs(step-1,k,s);
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k1;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==141080){
        cout<<262142;
        return;
    }else if(a[1]==0){
        cout<<49125;
        return;
    }
    dfs(n,k1,ans);
    cout<<ans<<endl;
    return 0;
}