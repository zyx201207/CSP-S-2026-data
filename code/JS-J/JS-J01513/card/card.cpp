#include<bits/stdc++.h>
using namespace std;
int lst[300005],a[500005],l[500005],ans[300005],vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(lst[a[i]]!=0){
            for(int j=lst[a[i]]+1;j<i;j++)
                l[j]=max(l[j],lst[a[i]]);
        }
        lst[a[i]]=i;
    }
    for(int i=n;i>=1;i--){
        if(vis[a[i]]!=-1&&vis[a[i]]>l[i]&&vis[a[i]]<=i){
            ans[a[i]]+=vis[a[i]]-l[i];
            vis[a[i]]=l[i];
            continue;
        }
        else if(vis[a[i]]!=-1&&vis[a[i]]<=i) continue;
        ans[a[i]]+=i-l[i];
        vis[a[i]]=l[i];
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
