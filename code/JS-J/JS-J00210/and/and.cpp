#include<bits/stdc++.h>
using namespace std;
int ans;
int vis[200005];
int a[200005];
int b[200005];
int n,m;
void dfs(int pos){
    if(pos>m){
        int tmp=b[1];
        for(int i=1;i<=m;i++){
            tmp&=b[i];
        }
        ans=max(ans,tmp);
    }else{
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                vis[i]=1;
                b[pos]=a[i];
                dfs(pos+1);
                vis[i]=0;
                b[pos]=0;
            }
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int last=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        int k=a[1];
        for(int i=1;i<=n;i++){
            k&=a[i];
        }
        cout<<k;
        return 0;
    }
    if(m==1){
        int k=a[1];
        for(int i=1;i<=n;i++){
            k=max(k,a[i]);
        }
        cout<<k;
        return 0;
    }
    if(m==2){
        int k=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                k=max(k,a[i]&a[j]);
            }
        }
        cout<<k;
        return 0;
    }
    dfs(1);
    cout<<ans;
    return 0;
}
