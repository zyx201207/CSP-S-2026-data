#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,k,n) for (int i=(k);i<=(n);i++)
#define R(i,k,n) for (int i=(k);i>=(n);i--)
#define pu push_back
#define mpr make_pair
#define lowb(x) (x&(-x))
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
const int N=2e3+10;
const int M=11;
const int inf=1e18;
int dp[N][N];
int c,t,a,b,n,k,td;
int dep[N];
int fa[N][M];
int id[N][N];
int U[N],V[N];
int tmp[N];
vector<int>T[N];
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    fa[u][0]=p;
    F(i,1,10) fa[u][i]=fa[fa[u][i-1]][i-1];
    F(i,0,(int)T[u].size()-1) if (T[u][i]!=p) dfs(T[u][i],u);
}
int LCA(int x,int y){
    if (x==y) return x;
    if (dep[x]<dep[y]) swap(x,y);
    int delta=dep[x]-dep[y];
    R(i,10,0){
        if (delta>=(1<<i)) x=fa[x][i],delta-=(1<<i);
    }
    if (x==y) return x;
    R(i,10,0) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void DP(int u){
    // cerr<<u<<'\n';
    if (dp[u][0]!=inf) return;
    // F(i,0,k) tmp[i]=inf;
    F(i,0,k) dp[u][i]=0;
    F(i,0,(int)T[U[u]].size()-1){
        if (T[U[u]][i]==V[u]) continue;
        F(j,0,k) tmp[j]=dp[u][j],dp[u][j]=inf;
        int v=id[T[U[u]][i]][U[u]];
        // cerr<<U[u]<<' '<<T[U[u]][i]<<' '<<u<<' '<<v<<'\n';
        DP(v);
        F(j,0,k){
            F(p,0,k){
                if (j+p>k) continue;
                if (!j && p) continue;
                dp[u][j+p]=min(dp[u][j+p],max(tmp[j],dp[v][p]+((!p)?1:0)));
            }
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while (t--){
        cin>>n>>k;
        if (n>100){
            F(i,1,n-1) cin>>a>>b;
            if (k==1){
                int m=(n+1)/2;
                cout<<(m+1)/2<<'\n';
            }
            else{
                int m=(n+1)/2;
                m-=(k-2);
                cout<<(m+3)/4<<'\n';
            }
            continue;
        }
        td=0;
        F(i,0,2*n) F(j,0,n) dp[i][j]=inf;
        F(i,1,n) T[i].clear();
        F(i,1,n-1){
            cin>>a>>b,T[a].pu(b),T[b].pu(a);
            td++,U[td]=a,V[td]=b,id[a][b]=td,td++,U[td]=b,V[td]=a,id[b][a]=td;
        } 
        dfs(1,0);
        F(i,1,td) DP(i);
        int f=inf;
        // F(i,1,td){
        //     F(j,0,k) cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        // F(i,1,n){
        //     F(j,1,n) cout<<dis(i,j)<<' ';
        //     cout<<'\n';
        // }
        F(i,1,td){
            F(j,1,td){
                if (dis(V[i],V[j])+2==dis(U[i],U[j])){
                    // cout<<V[i]<<" "<<U[i]<<' '<<V[j]<<' '<<U[j]<<'\n';
                    // cout<<"AAA\n";
                    int ans=inf;
                    F(p,1,k-1){
                        ans=min(ans,max(dp[i][p],dp[j][k-p]));
                    }
                    F(p,1,n){
                        if (dis(p,V[j])+1==dis(p,U[j]) && dis(p,V[i])+1==dis(p,U[i])){
                            ans=max(ans,min(dis(p,U[j]),dis(p,U[i])));
                        }
                    }
                    // cout<<i<<' '<<j<<' '<<ans<<'\n';
                    f=min(f,ans);
                }
            }
        }
        F(i,1,td){
            int ans=dp[i][k];
            F(p,1,n){
                if (dis(p,V[i])+1==dis(p,U[i])) ans=max(ans,dis(p,U[i]));
            }
            f=min(f,ans);
        }
        cout<<f<<'\n';
    }
    return 0;
}
/*
5 5
1 2 4 8 9
*/