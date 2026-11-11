#include <bits/stdc++.h>
using namespace std;
int a[500003],lst[300003],vis[500003],ans[300003];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) vis[j]=0;
        for(int j=1;j<=m;j++) lst[j]=-1;
        for(int j=i;j<=n;j++){
            if(lst[a[j]]==-1) lst[a[j]]=j;
            else{
                vis[lst[a[j]]]++;
                vis[j]--;
                for(int k=lst[a[j]];k<j;k++) lst[a[k]]=-1;
                lst[a[j]]=j;
            }
        }
        for(int j=i+1;j<=n;j++) vis[j]+=vis[j-1];
        for(int j=i;j<=n;j++)
            if(!vis[j]) ans[a[j]]++;//cout<<a[j]<<' ';
        //cout<<'\n';
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}
