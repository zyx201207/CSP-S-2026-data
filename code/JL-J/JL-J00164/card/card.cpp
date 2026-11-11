#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],ans[N],b[N],vis[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,tot=0;
    bool flag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i],vis[a[i]]++;
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            flag=0;
            break;
        }
    }
    if(flag){
        for(int i=1;i<=m;i++)ans[i]=ans[i-1]+vis[i];
        for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++){
        vector<int>vis(m+1),b(n+1);
        int tot=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                for(int k=vis[a[j]]+1;k<=tot;k++)vis[b[k]]=0;
                tot=vis[a[j]];
            }
            else b[++tot]=a[j],vis[a[j]]=tot;
        }
        for(int j=1;j<=tot;j++)ans[b[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}