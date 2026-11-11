#include<bits/stdc++.h>
using namespace std;
long long n,m,now;
long long arr[500002],ans[500002],vis[300002],xian[300002];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        memset(xian,0,sizeof(xian));
        now=1;
        for(int j=i;j<=n;j++){
            if(vis[arr[j]]!=0&&vis[arr[j]]<=now){
                now=vis[arr[j]];
            }
            vis[arr[j]]=now;
            now++;
            xian[now]=arr[j];
        }
        for(int j=1;j<=now;j++){
            ans[xian[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    //gou shi dai ma
    //gei wo shang mi huo xin wei da shang
    return 0;
}
