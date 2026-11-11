#include <bits/stdc++.h>
using namespace std;
int n1,m,maxn,a[200005],vis[200005];
void dfs(int n,int num,int now){
    if(now>=m){
        maxn=max(maxn,num);
        cout<<maxn<<endl;
        return;
    }
    vis[n]=1;
    for(int i=1;i<=n1;i++){
        if(vis[i]==0){
            dfs(i,num&a[i],now+1);
        }
    }
    vis[n]=0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n1>>m;
    for(int i=1;i<=n1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n1;i++){
        dfs(i,a[i],1);
    }
    cout<<maxn;
    return 0;
}
