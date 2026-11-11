#include<bits/stdc++.h>
#define ll long long
#define atn 522222
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct cmp{
    bool operator()(const pair<ll,ll> &a,const pair<ll,ll> &b){
        return a.se>b.se;
    }
};
ll d[3*atn],a[atn];ll c,n,m,xqd,T;
vector<pair<ll,ll>>v[3*atn];
bool vis[3*atn];
ll num;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp>q;
void dij(int s){
    f(i,1,num)d[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
    d[s]=0;q.push({s,0});
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        ll x=q.top().fi,zz=q.top().se;
        q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(auto i:v[x]){
            if(d[i.fi]>d[x]+i.se){
                d[i.fi]=d[x]+i.se;
                q.push({i.fi,d[i.fi]});
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>xqd>>T;
    f(i,1,m){
        cin>>a[i];
        v[i].pb({m+i,a[i]});
        v[m+i].pb({i,a[i]});
    }
    num=2*m;
    f(i,1,n){
        ll k;cin>>k;
        ll lst=-1;
        f(j,1,k){
            ll u,w;cin>>u>>w;++num;
            if(lst!=-1){

                v[num].pb({num-1,0});
                v[num-1].pb({num,0});
            }
            lst=u;
            v[num].pb({m+u,w});
            v[m+u].pb({num,w});
            //cout<<endl<<':'<<num<<' '<<m+j<<' '<<w<<endl;
        }
    }
    while(T--){
        int st,ed;cin>>st>>ed;
        dij(st);
        cout<<d[ed]<<'\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7

*/
