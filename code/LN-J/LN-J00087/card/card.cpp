#include<bits/stdc++.h>
using namespace std;
int n,m;int a[500050];
bool vis[500050];
int d[500050];
int ans[500050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
        int k=1;
        for(int j=1;j<=m;j++)vis[j]=0;
    for(int j=i;j<=n;j++){
        if(!vis[a[j]]){
            d[a[j]]=k;
             k++;
             vis[a[j]]=1;
        }else{
for(int l=1;l<=m;l++){
    if(vis[l]==1&&d[l]>d[a[j]]){

        vis[l]=0;
    }
}
        k=d[a[j]]+1;
        }
    }
for(int j=1;j<=m;j++){
    if(vis[j])ans[j]++;
}
}
for(int i=1;i<=m;i++){
    cout<<ans[i]<<' ';
}
return 0;
}
