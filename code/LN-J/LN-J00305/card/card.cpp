#include<bits/stdc++.h>
#define int long long
#define qrw ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int n,m,ans[300005],a[500005],lst[300005],f[300005];
signed main(){
    qrw;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--){
        if(!lst[a[i]]) lst[a[i]]=i;
        int p=i;
        while(p<n){
            ans[a[p]]++;
            p=lst[a[p]]+1;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";

}