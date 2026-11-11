#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ma=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m;i++){
        for(int j=i;j<=m;j++){
            ma=max(a[j]&a[j+1],ma);

        }
    }
    cout<<ma;
    return 0;
}
