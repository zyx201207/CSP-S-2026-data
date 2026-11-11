#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q;
int vis[500005][500005],w[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("sudway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int a[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2){
            vis[a[i-1]][a[i]]=1;
            vis[a[i][a[i-1]]=1;
        }
    }
    long long l,r,ans,mid;
    l=1;
    r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(mid>=k){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
