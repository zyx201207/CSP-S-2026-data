#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,ans,a[N],sm[N];
signed main(){
#ifndef LOC
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);for(int i=1;i<=n;i++)sm[i]=sm[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,w=0;
        while(l<=r){
            int j=(l+r)/2;
            if(a[i]*(i-j+1)-(sm[i]-sm[j-1])<=m)w=j,r=j-1;
            else l=j+1;
        }
        ans=max(ans,i-w+1);
    }
    cout<<ans<<endl;
    return 0;
}