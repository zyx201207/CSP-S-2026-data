#include<bits/stdc++.h>
using namespace std;
long long ans=0,cnt=0;
long long n,m,a[200005];
bool vis[200005];
void dfs(long long x,long long bu){
    if(bu==m){cnt=max(cnt,ans);return;}
    for(int i=1;i<=n;i++){
        if(vis[a[i]]==0){
            ans=x&a[i];
            vis[a[i]]=1;
            dfs(a[i],bu+1);
            vis[a[i]]=0;
            ans=x;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxx=0;
    for(int i=1;i<=n;i++){
        vis[a[i]]=1;
        dfs(a[i],1);
        maxx=max(maxx,cnt);
        memset(vis,0,sizeof(vis));
        ans=0;
        cnt=0;
    }
    cout<<maxx;
    return 0;
}
