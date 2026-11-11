#include <bits/stdc++.h>
using namespace std;
long long n,a[100000000],m=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            m=max(m,a[i]&a[j]);
        }
    }cout<<m;
    return 0;
}
