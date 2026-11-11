#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int st;
    int rt;
    int et;
};
vector<node>g[500005],e[500005];
int c,n,m,d,q,sum[500005],k[500005],x,y,z,a[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        g[i].push_back({0,0,0});
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    bool isA=true;
    for(int i=1;i<=n;i++){
        cin>>k[i]>>x;
        if(k[i]>2)isA=false;
        if(k[i]==2){

        }
        for(int j=2;j<=k[i];j++){
            cin>>y>>z;
            //e[x].push_back(y);
            //e[y].push_back(x);
            //x=y;
        }

    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<'\n';
    }
    return 0;
}
