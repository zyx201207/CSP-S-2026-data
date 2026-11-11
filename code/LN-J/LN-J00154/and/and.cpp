#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool vis[200005];
void dfs(int x,int used,int sum){
    if(used==0){
        ans=max(ans,sum);
        return;
    }
    if(vis[x]) return;
    vis[x]=1;
    for(int i=1;i<=n;i++)
        dfs(i,used-1,sum&a[i]);
    vis[x]=0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(n<=20){
        for(int i=1;i<=n;i++)
            dfs(i,m,a[i]);
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i]!=a[j])
                    ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    ans=a[n];
    for(int i=n-1;i>=n-m+1;i--)
        ans=ans&a[i];
    cout<<ans;
    return 0;
}
