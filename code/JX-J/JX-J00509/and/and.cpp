#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200001],max_,cnt,ans;
bool vis[200001];
void dfs(int x,int cnt){
    if(x==m-1){
        ans=max(ans,cnt);
        return ;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=true;
            dfs(x+1,cnt&a[i]);
            vis[i]=false;
        }
    return ;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m>>a[1];
    max_=ans=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        max_=max(max_,a[i]);
        ans=(ans&a[i]);
    }
    if(m==1){
        cout<<max_;
        return 0;
    }
    if(m==n){
        cout<<ans;
        return 0;
    }
    if(m==2){
        ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j) ans=max(ans,(a[i]&a[j]));
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        cnt=a[1];
        for(int i=2;i<n;i++)
            cnt=(cnt&a[i]);
        ans=max(ans,cnt);
        for(int i=1;i<n;i++){
            cnt=a[i+1];
            for(int j=1;j<=n;j++)
                if(j!=i&&j!=i+1) cnt=(cnt&a[j]);
            ans=max(ans,cnt);
        }
        cout<<ans;
        return 0;
    }
    ans=0;
    for(int i=1;i<=n;i++){
        vis[i]=true;
        dfs(0,a[i]);
        vis[i]=false;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
