#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool vis[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(vis,false,sizeof(vis));
    long long n,m;
    cin>>n>>m;
    long long ans=0,w;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
        if(ans==a[i]){
            w=i;
        }
    }
    vis[w]=true;
    for(int i=2;i<=m;i++){
        long long maxx=0;
        for(int j=1;j<=n;j++){
            if(vis[j]==false){
                maxx=max(maxx,(ans&a[j]));
                if(maxx==(a[j]&ans)){
                    w=j;
                }
            }
        }
        ans=maxx;
        vis[w]=true;
    }
    cout<<ans;
    return 0;
}
