#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
namespace YuJH{
    int n;
    long long d;
    long long x[5010];
    int dis[5010],cnt[5010];
    struct Node{
        int v,c;
    };
    struct SegT{
        Node val[20010];
        void build(){
            for(int i=1;i<=n*4;i++){
                val[i].v=1e9;
                val[i].c=0;
            }
            return;
        }
        void down(int u){
            if(val[u].v!=1e9){
                if(val[u<<1].v>val[u].v){
                    val[u<<1].v=val[u].v;
                    val[u<<1].c=val[u].c;
                }
                else if(val[u<<1].v==val[u].v){
                    val[u<<1].c+=val[u].c;
                    val[u<<1].c=min((int)1e9,val[u<<1].c);
                }
                if(val[u<<1|1].v>val[u].v){
                    val[u<<1|1].v=val[u].v;
                    val[u<<1|1].c=val[u].c;
                }
                else if(val[u<<1|1].v==val[u].v){
                    val[u<<1|1].c+=val[u].c;
                    val[u<<1|1].c=min((int)1e9,val[u<<1|1].c);
                }
            }
            val[u].v=1e9;
            val[u].c=0;
            return;
        }
        void update(int x,int y,Node z,int u=1,int l=1,int r=n){
            if(x<=l&&r<=y){
                if(val[u].v>z.v){
                    val[u].v=z.v;
                    val[u].c=z.c;
                }
                else if(val[u].v==z.v){
                    val[u].c+=z.c;
                    val[u].c=min((int)1e9,val[u].c);
                }
                return;
            }
            down(u);
            int mid=(l+r)>>1;
            if(x<=mid)
                update(x,y,z,u<<1,l,mid);
            if(mid+1<=y)
                update(x,y,z,u<<1|1,mid+1,r);
            return;
        }
        Node query(int x,int u=1,int l=1,int r=n){
            if(x==l&&x==r)
                return val[u];
            down(u);
            int mid=(l+r)>>1;
            if(x<=mid)
                return query(x,u<<1,l,mid);
            else
                return query(x,u<<1|1,mid+1,r);
        }
    };
    SegT seg;
    void bfs(int s){
        seg.build();
        seg.update(s,s,{0,1});
        for(int u=s,v=s;u<=n;u++){
            Node t=seg.query(u);
            dis[u]=t.v;
            cnt[u]=t.c;
            v=max(u,v);
            while(v+1<=n&&x[v+1]-x[u]<=d)
                v++;
            if(u<v)
                seg.update(u+1,v,{dis[u]+1,cnt[u]});
        }
        return;
    }
    int ans;
    int main(){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        ans=0;
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=i+1;j<=n;j++)
                if(dis[j]<=n&&cnt[j]==2)
                    ans++;
        }
        cout<<ans;
        return 0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--){
        YuJH::main();
        cout<<'\n';
    }
    return 0;
}