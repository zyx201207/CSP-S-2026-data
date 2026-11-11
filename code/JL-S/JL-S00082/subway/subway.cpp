#include <bits/stdc++.h>
using namespace std;
int a[1000005],t[1000005],w[1000005],sum[1000005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q,ki,x,y;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>ki;
        for(int j=1;j<=2*ki;j++){
            cin>>a[j];
            if(j%2==0) sum[i]+=a[j];
        }
    }for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<w[x]+w[y]+sum[i]<<endl;
    }
    return 0;
}
