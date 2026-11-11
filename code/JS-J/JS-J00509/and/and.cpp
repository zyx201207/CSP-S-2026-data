#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
            cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long x=n-m+1;
    cout<<a[x];
    return 0;
}
