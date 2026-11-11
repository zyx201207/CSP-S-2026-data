#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int c,n,m,d,q;
ll w[N];
int a[501][501],t[501][501];
int k[501];
vector<int>g1[N];
vector<vector<int>>g[N];
bool vis[501];
ll ans=99999999;
void dfs(int n1,ll s,int tar){
    for(int i=1;i<=k[n1];i++){
        if(a[n1][i]==tar){
            //cout<<n1<<' '<<tar<<endl;
            ans=min(s+t[n1][tar],ans);

            return;
        }
    }
    for(int i=1;i<=k[n1];i++){
        for(int &x:g1[a[n1][i]]){
            if(x==n1){continue;}
            if(vis[x]!=1){
                vis[x]=1;
                //cout<<a[n1][i]<<' '<<n1<<' '<<x<<endl;

                dfs(x,s+t[n1][a[n1][i]]+t[x][a[n1][i]],tar);
                
                vis[x]=0;
            }
            
        }
    }
    

}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
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
    for(int v=1;v<=m;v++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==v){
                    g1[v].push_back(i);
                    //cout<<i<<' ';
                }
            }
        }
        /*g[v].reserve(n);
        for(int x:g1[v]){
            for(int y:g1[v]){
                if(y==x){
                    continue;
                }
                g[v][x].push_back(y);
            }
        }*/
        //cout<<endl;
    }
    while(q--){
        for(int i=0;i<=n;i++){
            //for(int j=0;j<=m;j++){
                vis[i]=0;
            //}
        }
        int x,y;
        cin>>x>>y;
        int xl[21],ix=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    xl[ix++]=i;
                }
            }
        }
        for(int i=0;i<ix;i++){
            //cout<<t[xl[i]][x]<<endl;
            dfs(xl[i],t[xl[i]][x],y);
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}