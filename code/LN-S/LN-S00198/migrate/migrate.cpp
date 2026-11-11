#include<bits/stdc++.h>
using namespace std;
long long n,d,m[1000100],vis[1000010][2],ans;
void dfs(int x,int i,int len=0){
    if(x>=n){
        return;
    }
    vis[x][0]=1;
    vis[x][1]=len;
    for(int j=i+1;j<=n;j++){
        if(vis[m[j]][0]){
            if(vis[m[j]][1]){
                ans++;
            }
            vis[m[j]][1]=min(int(vis[m[j]][1]),len);
        }
        if(m[j]-x<=d){
            dfs(m[j],j,len+j-i);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","W",stdout);
    int x,e;
    cin>>e>>x;
    for(int i=1;i<=x;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>m[j];
        }
        dfs(m[1],1);
        cout<<ans<<endl;
        for(int i=0;i<=n;i++){
            vis[i][1]=0;
            vis[i][0]=0;
        }
    }

    return 0;
}
