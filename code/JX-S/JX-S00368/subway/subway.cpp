#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,sum;
long long w[500009],a[509],t[509];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>t[i];
    }
    for(int i=1;i<=q;i++){
        int x,y;
        sum=0;
        cin>>x>>y;
        sum+=(w[x]+w[y]);
        for(int j=x;j<=y;j++){
            sum+=t[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
