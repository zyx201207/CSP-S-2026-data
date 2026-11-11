#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=500005;
int n,m,a[N],p[N];

bool check(int x){
    for(int i=1;i+x-1<=n;i++){
        int sum=p[i+x-1]-p[i-1];
        int need=a[i]*x;
        if(sum+m>=need)return 1;
    }
    return 0;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
    int l=2,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
}
