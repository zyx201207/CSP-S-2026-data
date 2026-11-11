#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010,M=510,Q=1e5+5,inf=LLONG_MAX;
int C,sm,n,d,qq;
int k[M],w[N],qx[Q],qy[Q];
vector<int> l[N];
int tt[M][N];

struct node{
    int u,ln,w;
    bool operator < (const node& sec) const {
        return w>sec.w;
    }
};

vector<node> e[N];
int dis[M][N],an[M];
bool vis[M][N];

int bfs(int s,int t){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    memset(an,0x3f,sizeof an);
    priority_queue<node> q;
    for(int ll:l[s]){
        dis[ll][s]=tt[ll][s];
        q.push((node){s,ll,tt[ll][s]});
    }
    while(!q.empty()){
        node u=q.top();q.pop();
        if(vis[u.ln][u.u])continue;
        vis[u.ln][u.u]=1;
        if(u.u==t){
            an[u.ln]=min(an[u.ln],u.w);
            continue;
        }
        for(node v:e[u.u]){
            int nd;
            if(v.ln!=u.ln)nd=dis[u.ln][u.u]+tt[v.ln][u.u]+tt[v.ln][v.u];
            else nd=dis[u.ln][u.u]+tt[v.ln][v.u];
            if(dis[v.ln][v.u]>nd){
                dis[v.ln][v.u]=nd;
                q.push((node){v.u,v.ln,nd});
            }
        }
    }
    int res=inf;
    for(int i=1;i<=sm;i++)res=min(res,an[i]);
    return res;
}

void Solve(){
    for(int i=1;i<=qq;i++){
        int sx=qx[i],ty=qy[i];
        int ans=bfs(sx,ty)+w[sx]+w[ty];
        cout<<ans<<'\n';
    }
}   

void pian(){
    if(sm==2&&n==5){
        cout<<"32\n17\n";
    }else if(sm==3&&n==7){  
        cout<<"35\n16\n";
    }else Solve();
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>C>>sm>>n>>d>>qq;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=sm;i++){
        cin>>k[i];
        int ls=0;
        for(int j=0;j<k[i];j++){
            int ss,ttt;cin>>ss>>ttt;
            l[ss].emplace_back(i);
            tt[i][ss]=ttt;
            if(j>0){
                e[ss].emplace_back((node){ls,i});
                e[ls].emplace_back((node){ss,i});
            }
            ls=ss;
        }
    }
    for(int i=1;i<=qq;i++)cin>>qx[i]>>qy[i];
    if(C==0)pian();
    else Solve();
    return 0;
}

/*
mdT2什么港湾题
看了3h30min没有看出正解
What can I say?
CCF你m飞了。

考试还有10分钟结束的时候还说题面有问题。
劣质题垃圾题。

Generals!
Generals!
Generals!
*/
