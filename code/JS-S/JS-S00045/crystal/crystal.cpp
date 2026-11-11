#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=5e5+10;
int a[MAXN],sum[MAXN];
int n,m;

bool check(int x){
    for(int i=x;i<=n;i++){
        // [i-x+1,i]
        int s=a[i]*(x-1)-sum[i-1]+sum[i-x];
        if(s<=m) return 1;
    }
    return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];


    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    }

    cout<<ans<<"\n";
    return 0;
}
