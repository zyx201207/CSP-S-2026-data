#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],k[500005],ans[500005];
map<int,int>mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        k[i]=i;
        if(mp[a[i]]==0) mp[a[i]]=i;
        else k[mp[a[i]]]=i,mp[a[i]]=i;
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;){
            if(k[j]==j) ans[a[j]]++,j++;
            else j=k[j];
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}

