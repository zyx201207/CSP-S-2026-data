#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[500005],ans[500005],c[500005];
bool vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(v[a[j]]==0||vis[v[a[j]]]==1)v[a[j]]=j;
            else{
                for(int k=v[a[j]];k<j;k++)vis[k]=1;
                v[a[j]]=j;
            }
        }
        memset(c,0,sizeof(c));
        for(int j=i;j<=n;j++){
            if(!vis[j])c[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(c[j]==1)ans[j]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
