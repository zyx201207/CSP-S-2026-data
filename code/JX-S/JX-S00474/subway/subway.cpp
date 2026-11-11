#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q1,w[N],a[N];
ll tp[N][21];
ll dis[4005][4005],dis2[4005][4005];
ll vis[N];
struct pot{
    ll v,type;
};
struct node{
    ll v,w,type;
    bool operator < (const node &T)const{
        return w<T.w;
    }
    bool operator > (const node &T)const{
        return w>T.w;
    }
};
vector<pot>g[N];
void djstra(ll k){
    priority_queue<node,vector<node>,greater<node> >q;
    q.push({k,0,0});
    dis[k][k]=0;
    while(!q.empty()){
        node f=q.top();
        q.pop();
        ll now=f.v,type=f.type,val=f.w;
        //if(k==1&&now==4)cout<<1111111;
        for(pot _:g[now]){
            ll to=_.v,typ=_.type;
            ll w=tp[now][type]+tp[now][typ];
            if(type==typ){
                w=0;
            }else if(type==0){
                w=tp[now][typ];
            }
            if(val+w<dis[k][to]){
                dis[k][to]=val+w;
            }
            dis2[k][to]=min(dis2[k][to],val+w+tp[to][typ]);
            q.push({to,val+w,typ});
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q1;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    ll k;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j];
            cin>>tp[a[j]][i];
            g[a[j-1]].push_back({a[j],i});
            //g[a[j]].push_back({a[j-1],i});
        }
    }
    memset(dis,0x3f3f3f3f3f3f3f3f,sizeof dis);
    memset(dis2,0x3f3f3f3f3f3f3f3f,sizeof dis2);
    for(int i=1;i<=m;i++){
        djstra(i);
        //memset(vis,0,sizeof vis);
    }
    ll s,t;
    while(q1--){
        cin>>s>>t;
        if(dis2[s][t]==INF){
            cout<<dis2[t][s]+w[s]+w[t]<<'\n';
        }else{
            cout<<dis2[s][t]+w[s]+w[t]<<'\n';
        }
    }
    return 0;
}
