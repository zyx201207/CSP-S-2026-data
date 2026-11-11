#include<bits/stdc++.h>
using namespace std;
#define maxn 505
#define maxm 500005
#define maxq 100005
#define INF (1<<30)
#define maxd 25

int c,n,m,d,q,cnttim;//c->测试点编号,n->地铁线路数,m->地铁站数,d->每个地铁站最多被几条线路经过,q->出行计划数
int w[maxm],k[maxn],timhd[maxn],t[maxn][maxn],lnk[maxn],cntw;long long dir[maxn];//w[id]->站台id厅到口,k[id]->id线路经过站台数,timhd[id]->id线路在tim中的第一个的位置
bool vis[maxn],an[maxm][maxn];
struct stoh{
    int a,t,id;
    bool operator<(const stoh &b)const{return a<b.a||a==b.a&&t<b.t;}
}tim[maxm];//id线路在a站从站台走到大厅需要t
struct trp{
    int frm,to;
}r[maxq];
struct way{
    int to,nxt,vl;
}wy[250005];

int read(){
    int f=1,r=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
    return f*r;
}
void dfs(int frm,int to){
    for(int i=1;i<=n;i++)dir[i]=(1<<30),vis[i]=0;
    int que[505],hed=0,til=0;que[++hed]=frm;
    while(hed!=til){
        til=(til+1)%maxn;
        for(int i=lnk[que[til]];i;i=wy[i].nxt){
            if(dir[que[til]]+wy[que[til]].vl<dir[wy[que[til]].to])dir[wy[que[til]].to]=dir[que[til]]+wy[que[til]].vl,que[hed=(hed+1)%maxn]=wy[que[til]].to;
        }
    }
}
void mke(int frm,int to,int vl){
    wy[++cntw]=(way){to,lnk[frm],vl};
    lnk[frm]=cntw;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();timhd[i]=cnttim+1;
        for(int j=1;j<=k[i];j++)cnttim+=1,tim[cnttim]=(stoh){read(),read(),i},an[tim[cnttim].a][i]=1;
    }
    timhd[n+1]=cnttim+1;
    for(int i=1;i<=q;i++)r[i]=(trp){read(),read()};
    sort(tim+1,tim+1+cnttim);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)t[i][j]=INF;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int di=timhd[i],dj=timhd[j];
            while(di<timhd[i+1]&&dj<timhd[j+1]){
                if(tim[di].a==tim[dj].a){
                    if(!t[i][j]&&!t[j][i])t[i][j]=cntw+1,t[j][i]=cntw+2,mke(i,j,(1<<30)),mke(j,i,(1<<30));
                    wy[t[i][j]].vl=wy[t[j][i]].vl=min(wy[t[i][j]].vl,tim[di].t+tim[dj].t);
                    di++,dj++;
                }
                else if(tim[di].a<tim[dj].a)di++;
                else dj++;
            }
        }
    }
    for(int i=1;i<q;i++){
        long long ans=1000000000000000;
        for(int j=1;j<=n;j++){
            if(!an[r[i].frm][j])continue;
            for(int k=1;k<=n;j++){
                if(!an[r[i].to][k])continue;
                dfs(j,k);
                ans=min(ans,dir[k]);
            }
        }
        printf("%lld\n",ans+w[r[i].frm]+w[r[i].to]);
    }
    return 0;
}