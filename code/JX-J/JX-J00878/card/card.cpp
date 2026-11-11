#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]!=0 && a[i-1]!=a[i]) cout<<ans<<' ';
        ++ans;
    }
    cout<<n;
    return 0;
}
