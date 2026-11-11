#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y;
int w[50005],a[505][50005],t[505][50005];
long long sum;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
            cin>>k;
        for(int j=1;j<=k;j++)cin>>a[i][k]>>t[i][k];
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        sum+=w[x]+w[y];
        cout<<sum<<endl;
    }
    return 0;
}
