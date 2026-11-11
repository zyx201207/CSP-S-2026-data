#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define N 15010
using namespace std;
const int inf=1e13;
int c,n,m,d,q;
int dist[N][N],w[N],a[N],t[N];
bool vis[N],flag[N][N];
vector<pii> G[N];
priority_queue<pii,vector<pii>,greater<pii> > pq;
int read(){
    int x=0;
    char c=getchar_unlocked();
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar_unlocked();
    }
    return x;
}
void write(int x){
    string s="";
    while(x){
        s=char('0'+x%10)+s,x/=10;
    }
    for(char c:s){
        cout<<c;
    }
    cout<<'\n';
}
void dij(int s){
    for(int i=1;i<=m;i++){
        if(i!=s)
            dist[s][i]=inf;
    }
    pq.push({0,s});
    while(!pq.empty()){
        pii temp=pq.top();
        pq.pop();
        int val=temp.fi,pos=temp.se;
        flag[s][pos]=1;
        for(pii edge:G[pos]){
            int to=edge.fi,ww=edge.se;
            if(flag[s][to])
                continue;
            int _new=dist[s][pos]+ww;
            if(_new<dist[s][to]){
                dist[s][to]=_new;
                pq.push({_new,to});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            a[j]=read(),t[j]=read();
            for(int l=1;l<j;l++){
                int from=a[j],to=a[l],val=t[j]+t[l];
                G[from].push_back({to,val});
                G[to].push_back({from,val});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int from,to;
        from=read(),to=read();
        if(vis[to])
            swap(from,to);
        if(!vis[from] && !vis[to])
            dij(from),vis[from]=1;
        write(dist[from][to]+w[from]+w[to]);
    }
    return 0;
}
