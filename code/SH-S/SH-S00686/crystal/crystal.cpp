#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500005],f[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    f[1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i]+=(a[i]-a[j]);
        }
    }
   	for(int i=1;(i<=n&&m>=0);i++){
        m-=f[i];
        ans++;
    }
    cout<<ans;
    return 0;
}
