#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],ans,vis[N];
void dfs(int u,int step){
    if(step>m){
        int sum,ok=0;
        for(int i=1;i<=n;i++){
            if(vis[i]&&!ok)sum=a[i],ok=1;
            if(vis[i])sum=sum&a[i];
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=u;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,step+1);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    int sum=a[1];
    if(m==n){
        for(int i=2;i<=n;i++)sum=sum&a[i];
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            int sum;
            for(int j=1;j<=n;j++){
                if(sum==0&&i!=j)sum=a[j];
                if(i!=j)sum=sum&a[j];
            }
            ans=max(ans,sum);
        }
        cout<<ans;
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
