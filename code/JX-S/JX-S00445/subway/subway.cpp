#include<bits/stdc++.h>
using namespace std;
const int maxm=500005,maxn=505;
int c,n,m,d,q;
long long w[maxm];
struct node{
    int a;
    long long t;
};
vector<node>tp[maxm];//tp[i][j]:从i地铁站的站厅走到第.a条线路的站台需要的时间.t
long long f[maxn][maxn];//f[i][j]:从第i条线路到第j条线路需要的时间
long long res;
unsigned long long readll(){
    long long p,res=0;
    bool neg=false;
    while(p!=EOF&&(p<'0'||p>'9')){
        p=getchar();
    
    }
    while(p!=EOF&&('0'<=p&&p<='9')){
        res=res*10+p-'0';
        p=getchar();
    
    }
    if(neg)res=-res;
    return res;
}
unsigned int read(){
    int p,res=0;
    bool neg=false;
    while(p!=EOF&&(p<'0'||p>'9')){
        p=getchar();
    
    }
    while(p!=EOF&&('0'<=p&&p<='9')){
        res=res*10+p-'0';
        p=getchar();
    
    }
    if(neg)res=-res;
    return res;
}
int k,a,t;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i][i]=0;
        int k=read(),a;
        long long tt;
        for(int j=1;j<=k;j++){
            a=read(),tt=readll();
            tp[a].push_back({i,tt});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<tp[i].size();j++){
           for(int k=j+1;k<tp[i].size();k++){
                int u=tp[i][j].a, v=tp[i][k].a;
                long long ut=tp[i][j].t,vt=tp[i][k].t;
                    f[u][v]=min(f[u][v],ut+vt);
                    f[v][u]=min(f[v][u],ut+vt);
            }
        }
    }//O(md^2);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                f[j][i]=f[i][j];
            }
        }
    }//O(n^3);
    
    int x,y;
    while(q--){
        res=LONG_LONG_MAX;
        x=read(),y=read();
        for(int i=0;i<tp[x].size();i++){
            for(int j=0;j<tp[y].size();j++){
                res=min(res,w[x]+w[y]+tp[x][i].t+tp[y][j].t+f[tp[x][i].a][tp[y][j].a]);
            }
        }
        cout<<res<<"\n";
    }
}