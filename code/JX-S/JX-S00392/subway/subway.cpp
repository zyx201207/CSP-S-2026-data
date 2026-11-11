#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
inline int read(int &a){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return a=x*f;
}
int c,n,m,d,q;
int k[N];
int cnt;
int e[N],ne[N],h[N],w[N],idx;

void add(int a,int b,int c){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

typedef pair<int,int> PII;
int dist[N],st[N];
void dijkstra(int s){
    priority_queue<PII,vector<PII>,greater<PII>> q;
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(st[u])continue;
        st[u]=1;
        for(int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[u]+w[i]){
                dist[j]=dist[u]+w[i];
                q.push({dist[j],j});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(h,-1,sizeof h);
    read(c);
    read(n);
    read(m);
    read(d);
    read(q);
    for(int i=1;i<=m;i++){
        int w;
        read(w);
        int a=++cnt;
        int b=++cnt;
        add(a,b,w);
        add(b,a,w);
    }
    for(int i=1;i<=n;i++){
        int k;
        int x,y;
        int a,b;
        read(k);
        for(int j=1;j<=k;j++){
            if(j!=1){
                add(a,cnt+1,0);
                add(cnt+1,a,0);
            }
            read(x),read(y);
            a=++cnt;
            b=2*x;
            add(a,b,y);
            add(b,a,y);
        }
    }
    
    for(int i=1;i<=q;i++){
        int a,b;
        read(a),read(b);
        dijkstra(a*2-1);
        cout<<dist[b*2-1]<<"\n";
    }
    return 0;
}