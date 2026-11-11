#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int > PI;
typedef pair<ll,pair<int,int> > PLI;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=5e5+5;
int c,n,m,d,q;
int w[N],len,st,ed;
ll ans[N];
map<int,ll> dis[N];
bool vs[N][205];
map<int,int> tim[N];
vector<PI> line[N];
vector<int> dt[N];
struct node{
    ll v;
    int bl,x;
    bool operator >(const node &t)const{
        return v>t.v;
    }
    bool operator <(const node &t)const{
		return v<t.v;
	}
};
struct ques{
    int st,ed,id;
    bool operator <(const ques t)const{
        return st<t.st;
    }
}qs[N];
vector<node> g[N];
int id[N];
void build(){
    for(int i=1;i<=n;++i){
        for(int j=0;j<line[i].size()-1;++j){
            int tx=line[i][j].first,x=line[i][j].second;
            int ty=line[i][j+1].first,y=line[i][j+1].second;
            g[x].push_back({0,i,y});
            g[y].push_back({0,i,x});
        }
       
    }
        
}
priority_queue<PLI,vector<PLI>,greater<PLI> > qu;
void dijkstra(int s){
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j)
            vs[i][j]=0;
        dis[i].clear();
    }
    while(!qu.empty()) qu.pop();
    for(int i:dt[s]) qu.push({dis[s][i]=tim[s][i],{i,s}});
    while(!qu.empty()){
        auto now=qu.top();qu.pop();
        int x=now.second.second,bl=now.second.first;
        if(vs[x][bl]) continue;
        vs[x][bl]=true;
        for(auto tmp:g[x]){
            int y=tmp.x,id=tmp.bl;
            if(id!=bl){
                ll val=tim[x][bl]+tim[x][id];
                if(!dis[y].count(id)||dis[y][id]>dis[x][bl]+val)
                    qu.push({dis[y][id]=dis[x][bl]+val,{id,y}});
            }else if(!dis[y].count(bl)||dis[y][bl]>dis[x][bl]) qu.push({dis[y][bl]=dis[x][bl],{bl,y}});
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    int x,t;
    for(int i=1;i<=n;++i){
        cin>>len;
        for(int j=1;j<=len;++j){
            cin>>x>>t;
            dt[x].push_back(i);
            line[i].push_back({t,x});
            tim[x][i]=t;
        }
    }
    build();
    for(int i=1;i<=q;++i){
        cin>>st>>ed;
        qs[i]={st,ed,i};
    }
    sort(qs+1,qs+q+1);
    for(int i=1;i<=q;++i){
        if(qs[i].st!=qs[i-1].st){
            dijkstra(qs[i].st);
        } 
        int ed=qs[i].ed;
        int p=dt[ed][0];
        ans[qs[i].id]=dis[ed][p]+tim[ed][p];
        for(int j=2;j<dt[ed].size();++j){
            p=dt[ed][j];
            ans[qs[i].id]=min(ans[qs[i].id],dis[qs[i].ed][p]+tim[qs[i].ed][p]);
        }
            
        ans[qs[i].id]+=w[qs[i].st]+w[qs[i].ed];
    }
    for(int i=1;i<=q;++i)
        cout<<ans[i]<<'\n';

    return 0;
}
