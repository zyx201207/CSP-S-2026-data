#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool check(long long h){
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        if(h>=a[i]){
            cnt+=(h-a[i]);
        }
    }
    return (cnt<=m);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long l=-5e5;
    long long r=5e5;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        if(a[i]<=r){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
