#include<bits/stdc++.h>
using namespace std;
const long long maxm=5e5+10,maxn=5e2+10;
long long w[maxn],k[maxn];
struct edge{long long v,w;};
vector<edge>mp[maxn];
struct node{long long x,y;}q[maxn];
long long c,n,m,d,Q,Count;
bool check1(){
    if(n<=200&&Count<=400)return true;
    return false;
}
long long Floyd[610][610];
const long long INF=LLONG_MAX;
void solve1(){
    for(long long i=1;i<=603;i++){
        for(long long j=1;j<=603;j++){
            if(i==j)continue;
            Floyd[i][j]=INF;
            Floyd[j][i]=INF;
        }
    }
    for(long long u=1;u<=n;u++){
        for(edge v:mp[u]){
            Floyd[u+Count+1][v.v]=v.w;
            Floyd[v.v][u+Count+1]=v.w;
        }
    }
    for(long long k=1;k<=603;k++){
        for(long long i=1;i<=603;i++){
            for(long long j=1;j<=603;j++){
                if(Floyd[i][k]==INF||Floyd[k][j]==INF)continue;
                Floyd[i][j]=Floyd[j][i]=
                    min(Floyd[i][j],Floyd[i][k]+Floyd[k][j]);
            }
        }
    }
    for(long long i=1;i<=Q;i++){
        cout<<Floyd[q[i].x][q[i].y]+w[q[i].x]+w[q[i].y]<<'\n';
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>n>>m>>d>>Q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(long long j=1;j<=k[i];j++){
            long long a,t;cin>>a>>t;
            mp[i].push_back((edge){a,t});
        }
    }
    for(long long i=1;i<=Q;i++){
        cin>>q[i].x>>q[i].y;
    }
    for(long long i=1;i<=n;i++)Count+=k[i];
    if(check1())solve1();
    return 0;
}
