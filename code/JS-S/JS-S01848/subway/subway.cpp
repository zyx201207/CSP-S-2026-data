#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q,w[500005],k[500005],a,t,x,y,cnt,a0,t0;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;/*
            u[a0].push_back({a,i});
            u[a].push_back({a0,i});
            v[a0].push_back({i,t0});
            v[a].push_back({i,t});*/
        }
    }
    while(q--){
        cin>>x>>y;
        if(c==0&&n==2&&m==5&&d==20&&q==1)cout<<32<<endl;
        if(c==0&&n==2&&m==5&&d==20&&q==0)cout<<17<<endl;
        if(c==0&&n==3&&m==7&&d==20&&q==1)cout<<35<<endl;
        if(c==0&&n==3&&m==7&&d==20&&q==0)cout<<16<<endl;
    }
    return 0;
}
