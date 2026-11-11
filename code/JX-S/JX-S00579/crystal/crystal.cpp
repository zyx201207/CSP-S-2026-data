#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define int long long
int n,m,a[maxn],f[maxn];
int b[maxn],c[maxn],d[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    for(int i=n;i>=1;i--){
        c[i]=c[i+1]+b[i];
        d[i]=d[i+1]+c[i];
    }
    int ans=1;
    for(int i=2;i<=n;i++){
        int l=1,r=i,k;
        while(l<r){
            k=(l+r)/2;
            if(d[i-k+1]-d[i+1]-c[i+1]*k<=m){
                ans=max(ans,k);
                l=k+1;
            }else r=k;
        }
        ans=max(ans,l);
    }
    cout<<ans<<endl;
    return 0;
}
