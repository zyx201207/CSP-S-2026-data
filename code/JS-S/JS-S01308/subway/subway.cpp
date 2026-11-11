#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=5e5+5;
inline int read(){
    int x=0;
    char c=getchar_unlocked();
    while(c<'0'||c>'9')c=getchar_unlocked();
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar_unlocked();
    }return x;
}int o,n,m,zq[M],D,T,t[M][2],d[M];
vector<int>head,nxt,to,w;
bool b[M];
priority_queue<pair<int,int> >q;
void add(int u,int v,int k){
    nxt.push_back(head[u]);
    head[u]=to.size();
    to.push_back(v);
    w.push_back(k);
}
void dij(int s,int v){
    memset(b,0,sizeof(b));
    memset(d,0x3f,sizeof(d));
    while(!q.empty())q.pop();
    d[s]=0;q.push({0,s});
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(x==v)break;
        if(b[x])continue;
        b[x]=1;
        for(int i=head[x];~i;i=nxt[i]){
            int y=to[i];
            if(d[x]+w[i]<d[y]){
                d[y]=d[x]+w[i];
                q.push({-d[y],y});
            }
        }
    }
}
void print(int x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    o=read();n=read();m=read();D=read();T=read();
    head.resize(M,-1);
    for(int i=1;i<=m;i++)zq[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){t[j][0]=read();t[j][1]=read();}
        for(int j=1;j<k;j++)
            for(int z=j+1;z<=k;z++){
                add(t[j][0],t[z][0],t[j][1]+t[z][1]);
                add(t[z][0],t[j][0],t[j][1]+t[z][1]);
            }
    }while(T--){
        int u=read(),v=read();
        dij(u,v);
        int ans=d[v]+zq[u]+zq[v];
        print(ans);putchar('\n');
    }
    return 0;
}