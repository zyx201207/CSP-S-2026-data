#include<bits/stdc++.h>
using namespace std;
long long a[500009];
long long s[500009];
long long b[500009];
long long c[500009];
long long d[500009];
long long m,n;
bool work(int a1,int b1){
    long long f=0;
    f=c[b1]-(b1-a1)*b[b1]+d[b1-a1-1];
    return f<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        s[i]=a[i]-a[i-1];
        b[i]=b[i-1]+s[i];
        c[i]=s[i]*(i-1)+c[i-1];
        d[i]=b[i]+d[i-1];
    }
    long long f=1;
    long long ans=-1;
    while(f<=n){
        long long l=1;
        long long r=f;
        long long mid=(l+r)/2;
        while(l<=r){
            mid=(l+r)/2;
            if(work(mid,f)){
                ans=max(ans,mid);
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        f++;
    }
    cout<<ans;
    return 0;
}
