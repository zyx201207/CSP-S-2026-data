//subway
#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define int long long
#define vpb push_back
#define vc vector
#define PII pair<int,int>

using namespace std;

int c;
int n,m,dd,qq;
const int N=2e3+10,inf=1e18;
int ww[N];
vc<PII>e[N];
int d[N][N];
priority_queue<PII,vc<PII>,greater<PII>>q;//small
void dij(int s){
    L(i,1,n+m)d[s][i]=inf;
    d[s][s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second,uw=q.top().first;
        q.pop();
        if(uw!=d[s][u])continue;
        for(PII now:e[u]){
            int v=now.first,w=now.second;
            if(d[s][v]>uw+w){
                d[s][v]=uw+w;
                q.push({d[s][v],v});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //cout<<"fre";
    cin>>c>>n>>m>>dd>>qq;
    L(i,1,m)cin>>ww[i];
    //cout<<"fref";
    L(i,1,n){
        int cnt,u=m+i,v,w;
        cin>>cnt;

        L(j,1,cnt){
            cin>>v>>w;
            e[u].vpb({v,w});
            e[v].vpb({u,w});
        }
    }
    //cout<<"ok";
    L(i,1,m){
        dij(i);

    }
    while(qq--){
        int x,y;
        cin>>x>>y;
        cout<<d[x][y]+ww[x]+ww[y]<<"\n";
    }
    return 0;
}
