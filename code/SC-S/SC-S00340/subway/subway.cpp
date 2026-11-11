#include<bits/stdc++.h>
#include<bits/extc++.h>
#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
const int MAXN=5e2,MAXM=5e5;
int c,n,m,d,q,w[MAXM+11],k[MAXN+11];
long long lg[MAXN+11][MAXN+11];
vector<int>g[MAXM+11],a[MAXN+11],t[MAXN+11];
cc_hash_table<int,cc_hash_table<int,int>>mp;
void main_init(){
    memset(lg,0x3f,sizeof lg);
    for(int i=1;i<=MAXN;i++)
        lg[i][i]=0;
    return;
}
void solve(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].resize(k[i]);
        t[i].resize(k[i]);
        for(int j=0;j<k[i];j++){
            cin>>a[i][j]>>t[i][j];
            mp[a[i][j]][i]=t[i][j];
            g[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<k[i];j++)
            for(int v:g[a[i][j]])
                lg[i][v]=lg[v][i]=min(lg[i][v],(long long)(t[i][j]+mp[a[i][j]][v]));
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                lg[i][j]=lg[j][i]=min(lg[i][j],lg[i][k]+lg[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        long long minn=1e18;
        for(int u:g[x])
            for(int v:g[y])
                minn=min(minn,lg[u][v]+w[x]+w[y]+mp[x][u]+mp[y][v]);
        cout<<minn<<endl;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    main_init();
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}