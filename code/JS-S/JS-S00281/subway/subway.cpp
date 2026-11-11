#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define int long long
using namespace std;
struct node{
    int v,w;
};
bool operator<(node x,node y){
    return x.w>y.w;
}
int c,n,m,d,q;
int w[500050];
vector<node>edge[2000050];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10){
        write(x/10);
        x%=10;
    }
    putchar(x+'0');
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    if(c<=15||c>=24||c==22||c==23){
        for(int i=1;i<=n;i++){
            int l=read();
            for(int j=1;j<=l;j++){
                int a=read(),t=read();
                edge[i+m].push_back({a,t});
                edge[a].push_back({i+m,t});
            }
        }
        while(q--){
            int x=read(),y=read();
            int d[n+m+1];
            for(int i=1;i<=n+m;i++)d[i]=1e18;
            d[x]=0;
            priority_queue<node>pq;pq.push({x,0});
            while(!pq.empty()){
                int u=pq.top().v,w=pq.top().w;pq.pop();
                if(d[u]!=w)continue;
                for(auto e:edge[u]){
                    if(d[e.v]>d[u]+e.w){
                        d[e.v]=d[u]+e.w;
                        pq.push({e.v,d[e.v]});
                    }
                }
            }
            write(d[y]+w[x]+w[y]);
            putchar('\n');
        }
    }
    else if(16<=c&&c<=19){
        vector<int>g[m+1];
        int T;
        for(int i=1;i<=n;i++){
            int l=read();
            for(int j=1;j<=l;j++){
                int a=read(),t=read();T=t;
                g[a].push_back(i);
            }
        }
        set<int>v[n+1];
        for(int i=1;i<=m;i++){
            for(int j=0;j<g[i].size()-1;j++){
                for(int k=j+1;k<g[i].size();k++){
                    v[g[i][j]].insert(g[i][k]);
                    v[g[i][k]].insert(g[i][j]);
                }
            }
        }
        int dis[n+1][n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=1e16;
            }
        }
        for(int i=1;i<=n;i++){
            for(auto e:v[i]){
                dis[i][e]=dis[e][i]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                for(int k=1;k<=n;k++){
                    if(i==k||j==k)continue;
                    dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        for(int i=1;i<=n;i++)dis[i][i]=0;
/*        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dis[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        while(q--){
            int x=read(),y=read();
            int ans=1e16;
            for(auto o:g[x]){
                for(auto p:g[y]){
                    ans=min(ans,dis[o][p]);
                }
            }
            write(ans*T+T*2+w[x]+w[y]);
            putchar('\n');
        }
    }
    else if(c==20||c==21){
        bool belong[m+1][2];
        int dis[m+1][2];
        memset(belong,0,sizeof(belong));
        for(int i=1;i<=m;i++){
            dis[i][0]=dis[i][1]=1e16;
        }
        for(int i=1;i<=n;i++){
            int l=read();
            for(int j=1;j<=l;j++){
                int a=read(),t=read();
                belong[a][i-1]=1;
                dis[a][i-1]=t;
            }
        }
        int mindis=1e16;
        for(int i=1;i<=m;i++){
            if(belong[i][0]&&belong[i][1]){
                mindis=min(mindis,dis[i][0]+dis[i][1]);
            }
        }
        while(q--){
            int x=read(),y=read();
            if(belong[x][0]&&belong[x][1]&&belong[y][0]&&belong[y][1]){
                int ans1=min(dis[x][0]+dis[y][0],dis[x][1]+dis[y][1]);
                int ans2=min(dis[x][1]+dis[y][0],dis[x][0]+dis[y][1])+mindis;
                write(min(ans1,ans2)+w[x]+w[y]);
                putchar('\n');
            }
            else if(!belong[x][0]&&belong[x][1]&&belong[y][0]&&belong[y][1]){
                int ans1=dis[x][1]+dis[y][1];
                int ans2=dis[x][1]+dis[y][0]+mindis;
                write(min(ans1,ans2)+w[x]+w[y]);
                putchar('\n');
            }
            else if(belong[x][0]&&!belong[x][1]&&belong[y][0]&&belong[y][1]){
                int ans1=dis[x][0]+dis[y][0];
                int ans2=dis[x][0]+dis[y][1]+mindis;
                write(min(ans1,ans2)+w[x]+w[y]);
                putchar('\n');
            }
            else if(belong[x][0]&&belong[x][1]&&!belong[y][0]&&belong[y][1]){
                int ans1=dis[y][1]+dis[x][1];
                int ans2=dis[y][1]+dis[x][0]+mindis;
                write(min(ans1,ans2)+w[x]+w[y]);
                putchar('\n');
            }
            else if(!belong[x][0]&&belong[x][1]&&!belong[y][0]&&belong[y][1]){
                write(dis[x][1]+dis[y][1]+w[x]+w[y]);
                putchar('\n');
            }
            else if(belong[x][0]&&!belong[x][1]&&!belong[y][0]&&belong[y][1]){
                write(dis[x][0]+dis[y][1]+w[x]+w[y]+mindis);
                putchar('\n');
            }
            else if(belong[x][0]&&belong[x][1]&&belong[y][0]&&!belong[y][1]){
                int ans1=dis[y][0]+dis[x][0];
                int ans2=dis[y][0]+dis[x][1]+mindis;
                write(min(ans1,ans2)+w[x]+w[y]);
                putchar('\n');
            }
            else if(!belong[x][0]&&belong[x][1]&&belong[y][0]&&!belong[y][1]){
                write(dis[x][1]+dis[y][0]+w[x]+w[y]+mindis);
                putchar('\n');
            }
            else if(belong[x][0]&&!belong[x][1]&&belong[y][0]&&!belong[y][1]){
                write(dis[x][0]+dis[y][0]+w[x]+w[y]);
                putchar('\n');
            }
        }
    }
    return 0;
}
