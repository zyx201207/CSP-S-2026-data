#include<bits/stdc++.h>
using namespace std;
long long w[100005],k[1005],a[100005],t[100005],x[100005],y[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,p,ans=0;
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a[i]>>t[i];
                ans+=t[i];
            }
        }
        for(int i=1;i<=p;i++){
            cin>>x[i]>>y[i];


    ans=ans+w[1]+w[m];
    cout<<ans<<endl;
        }
    return 0;
}
