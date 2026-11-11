#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<0;
        return 0;
    }
    int ma=0;
    int mb;
    int z;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        if(ma==a[i])mb=i;
    }
    m--;
    z=ma;
    a[mb]=0;
    ma=0;
    while(m){
        for(int i=1;i<=n;i++){
            ma=max(ma,a[i]);
            if(ma==a[i])mb=i;
        }
        m--;
        z=min(z,ma);
        a[mb]=0;
        ma=0;
    }
    cout<<z;
    return 0;
}