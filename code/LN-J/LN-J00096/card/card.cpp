#include<bits/stdc++.h>
using namespace std;
long long vis[500010];
long long a[500010];
long long tb[1000][1000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;++j){
            if(vis[a[j]]==0){
                vis[a[j]]=j;
                tb[i][a[j]]=tb[i-1][a[j]]+1;
            }
            else{
                for(int k=vis[a[j]]+1;k<=j-1;++k){
                    tb[i][a[k]]=tb[i-1][a[k]];
                    vis[a[k]]=0;
                    vis[a[j]]=j;

                }
            }
        }
        for(int j=1;j<=n;++j){
            tb[i+1][a[j]]=tb[i][a[j]];
        }
    }
    for(int i=1;i<=m;++i){
        cout<<tb[n][i]<<" ";
    }
    return 0;
}
