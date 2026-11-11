#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
int n,d,ans=0;
struct st{
    int v,l;
};
int x[N],lm[N],lc[N];
bool vis[N],vv[N];
vector<int> g[N];
void dfs(int u,int l){
    //cout<<u<<"\n";
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vv[u]) return;
        vv[u]=1;
        if(lm[v]>l+1){
            lc[v]=1;
            lm[v]=l+1;
        }else if(lm[v]==l+1){
            lc[v]++;
        }else{
            return;
        }
        //cout<<v<<" "<<lc[v]<<" "<<lm[v]<<"\n";
        dfs(v,l+1);
        vv[u]=0;
    }
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        vis[i]=0;
        lm[i]=1e9;
        lc[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=i;x[j]-x[i]<=d&&j<=n;j++){
            if(i==j) continue;
            g[i].push_back(j);
            g[j].push_back(i);
         //   cout<<i<<" "<<j<<"\n";
        }
    }
    for(int i=1;i<n;i++){
        vv[i]=1;
        dfs(i,0);
        for(int j=1;j<=n;j++){
            //cout<<lc[j]<<" ";
            if(lc[j]==2) ans++;
            lc[j]=1;
            lm[j]=1e9;
            vv[j]=0;
        }
        //cout<<"\n";
        cout<<ans<<"\n";
    }
    //cout<<"############\n";
    //cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) solve();

    return 0;
}
