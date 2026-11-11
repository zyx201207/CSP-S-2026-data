#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
ll read(){
    ll num=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    return num;
}
void print(ll x){
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
const int M=5e5+5;
const int N=5e2+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
ll w[M],dis[N][N];
int s,t;
vector<pair<int,ll>>g[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1,k;i<=n;i++){
        k=read();
        for(int j=1,x,w;j<=k;j++)
            x=read(),w=read(),g[x].push_back({i,w});
    }
    memset(dis,INF,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(auto[v1,w1]:g[i])
            for(auto[v2,w2]:g[i])
                dis[v1][v2]=min(dis[v1][v2],w1+w2);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        s=read(),t=read();
        ll ans=INF;
        for(auto[u,w1]:g[s])
            for(auto[v,w2]:g[t])
                ans=min(ans,w[s]+w1+dis[u][v]+w2+w[t]);
        print(ans),putchar('\n');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
