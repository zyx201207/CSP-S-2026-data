#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fir first
#define sec second
#define pii pair<int,int>
#define u_mp unordered_map
#define u_st unordered_set
#define prio_q priority_queue

const int N=1000,M=5e5+5;
int c,n,m,d,q,idx=-1;
int w[M],ids[M];
ll dis[N][N];
vector<vector<pii>>pt;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        ids[i]=-1;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            //rd[i].push_back({a,t});
            if(ids[a]==-1){
                idx++;
                ids[a]=idx;
                vector<pii>nv;
                nv.push_back({i,t});
                pt.push_back(nv);
            }
            pt[ids[a]].push_back({i,t});
        }
        
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dis[i][j]=0x3f3f3f3f3f3f3f3f;
            dis[j][i]=0x3f3f3f3f3f3f3f3f;
        }
        dis[i][i]=0;
    }
    for(auto i:pt){
        for(int j=0;j<i.size();j++){
            pii u=i[j];
            for(int k=j+1;k<i.size();k++){
                pii v=i[k];
                dis[u.fir][v.fir]=dis[v.fir][u.fir]=min(dis[u.fir][v.fir],u.sec+v.sec);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(auto x:pt[ids[u]]){
            for(auto y:pt[ids[v]]){
                ll sum=w[u]+w[v]+x.sec+y.sec+dis[x.fir][y.fir];
                ans=min(ans,sum);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}