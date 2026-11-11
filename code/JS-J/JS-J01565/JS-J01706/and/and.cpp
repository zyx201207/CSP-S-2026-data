#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
unsigned long long n,m,ans=0,vis[N];
unsigned long long a[N],maxx=0,sum=(1<<30)-1;
void dfs(int cnt,unsigned long long s){
    if(cnt==m){
        ans=max(ans,s);
        // cout<<s<<'\n';
        // for(int i=1;i<=n;i++){
        //     cout<<vis[i]<<' ';
        // }cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            continue;
        }
        vis[i]=1;
        dfs(cnt+1,s&a[i]);
        vis[i]=0;
    }
}
int main(){
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        sum&=a[i];
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    if(m==n){
        cout<<sum;
        return 0;
    }
    fill(vis+1,vis+n+1,0);
    dfs(0,(1<<30)-1);
    cout<<ans;

    return 0;
}