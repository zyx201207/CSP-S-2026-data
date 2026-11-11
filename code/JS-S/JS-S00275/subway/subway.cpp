#include<bits/stdc++.h>
using namespace std;
struct str{
    int type;
    int nf,nb;
    int to;
};
struct node{
    int id,la;
};
vector <str> g[501];
int n,c,d,m,k,q;
int t[500001],dis[500001];
void dij(int s,int e){
    priority_queue <node,vector<int>,greater<int> > q;
    q.push_back({s,0});
    int last=0;
    while(!q.empty()){
        int now=q.front().id;
        int last=q.front().last;
        q.pop();
        for(auto {u,v1,v2,w}:g[now]){
            if(last==u)dis[w]=max(dis[w],dis[now]);
            else dis[w]=max(dis[w],dis[now]+v1+v2);
            q.push_back({{w,u},dis[w]});
        }

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>t[i];
    for(int i=1;i<=n;i++){
        int a[500001],v[500001],last=0,las=0;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>v[j];
        }
        for(int j=1;j<k;j++){
            g[a[j]].push_back({i,v[j],v[j+1],a[j+1]});
            g[a[j+1]].push_back({i,v[j+1],v[j],a[j]});
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        memset(dis,0x3ffffff,sizeof(dis));
        dij(x,y);
        cout<<dis[e]+t[x]+t[y];
    }
    return 0;
}
