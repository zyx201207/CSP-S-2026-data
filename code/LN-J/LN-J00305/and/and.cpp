#include<bits/stdc++.h>
#define int long long
#define qrw ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int n,m,a[200005];
signed main(){
    qrw;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int k=29;k>=0;k--){
        int sumb=0;
        for(int i=1;i<=n;i++){
            if(a[i]&(1<<k)) sumb++;
        }
        if(sumb<m) continue;
        ans+=(1<<k);
        for(int i=1;i<=n;i++){
            if(a[i]&(1<<k)) continue;
            a[i]=0;
        }
    }
    cout<<ans<<endl;
}   