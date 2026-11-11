#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e3+5;

int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
bool vis[MAXN];
int dis[MAXN][MAXN];
int n,k;
void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c=read(),T=read();
    srand(time(NULL));
    while(T--){
        n=read(),k=read();
        for(int i=1;i<=n-1;i++){
            int u=read(),v=read();
            dis[u][v]=dis[v][u]=1;
        }
        memset(dis,0x3f,sizeof(dis));
        int ans=0x3f3f3f;
        Floyd();
        for(int t=0;t<10000;t++){
            for(int i=1;i<=n;i++) vis[i]=false;
            for(int i=1;i<=k;i++){
                int r=rand()%n+1;
                while(vis[r]) r=rand()%n+1;
                vis[r]=true;
            }
            int kkk=0;
            for(int i=1;i<=n;i++){
                int p=0x3f3f3f;
                for(int j=1;j<=n;j++){
                    if(vis[j]) p=min(p,dis[i][j]);
                }
                kkk=max(p,kkk);
            }
            ans=min(ans,kkk);
        }
        cout<<ans<<endl;
    }
    return 0;
}