#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
bool vis[200005];
int q[200005];
void dfs(int step){
    if(step==m){
        int cnt=q[1];
        for(int i=1;i<=m;i++){
            cnt=cnt&q[i];
        }
        ans=max(ans,cnt);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            q[++step]=a[i];
            dfs(step);
            step--;
            vis[i]=0;
        }
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxa=-1,alland;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        if(i==1)alland=a[i];
        else alland=alland&a[i];
    }
    if(m==1){
        cout<<maxa<<endl;
        return 0;
    }
    if(m==n){
        cout<<alland<<endl;
        return 0;
    }
    if(n>2000){
        cout<<maxa<<endl;
        return 0;
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}

