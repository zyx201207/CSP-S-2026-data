#include<bits/stdc++.h>
using namespace std;
#define il inline
#define cst const
#define csti const int
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define rep1(i,l,r) for(int i=(l);i<(r);++i)
#define ll long long
#define mkp make_pair
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define int long long
#define LOL

#ifdef LOL
csti inf=0x3f3f3f3f3f3f3f3f;
#else
csti inf=0x3f3f3f3f;
#endif // LOL
il int abs_(csti x){
    return x>0?x:-x;
}
csti N=1e6+7,mod=1;

int c,n,m,d,q,a[N];
struct node{
    int y,v;
};
//vector<int> g[N];
vector<int> l[N];
unordered_map<int,int> mp[N];


struct nodes{
    int x,t;
    il bool operator<(cst nodes _)cst{
        return t>_.t;
    }
};
int dis[507][507];
vector<node> g2[507];
void dijk(csti s){
    memset(dis[s],0x3f,sizeof dis[s]);
    priority_queue<nodes> q;
    q.emplace(nodes{s,0});
    dis[s][s]=0;
    while(!q.empty()){
        cst nodes P=q.top();q.pop();
        csti x=P.x,t=P.t;
       // cout<<s<<" "<<x<<" "<<t<<'\n';
        if(dis[s][x]<t){
            continue;
        }
        for(cst node e:g2[x]){
            csti lx=e.y,v=e.v,vx=t+v;
                //cout<<" to "<<y<<" "<<lx<<" "<<t<<" "<<mp[x-m][y]<<' '<<mp[lx][y]<<'\n';
            if(dis[s][lx]>vx){
             //   cout<<s-m<<" "<<lx<<" val\n";
                dis[s][lx]=vx;q.emplace(nodes{lx,vx});
            }
        }
    }
}

void init(){
    rep(i,1,n){
        dijk(i);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m){
        cin>>a[i];
    }
    int V=inf,S=0;
    rep(i,1,n){
        int cnt;cin>>cnt;
        S+=cnt;
        rep(j,1,cnt){
            int x,y;cin>>x>>y;
            mp[i][x]=y;
            l[x].eb(i);
        }
    }
    rep(i,1,m){
        for(csti k1:l[i]){
            for(csti k2:l[i]){
                if(k1!=k2){
                    g2[k1].eb(node{k2,mp[k1][i]+mp[k2][i]});
                }
            }
        }
    }
    init();
    rep(Q,1,q){
        int x,y;cin>>x>>y;
        int ans=inf;
        for(csti k1:l[x]){
            for(csti k2:l[y]){
               //     cout<<k1<<" "<<k2<<"  "<<dis[k1][k2]<<'\n';
                ans=min(ans,mp[k1][x]+mp[k2][y]+dis[k1][k2]);
            }
        }
        cout<<ans+a[x]+a[y]<<'\n';
    }
    return 0;
}
/*
0 2 3 20 1
1 1 1
2 1 100 3 100
3 1 2 2 2 3 2
1 3

>80p
*/
