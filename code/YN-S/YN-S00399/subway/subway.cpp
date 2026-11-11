#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6,inf=0x3f3f3f3f3f;
int c,n,m,d,q,mx;

inline ll rd(){
    ll f=1,x=0;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10LL+ch-'0';
        ch=getchar_unlocked();
    }
    return f*x;
}

struct node{
    int to,cost;
};

bool operator<(node xx,node yy){
    return xx.cost>yy.cost;
}

vector<node> g[N];

ll dijk(int st,int ed){
    vector<ll> dis(mx,inf);
    vector<bool> vis(mx,0);
    priority_queue<node> q;
    dis[st]=0;
    q.push((node){st,0});
    while(!q.empty()){
        node c=q.top();
        q.pop();
        if(!vis[c.to]){
            vis[c.to]=1;
            for(auto &i:g[c.to]){
                if(dis[c.to]+i.cost<dis[i.to]){
                    dis[i.to]=dis[c.to]+i.cost;
                    q.push((node){i.to,dis[i.to]});
                }
            }
        }
    }
    return dis[ed];
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rd();n=rd();m=rd();d=rd();q=rd();mx=m+m+n+1;
    for(int i=1;i<=m;i++){
        int x=rd();
        g[i].push_back((node){i+m,x});
        g[i+m].push_back((node){i,x});
    }
    for(int i=1;i<=n;i++){
        int k=rd();
        for(int j=1;j<=k;j++){
            int aa=rd(),tt=rd();
            g[i+m+m].push_back((node){aa,tt});
            g[aa].push_back((node){i+m+m,tt});
        }
    }
    while(q--){
        int x=rd(),y=rd();
        printf("%lld",dijk(x+m,y+m));
        putchar_unlocked('\n');
    }
    return 0;
}
