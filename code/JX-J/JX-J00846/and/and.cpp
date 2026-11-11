#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long f[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=m;j>=2;j--){
            f[j]=max(f[j],f[j-1]&a[i]);
        }
        f[1]=max(f[1],a[i]);
    }
    cout<<f[m];
    return 0;
}
