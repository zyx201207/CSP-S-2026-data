#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005],c[500005];
bool f2;
long long ma(){
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        cnt+=i*c[i];
        if(cnt>m){
            return i;
        }
    }
    return n;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long cnt1=a[2]-a[1];
    for(long long i=3;i<=n;i++){
        if(a[i]-a[i-1]!=cnt1){
            f2=true;
            break;
        }
    }
    if(!f2){
        long long cnt=0;
        for(long long i=1;;i++){
            cnt+=i*cnt1;
            if(cnt>m){
                cout<<i;
                return 0;
            }
        }
    }
    for(long long i=2;i<=n;i++){
        b[i-1]=a[i]-a[i-1]+b[i-2];
        c[i-1]=a[i]-a[i-1];
    }
    long long cs=ma();
    for(long long i=2;i<n-cs;i++){
        long long cnt=0;
        for(long long j=i+1;j<=n;i++){
            cnt+=i*c[i];
            if(cnt>m){
                cs=max(cs,i);
            }
        }
    }
    cout<<cs;
    return 0;
}

