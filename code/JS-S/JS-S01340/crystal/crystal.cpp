#include <bits/stdc++.h>
using namespace std;
#define int long long
int qzh[500005],a[500005],ans,l=1,r=1;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    while(l<=r and r<=n){
        ans=max(ans,r-l+1);
        if(a[r]*(r-l+1)-(qzh[r]-qzh[l-1])<=m){
            r++;
        }
        if(a[r]*(r-l+1)-(qzh[r]-qzh[l-1])>m){
            l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
