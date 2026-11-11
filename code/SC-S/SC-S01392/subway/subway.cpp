#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
const int N=505;
const int M=5e5+5;
const int MM=1005;
const int NM=3e4+5;
struct node{
    int v,w,nxt;
}ll[(N+M)<<2];
struct node2{
    int v;
    long long w;
    bool operator<(const node2&xx)const{
        return w>xx.w;
    }
};
struct node3{
    int v;
    long long w;
};
int c,n,m,d,qu,cnt,top,sta;
int w[M],head[(N+M)<<1];
long long dis[MM][MM+N],dist[NM];
bool used[MM][MM+N],vis[NM];
priority_queue<node2>q;
node3 qq[NM<<5];
void add(int u,int v,int w){
    ll[++cnt]={v,w,head[u]};
    head[u]=cnt;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qu;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,ti;
            cin>>a>>ti;
            add(i+m,a,ti);
            add(a,i+m,ti);
        }
    }
    if(c<=11||m<=1005){
        for(int i=1;i<=m+n;i++){
            for(int j=1;j<=m+n;j++){
                dis[i][j]=inf;
            }
        }
        for(int i=1;i<=m;i++){
            dis[i][i]=0;
            q.push({i,0});
            while(!q.empty()){
                node2 ct=q.top();q.pop();
                if(used[i][ct.v])continue;
                used[i][ct.v]=1;
                for(int j=head[ct.v];j;j=ll[j].nxt){
                    node t=ll[j];
                    if(dis[i][t.v]>dis[i][ct.v]+t.w){
                        dis[i][t.v]=dis[i][ct.v]+t.w;
                        q.push({t.v,dis[i][t.v]});
                    }
                }
            }
        }
        while(qu--){
            int x,y;
            cin>>x>>y;
            cout<<dis[x][y]+1LL*w[x]+1LL*w[y]<<'\n';
        }
    }
    else{
        while(qu--){
            for(int i=1;i<=n+m;i++){dist[i]=inf;vis[i]=0;}
            int x,y;
            cin>>x>>y;
            top=0;
            dist[x]=0;
            qq[++top]={x,0};
            sta=1;
            while(sta<=top){
                node3 ct=qq[sta];sta++;
                vis[ct.v]=1;dist[ct.v]=ct.w;
                for(int j=head[ct.v];j;j=ll[j].nxt){
                    node t=ll[j];
                    if(vis[t.v])continue;
                    vis[t.v]=1;
                    qq[++top]={t.v,ct.w+t.w};
                }
            }
            cout<<dist[y]+1LL*w[x]+1LL*w[y]<<'\n';
        }
    }
}