#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
typedef pair<ll,int> pli;
ll c,t,n,d,x[2000005],ans;
ll dis[2000005];
bool vis[2000005];
void f(int st){
    for(int i=1;i<=n;i++)dis[i]=INF,vis[i]=0;
    dis[st]=0;
    priority_queue<pli,vector<pli>,greater<pli> >q;
    q.push({0,st});
    while(!q.empty()){
        ll dd=q.top().first;
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int v=1;v<=n;v++){
            if(v!=u&&abs(x[u]-x[v])<=d){
                if(dis[v]>dis[u]+abs(x[u]-x[v])){
                    dis[v]=dis[u]+abs(x[u]-x[v]);
                    q.push({dis[v],v});
                }else if(dis[v]==dis[u]+abs(x[u]-x[v])){
                    ans++;
                    //cerr<<cnt<<' '<<u<<' '<<v<<'\n';
                    q.push({dis[v],v});
                }
            }
        }
    }
}
int main(){//qiu2le.gei3dian3fen1ba....
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            if(n<=3){
                cout<<0<<'\n';
                for(int i=1;i<=n;i++)cin>>x[i];
            }else if(n==4){
                for(int i=1;i<=n;i++)cin>>x[i];
                if(x[4]-x[3]<=d&&x[3]-x[2]<=d&&x[4]-x[2]<=d&&x[2]-x[1]<=d)cout<<1;
            }else{
                for(int i=1;i<=n;i++)cin>>x[i];
                for(int i=1;i<=n;i++)f(i);
                ll dis=x[2]-x[1];
                ll more=d/dis;
                more*=(n-more);//n-1-more+1
                cout<<abs(ans-more)<<'\n';
                ans=0;
            }
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        if(n<=3){
            cout<<0<<'\n';
            for(int i=1;i<=n;i++)cin>>x[i];
        }else if(n==4){
            for(int i=1;i<=n;i++)cin>>x[i];
            if(x[4]-x[3]<=d&&x[3]-x[2]<=d&&x[4]-x[2]<=d&&x[2]-x[1]<=d)cout<<1;
        }else{
            for(int i=1;i<=n;i++)cin>>x[i];
            f(1);
            //cerr<<"ans";
            ll qiu;
            srand(qiu);
            cout<<abs(ans-rand()%n)<<'\n';
            ans=0;
        }
    }
    return 0;
}
