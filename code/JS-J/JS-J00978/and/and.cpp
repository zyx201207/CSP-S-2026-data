#include<bits/stdc++.h>
using namespace std;
const int N =2e5+5;
int a[N];
int ans;
bool vis[N];
int m,n;
void dfs(int cnt,int k){
    if(k==m){
        ans=max(ans,cnt);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(cnt&a[i],k+1);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    ans=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        ans=ans&a[i];
    }
    if(n==m){
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof vis);
        vis[i]=true;
        dfs(a[i],1);
    }
    cout<<ans<<endl;
    return 0;
}
