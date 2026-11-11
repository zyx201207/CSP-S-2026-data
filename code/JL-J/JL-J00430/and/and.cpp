#include<bits/stdc++.h>
using namespace std;
int n,m,a[300000],ans=-1;
int main (){
    freopen("and1.in","r",stdin);
    //reopen("and.out","w",stdout);
    cin>>n,m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans=max(ans,a[i] and a[j]);
        }
    }
    cout<<ans;
    return 0;
}
