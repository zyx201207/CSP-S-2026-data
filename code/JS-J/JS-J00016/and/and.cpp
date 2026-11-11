#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","s",stdin);
    freopen("and.out","r",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n-m];
    return 0;
}
