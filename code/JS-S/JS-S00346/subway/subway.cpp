#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e2+10,maxm=2e4+10;
ll c,n,m,d,q,w[maxm],k[maxn],a[maxn][maxm],t[maxn][maxm];
int res[maxn],b[maxn][maxm];
ll dfs(int x,int y,int df){
    if(res[x])return 1000000005;
    res[x]=1;
    if(x==y)return t[df][x];
    ll mi=LONG_LONG_MAX,p;
    for(int i=1;i<=n;i++){
        if(b[i][x]){
            for(int j=1;j<=k[i];j++){
                int g=a[i][j];
                int z=dfs(g,y,i);
                //res[g]=0;
                if(mi>z){
                    mi=z;
                    p=i;
                }
            }
        }
    }
    return mi+t[p][x]+t[df][x];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            b[i][a[i][j]]=1;
        }
    }
    for(int i=1;i<=q;i++){
        memset(res,0,sizeof(res));
        int x,y;
        ll ans=0;
        cin>>x>>y;
        ans+=w[x]+w[y];
        ans+=dfs(x,y,0);
        cout<<ans<<'\n';
    }
    return 0;
}
