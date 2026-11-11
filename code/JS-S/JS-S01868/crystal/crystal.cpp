#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,r=n;
    while(l<=r){
        bool p=0;
        long long mi=m;
        long long mid=(l+r)/2;
        for(long long i=1;i<=mid;i++){
            mi=mi-(a[mid]-a[i]);
            if(mi<0){
                r=mid-1;
                p=1;
                break;
            }
        }
        if(p)continue;
        l=mid+1;
    }
    cout<<r;
    return 0;
}
