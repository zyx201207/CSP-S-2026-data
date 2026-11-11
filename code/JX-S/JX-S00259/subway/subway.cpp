#include<bits/stdc++.h>
using namespace std;

const int N=5e5+7;
const int M=505;
int c,m,n,q,d;
int w[N];
long long dis[M][M];

struct node{
    int id,dis;
};
vector<node>a[N];

inline int read(){
    int res = 0 ;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
    res=res*10+ch-'0',ch=getchar();
    return res;
}

void init(){

    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;++i)dis[i][i]=0;

    for(int i=1;i<=m;++i){
        int len=a[i].size();
        for(int u=1;u<=len;++u){
            for(int v=1;v<u;++v){
                int p1=a[i][u-1].id;
                int p2=a[i][v-1].id;
                int d1=a[i][u-1].dis;
                int d2=a[i][v-1].dis;
                dis[p1][p2]=min(dis[p1][p2],d1*1ll+d2);
                dis[p2][p1]=dis[p1][p2];
            }
        }
    }

    for(int i=1;i<=n;++i)
    for(int k=1;k<=n;++k){
        if(i==k)continue;
        for(int j=1;j<=n;++j){
            if(i==j)continue;
            if(j==k)continue;
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            dis[j][i]=dis[i][j];
        }
    }
}

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read();
    d=read(),q=read();
    for(int i=1;i<=m;++i)w[i]=read();
    for(int i=1;i<=n;++i){
        int ss; ss=read();
        while(ss--){
            int x,y;
            x=read(),y=read();
            a[x].push_back({i,y});
        }
    }

    init();

    for(int i=1;i<=q;++i){
        int x,y;
        long long ans; 
        ans=1e18+7;
        x=read(),y=read();
        for(node u:a[x]){
            for(node v:a[y]){
                int d1=u.dis;
                int d2=v.dis;
                ans=min(ans,dis[u.id][v.id]+d1+d2);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
        //print the ans...
    }

    return 0;
}