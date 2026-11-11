#include<bits/stdc++.h>
#define ll long long

using namespace std;
int n,m,a[500010],vis[500010];
int ans[500010],t[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
        t[a[i]]++;
        for(int j=n;j>i;j--){
            if(!vis[j]&&a[j]==a[i]){
                for(int k=i+1;k<=j;k++){
                    if(!vis[k])t[a[k]]--;
                    vis[k]=1;

                }
            }
        }
       // for(int i=1;i<=m;i++)cout<<t[i]<<' ';
      //  cout<<'\n';
      //  for(int i=1;i<=m;i++)if(t[i])ans[i]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
