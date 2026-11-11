#include<bits/stdc++.h>
using namespace std;
long long a[20001000];
long long ans=-1;
int n,m;
void dfs(int step,long long tot,int i){
    if(i==n+1){
        if(step==m+1){
            if(tot>=ans)ans=tot;
            return ;
        }
        return ;
    }
    cout<<0;
    dfs(step,tot,i+1);
    tot&=a[i];
    dfs(step+1,tot,i+1);
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,-1,1);
    cout<<ans;
    return 0;
}
