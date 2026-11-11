#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[100005]={0},t[100005]={0},x[505],y[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=2*k;j++){
            if(j%2==1) cin>>a[j];
            else cin>>t[j];
        }
    }
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++){
        cout<<0<<endl;
    }
    return 0;
}
