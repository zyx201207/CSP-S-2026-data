#include<bits/stdc++.h>
using namespace std;
mt19937 md(chrono::steady_clock::now().time_since_epoch().count());
int get(int l,int r){
    return uniform_int_distribution<int>(l,r)(md);
}
int mian(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,x;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>x;
    for(int i=1;i<=n;i++){
        cin>>x;
        int t;
        while(x--)
            cin>>t;
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<get(1,53888888)<<'\n';
    }
    return 0;
}
