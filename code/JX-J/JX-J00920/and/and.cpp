#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=0;
    cin>>n>>m;
    long long a[200010],i;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    long long b;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            b=(a[i]&a[j]);
            ans=max(ans,b);
        }
    }
    cout<<ans;
    return 0;
}
