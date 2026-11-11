#include<bits/stdc++.h>
using namespace std;
//CSP-J AK++


long long n,a[200005],sum,m;
long long b[31]={"2","4","8","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288","1048576","2097152","4194304","8388608","16777216","33554432","67108864","134217728","268435456","536870912","1073741824"}


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }sort(a,a+n-1);
    sum=a[0];
    for(int i=0;i<m;i++){
        sum=a[i]&sum;
    }
    cout<<sum;
    return 0;
}
