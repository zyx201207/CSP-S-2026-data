#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,a[5000]={};
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int x,y;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>y;
        }
    }
    for(int i=1;i<=q;i++){
        int xr,yr;
        cin>>xr>>yr;
        cout<<a[xr]+a[yr]+2*y;
    }
    return 0;
}
