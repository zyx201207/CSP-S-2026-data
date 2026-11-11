#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m>=0){
        f+=a[2]-a[1];
        m-=f;
        ans++;

    }
    cout<<ans;
    return 0;
}
