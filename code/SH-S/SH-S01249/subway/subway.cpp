#include<cctype>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
char buf[1048577],*p1,*p2;
#define gc() p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p2==p1)?EOF:*p1++
void rd(int &x){
    x=0; char c=gc();
    while(!isdigit(c)) c=gc();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=gc();
}
const int N=509,M=5e5+9;
int SJQ,n,m,D,Q,val[M];
vector<PII> vec[M];
LL g[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    rd(SJQ),rd(n),rd(m),rd(D),rd(Q);
    for(int i=1;i<=m;i++) rd(val[i]);
    for(int i=1,c,x,y;i<=n;i++){
        rd(c);
        while(c--) rd(x),rd(y),vec[x].push_back({i,y});
    }
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++) g[i][i]=0;
    for(int i=1;i<=m;i++) for(PII &P:vec[i]) for(PII &Q:vec[i]) g[P.fi][Q.fi]=min(g[P.fi][Q.fi],(LL)P.se+Q.se);
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    int x,y; while(Q--){
        rd(x),rd(y);
        LL res=0x3f3f3f3f3f3f3f3fLL;
        for(PII &P:vec[x]) for(PII &Q:vec[y]) res=min(res,P.se+g[P.fi][Q.fi]+Q.se);
        res+=val[x]+val[y];
        printf("%lld\n",res);
    }
    return 0;
}