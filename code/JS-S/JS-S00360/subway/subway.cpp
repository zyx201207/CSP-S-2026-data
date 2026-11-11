#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define w second
const int M=5e5+5,N=505,MAX=1e17;
int c,n,m,d,q,b[M],f[N][N],ans;
vector<pair<int,int> >a[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        f[i][i]=0;
        int k,v,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>v>>t;
            a[v].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=m;i++){
        for(pair<int,int> j:a[i]){
            for(pair<int,int> k:a[i]){
               f[j.x][k.x]=min(f[j.x][k.x],j.w+k.w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        ans=MAX;
        for(pair<int,int> i:a[u]){
            for(pair<int,int> j:a[v]){
                ans=min(ans,f[i.x][j.x]+i.w+j.w);
            }
        }ans+=b[u]+b[v];
        cout<<ans<<"\n";
    }
    return 0;
}
