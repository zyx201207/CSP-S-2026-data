#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,long long>
using namespace std;
long long read(){
    long long k=0;
    int f=1,c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){k=k*10+(c^48);c=getchar();}
    return k*f;
}
void write(long long x){
    if(x<0)putchar('-');
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct Node{
    ll v,w;
};
vector<Node>g[500505];
ll c,n,m,d,q;
ll ww[505];
ll dij(ll s,int t){
    ll dis[500505];
    bool f[500505];
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(f,0,sizeof(f));
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        ll x=u.first,y=u.second;
        f[y]=1;
        if(dis[y]<x)continue;
        for(auto i:g[y]){
            if(f[i.v])continue;
            if(dis[i.v]>x+i.w){
                dis[i.v]=x+i.w;
                pq.push({dis[i.v],i.v});
            }
        }
    }/*
    for(int i=1;i<=m+n;i++){
            cout<<dis[i]<<" ";
        }
        cout<<endl;*/
    return dis[t];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++)ww[i]=read();
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        for(int j=1;j<=k;j++){
            ll x,y;
            x=read();y=read();
            g[i+m].push_back({x,y});
            g[x].push_back({i+m,y});
        }
    }
    while(q--){
        ll xr,yr;
        if(c>=12&&c<=19){
            bool f[500505]={0};
            ll idx=g[1][1].w;
            queue<pii>q;
            q.push({0,xr});
            ll ans=0;
            while(!q.empty()){
                auto x=q.front();
                q.pop();
                f[x.second]=1;
                if(x.second==yr){
                    ans=min(ans,idx*x.first);
                }
                for(auto y:g[x.second]){
                    if(!f[y.v]){
                        q.push({x.first+1,y.v});
                    }
                }
            }
            write(ans+ww[xr]+ww[yr]);
            putchar('\n');
            continue;
        }
        xr=read();yr=read();
        write(dij(xr,yr)+ww[xr]+ww[yr]);
        putchar('\n');
    }
    return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
