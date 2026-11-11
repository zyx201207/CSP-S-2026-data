#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
    }
    putchar(x%10+'0');
}
int dp[1010][1010];
int a[500010],t[500010];
int w[500010];
vector<pair<int,int> >g[10010];
int n,m,d,q;
void solve1(){//1-8
    n=read();
    m=read();
    d=read();
    q=read();
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            a[j]=read(),t[j]=read();
        }
        // for(int i=1;i<=k;i++){
        //     cout<<a[i]<<' ';
        // }
        // cout<<endl;
        // for(int i=1;i<=k;i++){
        //     cout<<t[i]<<' ';
        // }
        // cout<<endl;
        
        for(int u=1;u<=k;u++){
            for(int v=1;v<=k;v++){
                if(u==v) continue;
                dp[a[u]][a[v]]=min(dp[a[u]][a[v]],t[u]+t[v]);
                // cout<<"build:"<<a[u]<<' '<<a[v]<<endl;
            }
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++){
    //         if(dp[i][j]<=1000) cout<<dp[i][j]<<' ';
    //         else cout<<"-1 ";
    //     }
    //     cout<<endl;
    // }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        int u=read(),v=read();
        write(dp[u][v]+w[u]+w[v]);
        putchar('\n');
    }
    return ;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qu;
bool h[1010];
void dijkstra(int u){
    dp[u][u]=0;
    memset(h,0,sizeof h);
    while(!qu.empty()) qu.pop();
    qu.push(make_pair(0,u));
    while(!qu.empty()){
        auto tem=qu.top();
        qu.pop();
        while(!qu.empty()&&h[tem.second]){
            tem=qu.top();
            qu.pop();
        }
        if(h[tem.second]) break;
        h[tem.second]=1;
        // cout<<tem.first<<' '<<tem.second<<endl;
        for(auto p:g[tem.second]){
            int d=dp[u][tem.second]+p.second;
            if(dp[u][p.first]>d){
                dp[u][p.first]=d;
                qu.push(make_pair(d,p.first));
            }
        }
    }
    return ;
}
void solve2(){//A
    n=read();
    m=read();
    d=read();
    q=read();
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int k=read();
        a[1]=read(),t[1]=read();
        a[2]=read(),t[2]=read();
        dp[a[1]][a[2]]=min(dp[a[1]][a[2]],t[1]+t[2]);
        dp[a[2]][a[1]]=dp[a[1]][a[2]];
        // cout<<"egde:"<<a[1]<<' '<<a[2]<<' '<<t[1]<<endl;
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++){
    //         if(dp[i][j]<=1000) cout<<dp[i][j]<<' ';
    //         else cout<<"-1 ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i!=j&&dp[i][j]<=0x7fffffffffff){
                g[i].push_back(make_pair(j,dp[i][j]));
                g[j].push_back(make_pair(i,dp[i][j]));
                // cout<<i<<' '<<j<<' '<<dp[i][j];
            }
        }
    }
    memset(dp,0x3f,sizeof dp);
    // dijkstra(1);
    for(int i=1;i<=m;i++){
        dijkstra(i);
        // for(int j=1;j<=m;j++){
        //     cout<<dp[i][j]<<' ';
        // }
        // cout<<endl;
    }
    while(q--){
        int u=read(),v=read();
        write(dp[u][v]+w[u]+w[v]);
        putchar('\n');
    }
    return ;
}
vector<int>pas[500010];//record which lines go pass this station
void solve3(){
    n=read();
    m=read();
    d=read();
    q=read();
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            a[j]=read();
            t[j]=read();
        }
        for(int j=1;j<=k;j++){
            pas[a[j]].push_back(i);
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(auto j:pas[i]){
    //         cout<<j<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=m;i++){
        for(int u=0;u<pas[i].size();u++){
            for(int v=u+1;v<pas[i].size();v++){
                // cout<<pas[i][u]<<' '<<pas[i][v]<<endl;
                dp[pas[i][u]][pas[i][v]]=1;
                dp[pas[i][v]][pas[i][u]]=1;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(dp[i][j]<=1000) cout<<dp[i][j]<<' ';
    //         else cout<<"-1 ";
    //     }
    //     cout<<endl;
    // }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            dp[i][i]=0;
            for(int j=i+1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                dp[j][i]=dp[i][j];
            }
        }
    }
    while(q--){
        int x=read(),y=read();
        int minn=0x7fffffffff;
        for(int u=0;u<pas[x].size();u++){
            for(int v=0;v<pas[y].size();v++){
                minn=min(minn,dp[pas[x][u]][pas[y][v]]);
            }
        }
        write((minn+1)*2*t[1]+w[x]+w[y]);
        putchar('\n');
    }
    return ;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int id=read();
    if(id<=8) solve1();
    if(id>=9&&id<=11) solve2();
    if(id>=12&&id<=19) solve3();
    return 0;
}
/*
for subtask 1-8:
we can simply add edges and run floyd
time complexity: O(nk^2+n^3)

for subtask 9-11 (A):
we can run dijkstra for each start point
time complexity: O(n^2logn)

for subtask 12-19 (B):
we need to find the lowest count of transfering
we can let every metro line be a vex,
for every staion, record the lines that go pass the station
build egdes, time complexity O(md^2), about 2e8
then run floyd on O(n^3) about 1.25e7
for each query, O(qd^2),get the begin and end station, about 4e7
total time complexity: O((m+q)d^2+n^3) about 2.5e8
hope the divine machine can run this in 1s...

start coding: 15:19
1-8 pass 15:35

bro why diff doesnt work???
AHHHHHHHHHHHHHHHHHHHHHH
have to write checker to run diff, which takes half an hour

9-11 pass 16:32

12-19 pass 17:14
expect 76 pts

*/