#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using PII=pair<int,ll>;
int c,n,m,d,xx;
const int N=505,Q=1e5+10,M=5e5+10;
const long long INF=1e18;
ll w[M];int k[N];
vector<int> a[N];vector<ll> t[N];  
ll dis[N][N];
vector<PII> num[M];
int x,y;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>xx;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i]=vector<int> (k[i]+1);
        t[i]=vector<long long> (k[i]+1);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            num[a[i][j]].push_back({i,t[i][j]});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            dis[i][j]=INF;
            if(i==j) dis[i][j]=0;
        }
    for(int i=1;i<=m;i++){
        for(int j=0;j<num[i].size();j++){
            for(int u=0;u<num[i].size();u++){
                int p=num[i][j].first,q=num[i][u].first;
                dis[p][q]=dis[p][q]=min(dis[p][q],num[i][j].second+num[i][u].second);
               // cout<<p<<" "<<q<<" "<<dis[p][q]<<"\n"; 
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)
    //         cout<<dis[i][j]<<" ";
    //     cout<<"\n";
    // }
    while(xx--){
        cin>>x>>y;
        ll ans=INF;
        for(int i=0;i<num[x].size();i++){
            for(int j=0;j<num[y].size();j++){
                PII p=num[x][i],q=num[y][j];
                //cout<<p.first<<" "<<q.first<<"\n";
                ans=min(ans,w[x]+w[y]+p.second+q.second+dis[p.first][q.first]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}