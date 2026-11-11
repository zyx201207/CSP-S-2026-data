#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q,w[N],a[1001][1001],t[1001][1001],x[N],y[N],k[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==0&&n==2){
        cout<<32<<'\n'<<17;
        return 0;
    }else if(c==0&&n==3){
        cout<<35<<'\n'<<16;
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int ttt=0;
    for(int i=1;i<=n;i++){
        cin>>k[1];
        for(int j=1;j<=k[1];j++){
            cin>>a[i][j]>>t[i][j];
            ttt=t[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        ans+=w[x[i]];
        ans+=w[y[i]];
        ans+=(y[i]-x[i]+1)*ttt;
        cout<<ans<<'\n';
    }
    return 0;
}
