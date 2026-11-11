#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
ll c,n,m,d,q,w[M],f[N][N],x,y,k[N],u,xxx;
vector<ll> a[N],t[N];
struct node{
    int id;
    ll w;
};
vector<node> v[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=3e18;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>u>>xxx;
            // a[i].push_back(u);
            // t[i].push_back(xxx);
            v[u].push_back((node){i,xxx});
        }
    }
    for(int i=1;i<=m;i++){
        for(node j:v[i]){
            for(node k:v[i]){
                if(k.id==j.id)continue;
                f[k.id][j.id]=min(f[k.id][j.id],j.w+k.w);
            }
        }
    }
    for(int i=1;i<=n;i++){
        f[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j||j==k||k==i)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

            }
        }
    }
    while(q--){
        cin>>x>>y;
        ll ans=3e18;
        for(node j:v[x]){
            for(node k:v[y]){
                ans=min(ans,f[j.id][k.id]+j.w+k.w);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}