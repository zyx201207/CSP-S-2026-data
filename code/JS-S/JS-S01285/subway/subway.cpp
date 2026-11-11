#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int c,n,m,d,q;
int w[N];
ll f[505][505];
vector <pair<int,int> > vec[N];
int main(){
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    int k,a,t;
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            vec[a].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=1e17;
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto t1:vec[i])
            for(auto t2:vec[i]){
                if(t1.first!=t2.first){
                    f[t1.first][t2.first]=min(f[t1.first][t2.first],(ll)t1.second+t2.second);
                    f[t2.first][t1.first]=min(f[t2.first][t1.first],(ll)t1.second+t2.second);
                }
            }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    int u,v;ll ans=1e17;
    while(q--){
        cin>>u>>v;
        ans=1e17;
        for(auto t1:vec[u])
            for(auto t2:vec[v]){
                ans=min(ans,(ll)w[u]+w[v]+t1.second+t2.second+f[t1.first][t2.first]);
            }
        cout<<ans<<'\n';
    }
    return 0;
}