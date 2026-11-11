#include <bits/stdc++.h>
using namespace std;

long long sum = 0,c,n,m,d,q,x,y;
long long mp[5005][5005],w[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (long long i = 1;i<=m;i++){
        cin>>w[i];
    }
    for (long long i = i;i<=n;i++){
        long long h1,h2,tt1,tt2;
        cin>>h1>>tt1>>h2>>tt2;
        mp[h1][h2] = tt1+tt2;
    }
    for (long long i = 1;i<=q;i++){
        cin>>x>>y;
        cout<<mp[x][y]+w[x]+w[y]<<endl;
    }

    return 0;
}
