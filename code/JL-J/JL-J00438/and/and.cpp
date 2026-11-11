#include<bits/stdc++.h>
using namespace std;

int n,m,ans,a[200005];

void dfs(int step,int start,int tot){
    if(step==m+1){
        ans=max(ans,tot);
        return ;
    }
    for(int i=start+1;i<=n;i++){
        if(step!=1)dfs(step+1,i,tot&a[i]);
        else dfs(step+1,i,a[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        int maxn=0;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        cout<<maxn<<'\n';
    }
    else if(m==2){
        int maxn=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++)maxn=max(maxn,a[i]&a[j]);
        }
        cout<<maxn<<'\n';
    }
    else if(m==n){
        int tot=a[1];
        for(int i=2;i<=n;i++)tot&=a[i];
        cout<<tot<<'\n';
    }
    else{
        dfs(1,0,0);
        cout<<ans<<'\n';
    }
    return 0;
}
