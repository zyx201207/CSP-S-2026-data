#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[N],vis[M],ans[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>b[i];
    if(m==2){
        int ok1=0,ok2=0;
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof vis);
            for(int j=i;j<=n;j++){
                if(b[j]==1){
                    if(vis[1]&&!vis[2])vis[1]=1;
                    if(vis[2]==2)vis[1]=1,vis[2]=0;
                    if(vis[1]==2)vis[1]=2;
                    if(!vis[1]&&vis[2]==1)vis[1]=2;
                    if(!vis[1]&&!vis[2])vis[1]=1;
                    ok1=1;
                }
                if(b[j]==2){
                    if(vis[2]&&!vis[1])vis[2]=1;
                    if(vis[1]==2)vis[2]=1,vis[1]=0;
                    if(vis[2]==2)vis[2]=2;
                    if(!vis[2]&&vis[1]==1)vis[2]=2;
                    if(!vis[2]&&!vis[1])vis[2]=1;
                    ok2=1;
                }
            }
            ans[1]+=!(vis[1]==0),ans[2]+=!(vis[2]==0);
        }
        if(ok1)cout<<ans[1]<<' ';
        if(ok2)cout<<ans[2];
    }else{
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof vis);
            for(int j=i;j<=n;j++)
                if(!vis[b[j]])ans[b[j]]++,vis[b[j]]=1;
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    }
    return 0;
}
