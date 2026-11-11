#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+100,maxm=1e18+100;
long long n,m,a[maxn];
bool sh(long long x){
    long long sum=0;
    for(int i=x-1;i>=1;i--){
        sum+=(a[x]-a[i]);
        if(sum>m) return 0;
    }
    return sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n,mid,cnt=0;
    while(l<r){
        mid=(l+r)/2+1;
        if(sh(mid)) l=mid;
        else r=mid-1;
        cnt++;
    }
    cout<<l<<endl;
    return 0;
}
