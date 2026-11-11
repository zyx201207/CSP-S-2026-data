#include<bits/stdc++.h>
using namespace std;
int C,d;//测试点编号、每个地铁站最多被几条线路经过
int n,m,q;//地铁线路数、地铁站数、出行计划数
int w[50010];//第I从个地铁站的地铁口走到站厅需要的时间
int k[510];//第I条线路经过的地铁站数
int a[510][50010];//第I条线路经过的第J个地铁站的编号
int tr[50010][510];//从该地铁站J的站厅走到第I条线路的站台需要的时间
int xr[510],yr[510];//第I个出行计划的起点和终点所在的地铁站编号
int dist[510][50010];
vector<int> b[500010];//第I个地铁站数经过的线路
//1 11
int vl[50010],vt[50010];
int e=1e9;
void dfs(int x,int y,int tm,int zm){//地铁站编号,地铁线路,时间,终点所在的地铁站编号
    if(x==zm){
        e=min(e,tm);
        return ;
    }
    if(dist[x][y]<tm) return ;
    dist[x][y]=tm;
    if(vl[y]==0){
        for(int i=1;i<=k[y];i++){//站
            int ty=a[y][i];
            if(vt[ty]==0){
                vt[ty]=1;
                vl[y]=1;
                dfs(ty,y,tm+tr[ty][y],zm);
                vl[y]=0;
                vt[ty]=0;
            }
        }
    }
    for(int i=0;i<b[x].size();i++){//地铁线
        int lx=b[x][i];
        if(vl[lx]==0){
            vt[x]=1;
            vl[y]=1;
            dfs(x,lx,tm+tr[x][lx],zm);
            vl[y]=0;
            vt[x]=0;
        }
    }
    return ;
}
//12 19

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&C,&n,&m,&d,&q);
//    printf("1");
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            int ti;
            scanf("%d %d",&a[i][j],&ti);
            tr[a[i][j]][i]=ti;
            b[a[i][j]].push_back(i);
        }
    }
 //   printf("1");
    for(int i=1;i<=q;i++){
        scanf("%d %d",&xr[i],&yr[i]);
    }
    for(int i=1;i<=q;i++){
        memset(vl,0,sizeof(vl));
        memset(dist,0x3f3f3f3f,sizeof(dist));
//        memset(vt,0,sizeof(vt));
        vt[xr[i]]=1;
        e=1e9;
        int csh=w[xr[i]]+w[yr[i]];
        for(int j=0;j<b[xr[i]].size();j++){
            int lx=b[xr[i]][j];
            dist[xr[i]][lx]=csh+tr[xr[i]][lx];
            dfs(xr[i],lx,csh+tr[xr[i]][lx],yr[i]);
            dist[xr[i]][lx]=0x3f3f3f3f;
        }
        vt[xr[i]]=0;
        printf("%d\n",e);
    }
    return 0;
}
