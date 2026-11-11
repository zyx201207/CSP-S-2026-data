#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2005];
int box[2005];
bool vis[2005];
int ans;
int sum;
void dfs(int x){
    if(x==m){
        for(int i=0;i<m;i++){
            sum=sum&a[box[i]];
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
            if(!vis[i]){
                box[x]=i;
                vis[i]=1;
                dfs(x+1);
                vis[i]=0;
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
    dfs(0);
    cout<<ans;
    return 0;
}
