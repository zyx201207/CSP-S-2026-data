#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005];
bool c(long long x){
    x--;
    long long ans=0,pre=0;
    for(long long i=1;i<=x;++i){
        ans+=i*b[i];
        pre+=b[i];
    }
    for(long long i=x,j=1;i<n;++i,++j){
        if(ans<=m)return true;
        ans-=pre;
        ans+=x*b[i+1];
        pre-=b[j];
        pre+=b[i+1];
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;++i){
        b[i-1]=a[i]-a[i-1];
    }
    long long l=0,r=n+1;
    while(l+1<r){
        long long mid=(l+r)/2;
        if(c(mid))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}
