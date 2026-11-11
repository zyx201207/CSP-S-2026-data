#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200100],sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    sum=a[n-1];
    for(int i=n-2;i>=n-m;i--){
        sum&=a[i];
    }
    cout<<sum;
    return 0;
}
