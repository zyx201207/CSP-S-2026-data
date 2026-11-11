#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
vector<int> g[N];
int n,k,d[N],f[N][20],flag[N];
vector<int> choose;
void init(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
}
void dfs(int u,int fa,int dep){
    f[u][0]=fa,d[u]=dep;
    for(int i=1;i<20;i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u,dep+1);
    }
}
int lca(int x,int y){
    if(d[x]>d[y]) swap(x,y);
    for(int i=19;i>=0;i--){
        if(d[f[y][i]]>=d[x]) y=f[y][i];
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--){
        if(f[y][i]!=f[x][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
bool check(int x){
    int cnt=k;
    for(int i=0;i<k;i++){
        for(auto v:g[choose[i]]){
            if(v<choose[i]) continue;
            if(flag[v]) cnt--;
        }
    }
    //cout<<cnt<<" ";
    return (cnt<=2);
}
signed main(){
    init();
    //freopen("hub2.in","r",stdin);
  // freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        int res=0,ans=1e18;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n<=20){
            dfs(1,0,1);
            for(int i=1;i<(1<<n);i++){
                for(int j=1;j<=n;j++) flag[j]=0;
                choose.clear();
                for(int j=0;j<n;j++){
                    if(i>>j&1) choose.push_back(j+1),flag[j+1]=1;
                }
                if(choose.size()!=k) continue;
                if(!check(i)) continue;
            //    for(int i=0;i<k;i++) cout<<choose[i]<<" ";
           //     cout<<"\n";
                res=0;
                for(int i=1;i<=n;i++){
                    int tmp=1e18;
                    for(int j=0;j<k;j++){
                        if(i==choose[j]) continue;
                        int LCA=lca(i,choose[j]);
                       // if(choose[0]==3&&choose[1]==8&&choose[2]==9) cout<<i<<" "<<choose[j]<<" "<<d[i]+d[choose[j]]-2*d[LCA]<<"\n";
                        tmp=min(tmp,d[i]+d[choose[j]]-2*d[LCA]);
                    }
                //    if(choose[0]==3&&choose[1]==8&&choose[2]==9) cout<<tmp<<"\n";
                    res=max(res,tmp);
                }
                ans=min(ans,res);
            }
            cout<<ans<<"\n";
        }
        else if(k==2){

        }
    }
    return 0;
}
