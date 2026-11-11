#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[500010],ans[300010],v[500010];
bool vis[300010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        t=0;
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                v[++t]=a[j];
                vis[a[j]]=1;
            }
            else{
                for(int k=1;k<=t;k++){
                    if(v[k]==a[j]){
                        int now=k;
                        //for(int z=now;z<=t;z++)v[z]=0;
                        t=now;
                        vis[a[j]]=1;
                        break;
                    }
                }
            }
        }
        for(int j=1;j<=t;j++){
            if(v[j]!=0)ans[v[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
