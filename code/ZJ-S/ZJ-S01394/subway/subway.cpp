#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
#define M 500005
#define N 505
#define inf 0x3f3f3f3f3f3f3f3f

inline int read(){int x=0,f=1;char c=getchar();while(!isdigit(c))c-'-'?:(f=-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return f*x;}


int Nanamine_Sakura[M];
vector<PII> g[M]; //g[i][k]=PAIR{j,s} 站厅 i to j 号线，路程 = s 
// vector<int> subway[N]; //地铁图
int sub[N][N];

void MAIN(){

    //先处理每两列车间的最小距离
    int n=read(),m=read(),d=read(),q=read();// n 是 地铁线路数!!!

    for(int i=1;i<=m;i++)Nanamine_Sakura[i]=read();
    for(int i=1;i<=n;i++){
        int x=read();
        while(x--)g[read()].push_back({i,read()});
    }

    // for(int i=1;i<=m;i++){
    //     printf("%lld:",i);
    //     for(PII u:g[i])printf("{%lld,%lld}",u.first,u.second);
    //     puts("");
    // }


    memset(sub,0x3f,sizeof sub);

    for(int i=1;i<=m;i++)
        for(PII u:g[i])
            for(PII v:g[i])
                sub[u.first][v.first]=min(sub[u.first][v.first],u.second+v.second);


    // for(int i=1;i<=n;i++,puts(""))
    //     for(int j=1;j<=n;j++)
    //         printf("%lld ",sub[i][j]);


    for(int i=1;i<=n;i++)sub[i][i]=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                sub[j][k]=min(sub[j][k],sub[j][i]+sub[i][k]);


    // for(int i=1;i<=n;i++,puts(""))
    //     for(int j=1;j<=n;j++)
    //         printf("%lld ",sub[i][j]);
    
    //再对每次询问x,y 枚举该去哪列车
    while(q--){

        int x=read(),y=read();
        int ans=inf;
        for(PII u:g[x])
            for(PII v:g[y])
                ans=min(ans,sub[u.first][v.first]+u.second+v.second);

        printf("%lld\n",ans+Nanamine_Sakura[x]+Nanamine_Sakura[y]);
    }


    // O (m*d^2+n^3+q*d^2) 100pts

    return ;
}

signed main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int Test_time=1,id=read();
    while(Test_time--)MAIN();
    return 0;
}
