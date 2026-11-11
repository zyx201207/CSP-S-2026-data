#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],d[maxn],ans;
unsigned long long d1[maxn],sum[maxn];
bool check(int x){
    bool f=0;
    for(int i=0;i<=n-x;i++){
        if(sum[i+x]-d[i]<=m)f=1;
    }
    return f;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    d[1]=0,sum[1]=0,d1[1]=a[n]-a[1];
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        d1[i]=d1[i-1]+a[n]-a[i];
        sum[i]=sum[i-1]+d[i]*(i-1);
    }
    if(sum[n]<=m){
        cout<<n;
        return 0;
    }
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
