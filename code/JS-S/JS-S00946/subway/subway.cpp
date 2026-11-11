#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=509,M=1e5+9;
const ll INF=1e12+9;
ll c,n,m,d,q;
ll k[maxn];
vector<ll>a[maxn],t[maxn];
ll ans[M],km;
ll w[maxn];
bool book[maxn];
ll p;
bool check(int l,int g){
    for(int i=1;i<=k[l];i++){
        if(a[l][i]==g) return true;
    }
    return false;
}
void dfs(int l,int g,ll e){
    if(ll(g)==e){
        ans[p-q]=min(ans[p-q],km);
        return;
    }
    for(int j=1;j<=k[l];j++){
        if(a[l][j]==g||book[a[l][j]]) continue;
        for(int i=1;i<=n;i++){
            if(i!=l&&check(i,a[l][j])&&!book[a[l][j]]){
                km+= t[l][a[l][j]]+t[i][a[l][j]];
                book[a[l][j]]=1;
                dfs(i,a[l][j],e);
                km-= t[l][a[l][j]]+t[i][a[l][j]];
                book[a[l][j]]=0;
            }
        }
    }
}
void solve(int l,int g,ll e){
    km+=t[l][g];
    dfs(l,g,e);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        ans[i]=INF;
    }
    p=q;
    while(q--){
        ll x,y;
        cin>>x>>y;
        book[x]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    km=w[x]+w[y];
                    solve(i,j,y);
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
