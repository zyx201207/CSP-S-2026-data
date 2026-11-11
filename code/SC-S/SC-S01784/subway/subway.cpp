#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define pii pair<int,int>
const int N=509;
const int M=5e5+9;
const int D=25;
int c,n,m,d;
int inout[M];
vector<pii>e1[M];
long long dis[N][N];
inline int read(){
    int x=0,ch=getchar();
    while(ch<'0'||'9'<ch)ch=getchar();
    while('0'<=ch&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof dis);
    c=read(),n=read(),m=read(),d=read();
    int q=read();
    for(int i=1;i<=m;i++)inout[i]=read();
    for(int i=1;i<=n;i++){
        int edgenum=read();
        for(int j=1;j<=edgenum;j++){
            int to=read(),w=read();
            e1[to].push_back({i,w});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto y1:e1[i]){
            int to1=y1.first,w1=y1.second;
            for(auto y2:e1[i]){
                int to2=y2.first,w2=y2.second;
                dis[to2][to1]=dis[to1][to2]=min(dis[to1][to2],0ll+w1+w2);
            }
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1,u,v;i<=q;i++){
        u=read(),v=read();
        long long ans=1e18;
        for(auto y1:e1[u]){
            int to1=y1.first,w1=y1.second;
            for(auto y2:e1[v]){
                int to2=y2.first,w2=y2.second;
                ans=min(ans,w1+dis[to1][to2]+w2);
            }
        }
        printf("%lld\n",ans+inout[u]+inout[v]);
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/