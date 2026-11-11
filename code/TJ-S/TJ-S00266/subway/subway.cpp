#include<bits/stdc++.h>
#define N 1000505
using namespace std;
int c,n,m,d,q;
int dis[N],f[N];
struct Edge{
    int v,w;
};
struct Node{
    int u,dis;
    bool operator> (const Node& a)const {return dis > a.dis;}
};
vector<Edge> E[N];
priority_queue<Node,vector<Node>,greater<Node> > Q;
void dijktra(int u){
    memset(dis,0x3f,(n+m*2+1)*sizeof(int));
    memset(f,0,(n+m*2+1)*sizeof(int));
    Q.push({u,0});
    dis[u]=0;
    while(!Q.empty()){
        int x=Q.top().u;
        Q.pop();
        if(f[x]) continue;
        f[x]=1;
        for(auto i:E[x]){
            int y=i.v,w=i.w;
            if(dis[y]>w+dis[x]){
                dis[y]=w+dis[x];
                Q.push({y,dis[y]});
            }
        }
    }
}
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return a.first.second>b.first.second;
}
bool cmp2(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    int w;
    for(int i=1;i<=m;i++){
        cin>>w;
        E[n+i].emplace_back(Edge{n+m+i,w});
        E[n+m+i].emplace_back(Edge{n+i,w});
    }
    int k,a,t;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            E[i].emplace_back(Edge{n+m+a,t});
            E[n+m+a].emplace_back(Edge{i,t});
        }
    }
    pair<pair<int,int>,int> x[100005];
    for(int i=1;i<=q;i++){
        cin>>x[i].first.second>>x[i].second;
        x[i].first.first=i;
    }
    sort(x+1,x+1+q,cmp);
    pair<int,int> ans[100005];
    dijktra(n+x[1].first.second);
    ans[1].first=x[1].first.first;
    ans[1].second=dis[n+x[1].second];
    for(int i=2;i<=q;i++){
        if(x[i].first.second==x[i-1].first.second){
            ans[i].first=x[i].first.first;
            ans[i].second=dis[n+x[i].second];
        }else{
            dijktra(n+x[i].first.second);
            ans[i].first=x[i].first.first;
            ans[i].second=dis[n+x[i].second];
        }
    }
    sort(ans+1,ans+1+q,cmp2);
    for(int i=1;i<=q;i++){
        cout<<ans[i].second<<endl;
    }
    return 0;
}
