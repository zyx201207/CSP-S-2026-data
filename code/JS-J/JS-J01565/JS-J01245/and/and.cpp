#include<bits/stdc++.h>
using namespace std;
int a[20005],n,m,b[20005],d[20005],maxans;
void dfs(int s){
    if(s==m+1){
        int ans=a[d[1]];
        for(int i=1;i<=m;i++){
            ans=(ans&a[d[i]]);
        }
        maxans=max(maxans,ans);
        return;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=1;
            d[s]=i;
            dfs(s+1);
            b[i]=0;
            d[s]=0;
        }
    }

}
int main(){

    freopen("and.in","read",stdin);
    freopen("and.out","write",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1);
    cout<<maxans;
    return 0;
}
