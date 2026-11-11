#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int N=1e5+1005;
struct Node{
    int num;
    ll t;
}a[510];
int n,m,w[N];
ll dis[11000][11000];
vector<pair<int,ll> >g[N];
void djk(){
    for(int i=1;i<=m;i++){
        priority_queue<PII,vector<PII>,greater<PII> >pq;
        memset(dis[i],0x3f3f3f3f,sizeof(dis[i]));
        dis[i][1]=0;
        pq.push({0,1});
        while(pq.size()){
            auto [d,u]=pq.top();
            pq.pop();
            if(u==m)break;
            if(dis[i][u]>d)continue;
            for(auto [v,p]:g[u]){
                if(dis[i][v]>dis[i][u]+p){
                    dis[v][i]=dis[i][v]=dis[i][u]+p;
                    pq.push({dis[i][v],v});
                }
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //system("diff ");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i].num>>a[i].t;
            g[a[i].num].push_back({i+m,a[i].t});
            g[i+m].push_back({a[i].num,a[i].t});
        }
    }
    djk();
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[y]+w[x]<<endl;
    }
    return 0;
}
//please let me pass;
