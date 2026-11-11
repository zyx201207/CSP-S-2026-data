#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c,m,d,q,w[150005];
int a[505][500005],t[505][500005];
vector<ll> v[505];
vector<ll> sr[500005];
ll dep[505],F[505][10],k=10;
void dfs(ll x,ll fa){
    F[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int i=1;i<=k;i++) F[x][i]=F[F[x][i-1]][i-1];
    for(auto i:v[x]){
        if(i==fa) continue;
        dfs(i,x);
    }
}
ll find(ll x,ll y){
    if(dep[x]<dep[y]) swap(x,y);
    ll df=dep[x]-dep[y];
    for(int i=k;i>=0;i--){
        if(df>=(1<<i)){
            x=F[x][i];
            df-=(1<<i);
        }
    }
    if(x==y) return x;
    for(int i=k;i>=0;i--){
        if(F[x][i]!=F[y][i]){
            x=F[x][i];
            y=F[y][i];
        }
    }
    return F[x][0];
}
void slv1(){
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(int j=1;j<=2*k;j++){
            cin>>a[i][(j+1)/2]>>t[i][j/2];
            sr[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        for(ll j=0;j<sr[i].size();j++){
            for(int k=j+1;k<sr[i].size();k++){
                v[j].push_back(k);
                v[k].push_back(j);
            }
        }
    }
    dfs(1,0);
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(auto i:sr[x]){
            for(auto j:sr[y]){
                ans=min(ans,(dep[x]+dep[y]-2*dep[find(x,y)]-1)*t[1][1]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return ;
}
void slv2(){

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    if(c>=12&&c<=19){
        slv1();
    }
    if(c>=7&&c<=11) slv2();
    return 0;
}
