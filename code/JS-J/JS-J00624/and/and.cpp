#include<bits/stdc++.h>
using namespace std;
int m,n,z=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long a[n+3];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        z&=a[n-i+1];
    }
    cout<<z;
    return 0;
}
