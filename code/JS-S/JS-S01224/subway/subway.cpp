/*100min <=52 pts?*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
inline bool chmin(T &a,const T &b){return a>b?a=b,true:false;}
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define a first
#define t second
const int inf=1e18;
int c,n,m,d,q,w[500005]={},t0[500005][501]={};
vector<pii>tt[501];
vector<int>aa[500005]={};
void solve_1to6(){
    int dis[501][501]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)dis[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=0;k<tt[i].size();k++){
                int aa1=tt[i][k].a,tt1=tt[i][k].t;
                for(int l=0;l<tt[j].size();l++){
                    int aa2=tt[j][l].a,tt2=tt[j][l].t;
                    if(aa1==aa2){
                        chmin(dis[i][j],tt1+tt2);
                        dis[j][i]=dis[i][j];
                    }
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                chmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,n1,n2,dis0=inf;
        bool pd=false;
        cin>>x>>y;
        for(int j=0;j<aa[x].size();j++){
            int nn1=aa[x][j];
            for(int k=0;k<aa[y].size();k++){
                int nn2=aa[y][k];
                if(nn1==nn2){
                    pd=true;
                    n1=n2=nn1;
                    break;
                }else{
                    if(chmin(dis0,dis[nn1][nn2])){
                        n1=nn1;n2=nn2;
                    }
                }
            }
            if(pd)break;
        }
        cout<<w[x]+w[y]+t0[x][n1]+t0[y][n2]+dis[n1][n2]<<endl;
    }
}
void solve_7to11(){
    vector<pii>e[1001]={};
    int dis[1001][1001]={};
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i!=j)dis[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        int u=tt[i][0].a,v=tt[i][1].a,w=tt[i][0].t+tt[i][1].t;
        e[u].push_back(mp(v,w));
        e[v].push_back(mp(u,w));
    }
    for(int i=1;i<=m;i++){
        priority_queue<pii,vector<pii>,greater<pii> >q;
        q.push(mp(i,0));
        while(!q.empty()){
            int u=(q.top()).a;
            q.pop();
            for(int j=0;j<e[u].size();j++){
                int v=e[u][j].a,w=e[u][j].t;
                if(chmin(dis[i][v],dis[i][u]+w)){
                    q.push(mp(v,dis[i][v]));
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
}
void solve_12to19(){;}
void solve_20to21(){
    int del=inf;
    for(int i=1;i<=m;i++){
        if(aa[i].size()==2)chmin(del,t0[i][1]+t0[i][2]);
    }
    for(int i=1;i<=q;i++){
        int x,y,ans=inf;
        cin>>x>>y;
        for(int j=0;j<aa[x].szie();j++){
            int nan=aa[x][j];
            for(int k=0;k<aa[y].size();k++){
                int nnn=aa[y][k];
                if(nan==nnn)chmin(ans,t0[x][nan]+t0[y][nnn]);
                else chmin(ans,t0[x][nan]+t0[y][nnn]+del);
            }
        }
        cout<<w[x]+w[y]+ans<<endl;
    }
}
void solve_all(){;}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a1,t1;
            cin>>a1>>t1;
            tt[i].push_back(mp(a1,t1));
            aa[a1].push_back(i);
            t0[a1][i]=t1;
        }
    }
    if(c>=1&&c<=6){
        solve_1to6();
    }else if(c>=7&&c<=11){
        solve_7to11();
    }else if(c>=12&&c<=19){
        solve_1to6();
    }else if(c>=20&&c<=21){
        solve_20to21();
    }else{
        solve_1to6();
    }
    return 0;
}