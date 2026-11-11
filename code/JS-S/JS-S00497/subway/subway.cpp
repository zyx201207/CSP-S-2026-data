#include<bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
const int N=510;
int n,m,d,q,k,ans;
int w[N],t[N][N],num[N];
bool vis[N][N];
int rd(){
    int si=1,x=0;
    char c;
    for(c=getchar();c<'0'||c>'9';c=getchar())
        if(c=='-')si=-1;
    for(;c>='0'&&c<='9';c=getchar())
        x=(x<<1)+(x<<3)+(c^48);
    return x*si;
}
void fre(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}
void fow(int i,int now,int g,int cost){
    if(ans<=cost)return;
    if(t[i][g]>0)ans=min(ans,t[i][g]+cost);
    for(rg int v=1;v<=m;v++){
        if(t[i][v]>0&&!vis[i][v]){
            vis[i][v]=true;
            fow(i,v,g,cost+t[i][v]);
            vis[i][v]=false;
        }
    }
    for(rg int p=1;p<=n;p++){
        if(t[p][now]>0&&!vis[p][now]){
            vis[p][now]=true;
            fow(p,now,g,cost+t[p][now]);
            vis[p][now]=false;
        }
    }
}
void dfs(int x,int y){
    for(rg int i=1;i<=n;i++){
        for(rg int j=1;j<=m;j++){
            if(t[i][x]>0){
                vis[i][x]=true;
                fow(i,x,y,t[i][x]);
                vis[i][x]=false;
            }
        }
    }

}
void work(){
    int cha=rd();
    n=rd();m=rd();d=rd();q=rd();
    for(rg int i=1;i<=m;i++)
        w[i]=rd();
    for(rg int i=1;i<=n;i++){
        k=rd();
        for(rg int j=1;j<=k;j++){
            t[i][rd()]=rd();
        }
    }
    while(q--){
        ans=0x3f3f3f3f;
        memset(vis,false,sizeof(vis));
        int ww=rd(),jj=rd();
        dfs(ww,jj);
        printf("%lld\n",ans+w[ww]+w[jj]);
    }
}
signed main()
{
  fre();
    work();
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
