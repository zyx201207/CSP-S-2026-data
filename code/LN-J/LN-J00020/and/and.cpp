#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005];
int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cout<<a[n-m+1];
}
