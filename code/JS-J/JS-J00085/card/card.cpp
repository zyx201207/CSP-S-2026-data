#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int fa[500005];
int ans[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    map<int,int>mp;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(mp[a[i]]==0)mp[a[i]]=i;
        else fa[i]=mp[a[i]];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans[a[j]]++;
            if(fa[j]!=0){
                j=fa[j];
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ' ;
    return 0;
}
