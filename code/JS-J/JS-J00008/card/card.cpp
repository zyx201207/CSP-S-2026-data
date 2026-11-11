#include<bits/stdc++.h>
using namespace std;
int n,m,pos=1,cnt[300010],a[500010],g[500010],vis[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                memset(g,0,n);
                pos=1;
                vis[a[j]]=false;
            }else{
                vis[a[j]]=true;
                pos++;
            }
            g[pos]=a[j];
        }
        for(int z=1;z<=n;z++){
            for(int s=1;s<=m;s++){
                if(s==g[z]){
                    cnt[s]++;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
        return 0;
    }
}
