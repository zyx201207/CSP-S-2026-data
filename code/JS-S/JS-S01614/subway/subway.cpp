#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int rd(){
    int x=0;bool f=0;char c=getchar_unlocked();
    while((c<'0'||c>'9')&&c!='-')c=getchar_unlocked();
    if(c=='-')f=1,c=getchar_unlocked();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar_unlocked();
    if(f)return -x;
    return x;
}
int c,n,m,d,q;
int w[500005];
int a[505][500005];
int t[505][500005];
struct node{
    int to,w;
};
vector<node>e[500505];
ll dis[500505];
bool inq[500505];
ll spfa(int x,int y){
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    queue<int>q;
    q.push(x);
    inq[x]=1;
    dis[x]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(node v:e[u]){
            int to=v.to,w=v.w;
            if(dis[to]>dis[u]+w){
                dis[to]=dis[u]+w;
                q.push(to);
                inq[to]=1;
            }
        }
    }
    return dis[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
    for(int i=1;i<=m;i++){
        w[i]=rd();
    }
    for(int i=1;i<=n;i++){
        int k=rd();
        for(int j=1;j<=k;j++){
            a[i][j]=rd();
            t[i][j]=rd();
            e[a[i][j]].push_back({m+i,t[i][j]});
            e[m+i].push_back({a[i][j],t[i][j]});
        }
    }
    while(q--){
        int x=rd(),y=rd();
        cout<<spfa(x,y)+w[x]+w[y]<<'\n';
    }
    return 0;
}
