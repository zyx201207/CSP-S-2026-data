#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,m,n,d,q;
bool vis[30005];
ll dis[30005];
vector<vector<pair<int,int> > > v;
vector<pair<int,int> > v1;
priority_queue<pair<ll,ll> > qu;
pair<ll,ll> mp(ll a,ll b){
    return make_pair(a,b);
}
void djstl(){
    while(!qu.empty()){
        long long f=(qu.top()).first,s=(qu.top()).second;
        qu.pop();
        vis[s]=1;
        for(pair<int,int> i:v[s]){
            long long dsts=f+i.first;
            if(dis[i.second]>dsts&&!vis[i.second]){
                dis[i.second]=dsts;
                qu.push(mp(dis[i.second],i.second));
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=0;i<=n+m+n;i++)v.push_back(v1);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        v[i].push_back(mp(a,m+n+i));
        v[m+n+i].push_back(mp(a,i));

    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>c;
        for(int j=1;j<=c;j++){
            cin>>a>>b;
            v[n+i].push_back(mp(b,a));
            v[a].push_back(mp(b,n+i));
        }
    }
    while(q--){
        int s,e;
        cin>>s>>e;
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[s+n+m]=0;
        qu.push(mp(0,s+n+m));
        djstl();
        cout<<dis[n+m+e]<<endl;
    }
    return 0;
}
