#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005],a[500005],t[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(long long j=1;j<=k;j++){
            cin>>a[i]>>t[i];
        }
    }
    cin>>q;
    while(q--){
        long long x,y;
        cin>>x>>y;
        cout<<(y-x)*(y-x);
    }
    return 0;
}
