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
csti N=2e6+7,mod=1;

int c,n,d,a[N],dis[N][3],lx[N],rx[N];

struct node{
    int x,v;
    il bool operator<(cst node _)cst{
        return v>_.v;
    }
};
il void dijkstra(csti s){
    rep(i,1,n){
        dis[i][0]=dis[i][1]=dis[i][2]=inf;
    }
    priority_queue<node> q;
    q.emplace(node{s,0});
    dis[s][0]=0;
    while(!q.empty()){
        cst node P=q.top();q.pop();
        csti x=P.x,v=P.v;
        //cout<<x<<' '<<v<<'\n';
        if(dis[x][2]<v){
            continue;
        }
        rep(y,lx[x],rx[x]){
            if(x==y){
                continue;
            }
            csti vx=1+v;
            if(dis[y][0]>=vx){
                dis[y][2]=dis[y][1];
                dis[y][1]=dis[y][0];
                dis[y][0]=vx;
                q.emplace(node{y,vx});
            }else if(dis[y][1]>=vx){
                dis[y][2]=dis[y][1];
                dis[y][1]=vx;
                q.emplace(node{y,vx});
            }else if(dis[y][2]>=vx){
                dis[y][2]=vx;
                q.emplace(node{y,vx});
            }
        }
    }
}

namespace subA{
    void solve(){
        if(a[2]-a[1]>=d){
            cout<<"0\n";
        }else{
            int now=0;
            int dx=a[2]-a[1],p=n;
            rep(i,1,n){
                if(d<dx*i){
                    p=i-2;break;
                }
            }
            cout<<max(0ll,n-p*2-1)<<'\n';
        }
    }
}
il void solve(){
    cin>>n>>d;
    bool fA=1;
    rep(i,1,n){
        cin>>a[i];
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
            fA=0;
           // cout<<i<<" er\n";
        }
    }
    //cout<<n<<"  ";
    if(n>5000&&fA){
        subA::solve();
        return;
    }
    int ans=0;
    rep(i,1,n){
        lx[i]=rx[i]=i;
        rep(j,1,n){
            if(abs_(a[i]-a[j])<=d){
                if(!lx[i]){
                    lx[i]=j;
                }
                rx[i]=j;
            }
        }
       // cout<<i<<" "<<lx[i]<<" "<<rx[i]<<'\n';
    }
    rep(i,1,n){
        dijkstra(i);
        rep(j,1,n){
            if(i!=j&&dis[j][0]!=inf&&dis[j][1]!=inf&&dis[j][2]!=inf){
                   // cout<<i<<" "<<j<<" "<<dis[j][0]<<" "<<dis[j][1]<<" "<<dis[j][2]<<"\n";
                if(dis[j][0]==dis[j][1]&&dis[j][1]!=dis[j][2]){
                    ans++;

                }
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
0 1
10 15
0 5 10 15 20 25 30 35 40 45

*/
