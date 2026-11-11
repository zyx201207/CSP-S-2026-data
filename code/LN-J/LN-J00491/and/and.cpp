#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans=0;
bool vis[N];
void dfs(int s,int x){
    if(x==m){
        ans=max(ans,s);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        if(x==0) dfs(a[i],x+1);
        else dfs(s&a[i],x+1);
        vis[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1) s=a[i];
        else s&=a[i];
    }
    if(n==m){
        cout<<s;
        return 0;
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}

