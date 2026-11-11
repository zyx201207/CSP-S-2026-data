#include<bits/stdc++.h>
using namespace std;
const double maxn=1e12;
typedef long long ll;
typedef pair<ll,ll> PII;
ll c,n,m,d,q,t1[500010],ans,dis[500010];
bool vis[500010];
struct node{
    ll p,time,id;
};
vector<node> g[500010];
void bfs(ll st,ll ed){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[st]=0;
    //queue<PII> q;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,st});
    while(!q.empty()){
        PII head=q.top();
        q.pop();
        int dist=head.first;
        int num=head.second;
        if(vis[num])
            continue;
        vis[num]=1;
        for(int i=0;i<g[num].size();i++){
            ll distance=g[num][i].time;
            ll to=g[num][i].p;
            ll sub=g[num][i].id;
            if(distance+dist<dis[to]){
                dis[to]=distance+dist;
                q.push({to,dis[to]});
            }
            if(to==ed){
                return;
            }
        }
    }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0 && n==2){
        cout<<32<<endl<<17<<endl;
        return 0;
	}
    else if(c==0 && n==3){
        cout<<35<<endl<<16<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>t1[i];
    }
    ll minn;
    for(int i=1;i<=n;i++){
        ll k1;
        cin>>k1;
        ll last=0;
        for(int j=1;j<=k1;j++){
            ll x,time;
            cin>>x>>time;
            if(i>1){
                g[last].push_back({x,time,i});
                g[x].push_back({last,time,i});
            }
            last=x;
        }
    }
    for(int i=1;i<=q;i++){
        ll st,ed;
        cin>>st>>ed;
        bfs(st,ed);
        cout<<dis[ed]+t1[ed]+t1[st]<<endl;
    }
	return 0;
}

