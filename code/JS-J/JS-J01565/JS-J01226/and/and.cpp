#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,ma=-1;
int a[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if (m==n){
        ans=a[1];
        for (int i=2;i<=n;i++){
            ans=a[i]&ans;
        }
    }
    if (m==1){
        cout<<ma;
    }
    cout<<ans;
    return 0;
}
