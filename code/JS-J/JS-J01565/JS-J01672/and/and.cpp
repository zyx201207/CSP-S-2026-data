#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,k;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }sort(a,a+n);
    ans=a[n-1];
    for(long long i=2;i<=m;i++){
        ans=max((ans & a[n-i]),(a[n-i] & a[n-i-1]));
    }
    cout<<ans;
    return 0;
}
