#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn=505,maxm=5e5+7;
constexpr int inf=1e17+7;
int c,n,m,d,q;
int T1[maxm];
int K[maxn];
vector<pair<int,int> >S[maxn];
vector<pair<int,int> >att[maxm];
int u,w;
int ans,as;
bool vis[maxn];
int D[maxn][maxn];
int kd[maxn][maxn];
void push(int pos){
    for(int i=1;i<=n;i++)vis[i]=0;
    D[pos][pos]=0;
    for(int i=1;i<=n;i++){
        int min_d=inf;
        int min_id=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                if(D[pos][j]<min_d){
                    min_d=D[pos][j];
                    min_id=j;
                }
            }
        }
        vis[min_id]=1;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                D[pos][j]=min(D[pos][j],D[pos][min_id]+kd[min_id][j]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>T1[i];
    for(int i=1;i<=n;i++){
        cin>>K[i];
        for(int j=1;j<=K[i];j++){
            cin>>u>>w;
            att[u].push_back({i,w});
            S[i].push_back({u,w});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            kd[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        for(auto j:S[i]){
            for(auto k:att[j.first]){
                kd[i][k.first]=min(kd[i][k.first],1ll*j.second+1ll*k.second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            D[i][j]=inf;
        }
        push(i);
    }
    while(q--){
        cin>>u>>w;
        ans=T1[u]+T1[w],as=inf;
        for(auto i:att[u]){
            for(auto j:att[w]){
                as=min(as,D[i.first][j.first]+i.second+j.second);
            }
        }
        cout<<ans+as<<'\n';
    }
}