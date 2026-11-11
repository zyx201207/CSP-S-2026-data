#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5006];
int vis[5006];
int ans[3006];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w".stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        int y=0;
        for(int j=i;j<=n;j++){
            y=0;
            for(int k=i;k<j;k++){
                y+=vis[k];
                if(y==0){
                    if(a[k]==a[j]){
                        vis[k]++;
                        vis[j]--;
                    }
                }
            }
        }
        y=0;
        for(int j=i;j<=n;j++){
            y+=vis[j];
            if(y==0){
                ans[a[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
