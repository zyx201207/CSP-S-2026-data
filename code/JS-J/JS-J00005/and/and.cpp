#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],vis[30],ans;
void dfs(int x,int sum){
    if(x==m){
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(x+1,sum&a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
        dfs(0,pow(2,21)-1);
        cout<<ans;
    }
    else if(n<=2000){
        if(m==1){
            for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        }
        else if(m==n){
            ans=a[1];
            for(int i=2;i<=n;i++) ans&=a[i];
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }
        cout<<ans;
    }
    else{
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans;
    }
    return 0;
}
