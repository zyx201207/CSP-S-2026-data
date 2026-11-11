#include<bits/stdc++.h>
#define pll pair<int,int>
const int N=505;
const int M=5e5+10;
const long long inf=1e15;
using namespace std;
int c,n,m,d,q;
int w[M];
vector<pll> e[N];
struct node{
    long long dis,nowid,nowpos;
    bool operator <(const node b) const{
        return dis<b.dis;
    }
};
int find(int pos,int tar){
    //cout<<tar<<endl;
    for(int i=0;i<e[pos].size();i++){
        //cout<<pos<<" "<<e[pos][i].first<<endl;
        if(e[pos][i].first==tar) return i;
    }
    return -1;
}
long long dis[505][20005];
bool done[505][20005];
priority_queue<node> q1;
void dij(int st,int ta){
    while(!q1.empty()) q1.pop();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dis[i][j]=inf;
            done[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int p=find(i,st);
        //cerr<<p<<endl;
        if(p!=-1){
            q1.push({e[i][p].second,i,st});
            dis[i][st]=e[i][p].second;
        }
    }
   // cerr<<"ok";
    //cerr<<q1.size();
    while(!q1.empty()){
        int d=q1.top().dis;
        int xl=q1.top().nowid;
        int sta=q1.top().nowpos;
        //cerr<<xl<<" "<<sta<<endl;
        q1.pop();
        if(done[xl][sta]) continue;
        done[xl][sta]=1;
        int p=find(xl,sta);
        if(p!=e[xl].size()-1){
            if(dis[xl][e[xl][p+1].first]>dis[xl][e[xl][p].first]){
                dis[xl][e[xl][p+1].first]=dis[xl][e[xl][p].first];
                q1.push({dis[xl][e[xl][p+1].first],xl,e[xl][p+1].first});
            }
        }
        if(p!=0){
            if(dis[xl][e[xl][p-1].first]>dis[xl][e[xl][p].first]){
                dis[xl][e[xl][p-1].first]=dis[xl][e[xl][p].first];
                q1.push({dis[xl][e[xl][p-1].first],xl,e[xl][p-1].first});
            }
        }
        for(int i=1;i<=n;i++){
            if(i!=xl){
                int p1=find(i,sta);
                if(p1!=-1){
                    int w=e[xl][p].second+e[i][p1].second;
                    if(dis[i][e[i][p1].first]>dis[xl][e[xl][p].first]+w){
                        dis[i][e[i][p1].first]=dis[xl][e[xl][p].first]+w;
                        q1.push({dis[i][e[i][p1].first],i,sta});
                    }
                }
            }
        }
    }
    long long ans=LONG_LONG_MAX;
    for(int i=1;i<=n;i++){
        if(dis[i][ta]!=inf){
            int p=find(i,ta);
            if(p!=-1) ans=min(ans,dis[i][ta]+e[i][p].second);
        }
    }
    cout<<ans+w[st]+w[ta]<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k=0;
        cin>>k;
        //cout<<k<<endl;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            e[i].push_back(make_pair(a,t));
        }
        //cerr<<e[i].size()<<endl;
    }
    //cerr<<"ok";
    while(q--){
        int u,v;
        cin>>u>>v;
        if(n<=200)
            dij(u,v);
    }
    return 0;
}