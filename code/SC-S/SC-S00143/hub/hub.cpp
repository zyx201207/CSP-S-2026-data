#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define de(x...) fprintf(stderr,x)
#define rep(i,l,r) for(auto i = l;i <= r;++i)
#define per(i,l,r) for(auto i = l;i >= r;--i)
#define eb emplace_back
const int N = 1000005,M = 21,I = 1e9;
int Tid,TT,n,m,rt,S,fa[N],dep[N],d[N],Fa[M][N];
int len,zj[N];//zhijing chang
int D[N];
int dan[N];//when return to zhijing   (ancestor)
int isz[N];//in zhijing
vector<int> e[N];
void dfs(int x){
    for(int y:e[x])
        if(y ^ fa[x])  fa[y] = x,dep[y] = dep[x]+1,dfs(y);
}
void df(int x){
    if(!isz[x]) d[x] = d[fa[x]]+1,dan[x] = dan[fa[x]];
    else    dan[x] = x,d[x] = 1;
    for(int y:e[x]){
        if(y != fa[x]){
            df(y);
            if(!isz[y])  D[x] = max(D[x],D[y]+1);
        }
    }
}
int lo[N];
struct STB{
    int st[M][N]={};
    void init(){
        rep(i,1,lo[len])
            rep(j,0,len-(1<<i)+1)   st[i][j] = max(st[i-1][j],st[i-1][j+(1<<i-1)]);
    }
    int rmq(int l,int r){
        if(l > r)   return -I;
        int k = lo[r-l+1];
        return max(st[k][l],st[k][r-(1<<k)+1]);
    }
    void cl(){
        memset(st,0,sizeof(st));
    }
}s1,s2;
void CLEA(){
    len = rt = S = 0;
    rep(i,1,n)  e[i].clear(),dep[i] = d[i] = fa[i] = isz[i] = D[i] = zj[i] = dan[i] = 0;
    s1.cl(),s2.cl();
}
void gos(){
    rep(i,0,len){
        int x = zj[i];
        s1.st[0][i] = D[x] + dep[x],s2.st[0][i] = D[x] - dep[x];
    }
    s1.init(),s2.init();
}
int dmin(int i,int j){
    int x = (dep[i]+dep[j])>>1;
    return max(s1.rmq(dep[i]+1,x)-dep[i],s2.rmq(x+1,dep[j]-1)+dep[j]);
}
int jp(int x,int y){
    rep(i,0,lo[y])
        if(y>>i&1)  x = Fa[i][x];
    return x;
}
vector<int> F[N*2],G[N*2];
//F[x]:i2->x plus   G[x]:j2->x plus
int vi[N],A;
void del(int x){
    // if(vi[x] == 1)
    // de("    del(%d)\n",x);
    A -= !(--vi[x]);
}
void add(int x){
    A += (!vi[x]),++vi[x];
}
void goj(int i,int op = 0){
    if(op)  for(int x:G[i]) add(x);
    else    for(int x:G[i]) del(x);
}
void goi(int i){
    for(int x:F[i]) add(x);
}
void adf(int x,int y){
    if(x <= len){
        // de("    F %d,%d\n",x,y);
        F[x].eb(y);
    }
}
void adg(int x,int y){
    if(x >= 0){
        // de("    G %d,%d\n",x,y);
        G[x].eb(y);
    }
}
bool check(int dis){
    // de("check %d-------------------------------------------------------------------------\n",dis);
    rep(i,0,len)    F[i].clear(),G[i].clear();
    A = 0;
    rep(i,1,n)  vi[i] = 0;
    rep(i,1,n){
        // de("  i = %d\n",i);
        vi[i] = 0;
        if(d[i] <= dis){
            adf(dep[dan[i]]+dis-d[i],zj[dep[dan[i]]+dis-d[i]]);
            if(dep[dan[i]]-dis+d[i] >= 0)    adg(dep[dan[i]]-dis+d[i],zj[dep[dan[i]]-dis+d[i]]);
        }else{
            adf(dep[dan[i]],jp(i,dis));
            adg(dep[dan[i]],jp(i,dis));
        }
    }
    rep(i,0,len)    goj(i,1);
    goi(0);
    for(int i2 = 0,j2 = 0;i2 <= len;goi(++i2)){
        int i = zj[i2];
        while(j2 < len && dmin(i,zj[j2+1]) <= dis)   goj(j2),++j2;
        int j = zj[j2];
        add(i),add(j);
        // de("  i = %d,i2 = %d | j = %d,j2 = %d | dmin = %d,%d\n",i,i2,j,j2,dmin(i,j),dmin(i,zj[j2+1]));
        // de("     A = %d\n",A);
        if(A <= m)  return 1;
        del(i),del(j);
    }
    return 0;
}
// bool check(int dis){
//     de("check %d-------------------------------------------------------------------------\n",dis);
//     A = 0;
//     for(int i2 = 0,j2 = 0;i2 < len;goi(++i2)){
//         int i = zj[i2];
//         while(j2 < len && dmin(i,zj[j2+1]) <= dis)   ++j2;
//         int j = zj[j2];
//         // if(i2 >= j2){
//         //     de("????????????????????????????\n");
//         //     de("  len = %d i = %d,i2 = %d | j = %d,j2 = %d | dmin = %d,%d\n",len,i,i2,j,j2,dmin(i,j),dmin(i,zj[j2+1]));exit(0);
//         // }
//         rep(k,1,n)  vi[k] = 0;
//         add(i),add(j);
//         for(int x = 1;x <= n;++x){
//             if((d[x] >= dis && dep[dan[x]] <= i2) || (d[x] < dis && dep[dan[x]]+dis-d[x] <= i2)){
//                 if(d[x] <= dis){
//                     int z = dep[dan[x]]+dis-d[x];
//                     for(int j = 0;!vi[zj[z+j]];++j)   add(zj[z+j]);
//                 }else{
//                     int z = jp(x,dis);
//                     while(!isz[i])  vi[z] = 1,z = fa[z];
//                     z = dep[z];
//                     for(int j = 0;!vi[zj[z+j]];++j)   add(zj[z+j]);
//                 }
//             }else if((d[x] >= dis && dep[dan[x]] >= j2) || (d[x] < dis && dep[dan[x]]+d[x]-dis >= j2)){
//                 if(d[x] <= dis){
//                     int z = dep[dan[x]]+d[x]-dis;
//                     for(int j = 0;!vi[zj[z-j]];++j)   add(zj[z-j]);
//                 }else{
//                     int z = jp(x,dis);
//                     while(!isz[i])  vi[z] = 1,z = fa[z];
//                     z = dep[z];
//                     for(int j = 0;!vi[zj[z-j]];++j)   add(zj[z-j]);
//                 }
//             }
//         }
//         de("  A = %d\n",A);
//         if(A <= m)  return 1;
//     }
//     return 0;
// }
void gFA(){
    rep(i,1,n)  Fa[0][i] = fa[i];
    Fa[0][rt] = rt;
    rep(i,2,n)  lo[i] = lo[i>>1]+1;
    rep(i,1,lo[n])
        rep(j,1,n)  Fa[i][j] = Fa[i-1][Fa[i-1][j]];
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&Tid,&TT);
    while(TT--){
        scanf("%d%d",&n,&m);
        rep(i,1,n-1){
            int x,y;scanf("%d%d",&x,&y),e[x].eb(y),e[y].eb(x);
        }
        // if(TT == 4){
        //     CLEA();
        //     continue;
        // }
        dfs(1);
        rt = S = 0;
        rep(i,1,n)
            if(dep[i] > dep[rt])    rt = i;
        fa[rt] = dep[rt] = 0,dfs(rt);
        rep(i,1,n)
            if(dep[i] > dep[S]) S = i;
        if(m == 2){
            printf("%d\n",dep[S]/3);
            CLEA();
            continue;
        }
        len = dep[S];
        for(int i = S;i;i = fa[i])  isz[i] = 1,zj[dep[i]] = i;
        // de("rt = %d S = %d len = %d\n",rt,S,len);
        // de("zj[] = ");rep(i,0,len)  de("%d%c",zj[i]," \n"[i==len]);
        df(rt);
        gFA();
        // rep(i,1,n)  de("%d | dep = %d d = %d dan = %d D = %d\n",i,dep[i],d[i],dan[i],D[i]);
        
        if(m == n){
            printf("0\n");
            CLEA();
            continue;
        }
        gos();
        int l = 1,r = len-1;
        while(l < r){
            int mid = (l+r)>>1;
            if(check(mid))  r = mid;
            else    l = mid+1;
        }
        printf("%d\n",l);
        CLEA();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}