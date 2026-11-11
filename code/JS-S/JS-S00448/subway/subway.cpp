#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=0,maxn=505,maxm=5e5+5;
int read(){
    int f=1,k=0,c=getchar_unlocked();
    for(;!isdigit(c);c=getchar_unlocked()){
        if(c=='-'){
            f=-1;
        }
    }
    for(;isdigit(c);c=getchar_unlocked()){
        k=k*10+(c^48);
    }
    return f*k;
}
map<pair<int,int>,int> t;
vector<int> a[maxn],G1[maxm],G2[maxn];
int n,w[maxm],c,m,d,_,dis[maxn];
bool v[maxm];
void init1(){
    for(int i=1;i<=n;i++){
        for(int j:a[i]){
            for(int k:a[i]){
                if(j!=k){
                    G1[j].push_back(k);
                    G2[j].push_back(t[make_pair(j,i)]+t[make_pair(k,i)]);
                }
            }
        }
    }
}
struct node{
    int u,dis;
};
struct cmp{
    bool operator () (node x,node y){
        return x.dis>y.dis;
    }
};
priority_queue<node,vector<node>,cmp> q;
void solve1(){
    int x=read(),y=read();
    for(int i=1;i<=m;i++){
        dis[i]=INT_MAX;
        v[i]=0;
    }
    dis[x]=0;
    q.push((node){x,0});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(v[u]){
            continue;
        }
        v[u]=1;
        for(int i=0;i<G1[u].size();i++){
            int vv=G1[u][i];
            if(!v[vv]&&dis[vv]>dis[u]+G2[u][i]){
                dis[vv]=dis[u]+G2[u][i];
                q.push((node){vv,dis[vv]});
            }
        }
    }
    cout<<dis[y]+w[x]+w[y]<<"\n";
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    _=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int x=read();
        for(int j=1;j<=x;j++){
            int aa=read(),tt=read();
            a[i].push_back(aa);
            t[make_pair(aa,i)]=tt;
        }
    }
    if(c<=11){
        init1();
    }
    while(_--){
        if(c<=11){
            solve1();
        }
    }
    return 0;
}


/*
e a
bu shi,zhe sha wan yi a wo fu le
zhe ti mian du de wo xiang shi chi le yi zheng fa wu liang kong chu
zuo de wo hao shao xin
kan dao bian liang de shi hou hai po beng yi xia
na shuo sha le,tai jue wang le,zhe ba gei le
*/
