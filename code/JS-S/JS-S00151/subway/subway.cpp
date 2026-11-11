#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
const ll MAX=1e16;
int read(){
    int x=0,f=1;char p=getchar();
    while(!isdigit(p)){if(p=='-')f=-1;p=getchar();}
    while(isdigit(p))x=x*10+p-'0',p=getchar();
    return x*f;
}
inline void write(ll x){
    char buf[20],pi=0;
    while(x)buf[++pi]='0'+x%10,x/=10;
    while(pi)putchar(buf[pi--]);
    putchar('\n');
}
struct edge{int t,w;};
int n,m,d,q;
int w[M];
int k,a,t;
vector<edge> co[M];
ll dist[N][N];
int x,y;ll ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        k=read();
        for(;k--;){
            a=read(),t=read();
            co[a].push_back(edge{i,t});
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dist[i][j]=i==j?0:MAX;
    for(int i=1;i<=m;i++){
        k=co[i].size();
        for(int j=0;j<k;j++){
            x=co[i][j].t;
            for(int p=j+1;p<k;p++){
                t=co[i][j].w+co[i][p].w;
                y=co[i][p].t;
                dist[x][y]=min(dist[x][y],(ll)t);
                dist[y][x]=min(dist[y][x],(ll)t);
            }
        }
    }
    //Floyd
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++)
            for(int p=1;p<i;p++)
                dist[i][j]=min(dist[i][j],dist[i][p]+dist[p][j]);
        for(int j=1;j<i;j++)dist[j][i]=dist[i][j];
        for(int j=1;j<i;j++)
            for(int p=1;p<i;p++)
                dist[j][p]=min(dist[j][p],dist[j][i]+dist[i][p]);
    }
    for(;q--;){
        x=read(),y=read();ans=MAX;
        for(auto i:co[x])
            for(auto j:co[y])
                ans=min(ans,dist[i.t][j.t]+i.w+j.w);
        write(ans+w[x]+w[y]);
    }
    return 0;
}