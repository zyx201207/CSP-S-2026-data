#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qq;
struct nm{
    int id,dis;
    bool operator<(const nm &other)const{
        return other.dis<dis;
    }
};
int w[500009];
vector<nm> a[500009];
int k[509];
int ans[1509][1509];
int v[1509][1509];
int s;
priority_queue<nm> q;
void dij(int x){
    while(!q.empty()){
        q.pop();
    }
    q.push((nm){x,w[x]});
    ans[x][x]=w[x];
    while(!q.empty()){
        nm u=q.top();
        q.pop();
        if(v[x][u.id]){
            ans[x][u.id]-=w[x];
            continue;
        }
        v[x][u.id]=1;
        for(auto vv:a[u.id]){
            s=vv.dis+u.dis;
            if(ans[x][vv.id]>s+w[vv.id]){
                ans[x][vv.id]=s+w[vv.id];
                q.push((nm){vv.id,s});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(ans,0x3f,sizeof(ans));
    int u1,w1;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>u1>>w1;
            a[m+i].push_back((nm){u1,w1});
            a[u1].push_back((nm){m+i,w1});
        }
    }
    for(int i=1;i<=m;i++){
        dij(i);
    }
    int q1,q2;
    for(int i=0;i<qq;i++){
        cin>>q1>>q2;
        cout<<ans[q1][q2]<<"\n";
    }
    return 0;
}
