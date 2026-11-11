#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n-1;j++){
            long long ma=max(a[j],a[j+1]);
            long long mb=min(a[j],a[j+1]);
            a[j]=ma;
            a[j+1]=mb;
        }
    }
    //
    long long f=a[0]&a[1];
    for(int i=2;m>2;i++){
        f=f&a[i];
        m--;
    }
    cout<<f;
    return 0;
}
