#include<bits/stdc++.h>
using namespace std;
long long Read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-48;
        c=getchar();
    }
    return f*x;
}
long long t,n,k,c;
long long a[500005];
struct node{
    int pos,w;
};
long long dis[500005],vis[500005],cnt[500005],dist[500005],vis2[500005];
vector<node> q[500005];
vector<node> q2[500005];
void dij(int s){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++){
        cnt[i]=1;
    }
    priority_queue<pair<int,int>> pr;
    dis[s]=0;
    pr.push({-dis[s],s});
    while(!pr.empty()){
        int u=pr.top().second;
        pr.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto it:q[u]){
            int fir=it.pos;
            int sec=it.w;
            if(dis[fir]>dis[u]+sec){
                //cout<<dis[u]<<' '<<sec<<'\n';
                dis[fir]=dis[u]+sec;
                pr.push({-dis[fir],fir});
                cnt[fir]=1;
            }else if(dis[fir]==dis[u]+sec){
                cnt[fir]+=cnt[u];
            }
        }
    }
}
void dij2(int s){
    memset(dist,0x3f,sizeof dist);
    memset(vis2,0,sizeof vis2);
    priority_queue<pair<int,int>> pr;
    dist[s]=0;
    pr.push({-dist[s],s});
    while(!pr.empty()){
        int u=pr.top().second;
        pr.pop();
        if(vis2[u]) continue;
        vis2[u]=1;
        for(auto it:q2[u]){
            int fir=it.pos;
            int sec=it.w;
            if(dist[fir]>dist[u]+sec){
                //cout<<dis[u]<<' '<<sec<<'\n';
                dist[fir]=dist[u]+sec;
                pr.push({-dist[fir],fir});
            }
        }
    }
}
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    c=Read();
    t=Read();
    while(t--){
        n=Read();
        k=Read();
        for(int i=1;i<=n;i++){
            a[i]=Read();
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(abs(a[i]-a[j])<=k){
                    q[i].push_back({j,0});
                    q[j].push_back({i,0});
                    q2[i].push_back({j,1});
                    q2[j].push_back({i,1});
                }else{
                    q[i].push_back({j,abs(a[i]-a[j])});
                    q[j].push_back({i,abs(a[i]-a[j])});
                    q2[i].push_back({j,1});
                    q2[j].push_back({i,1});
                }
            }
        }
        int cn=0;
        for(int i=1;i<=n;i++){
            dij(i);
            dij2(i);
            for(int j=1;j<i;j++){
                if(cnt[j]==2&&dist[i]==dist[j]){
                    cn++;
                }
                cout<<cnt[j]<<' ';
            }
            cout<<'\n';
        }
        cout<<cn<<'\n';
    }
    return 0;
}
