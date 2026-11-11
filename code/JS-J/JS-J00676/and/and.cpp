#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],vis[200005];
long long res=-1e9;
void dfs(int step,int chose){
    if(step>n){
        if(chose==m){
            long long ans=vis[1];
            for(int i=2;i<=chose;i++){
                ans=ans&vis[i];
            }
            res=max(res,ans);
        }
        return;
    }
    if(n-step+1+chose<m)return;
    vis[chose+1]=a[step];
    dfs(step+1,chose+1);
    vis[chose+1]=0;
    dfs(step+1,chose);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0);
    cout<<res;
    return 0;
}
