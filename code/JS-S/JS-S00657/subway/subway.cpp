#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=507,M=5e5+7;
const ll LINF=0x3f3f3f3f3f3f3f3f;
int n,m,q,w0[M];
ll f[N][N];
vector<pii> e[M];

inline int read(){
    int s=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)){
        s=s*10+c-'0';
        c=getchar();
    }
    return s;
}

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][k]!=LINF&&f[k][j]!=LINF&&f[i][k]+f[k][j]<f[i][j]) f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read();n=read();m=read();read();q=read();
    for(int i=1;i<=m;i++) w0[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        //scanf("%d",&k);
        while(k--){
            int x,w;
            x=read();w=read();
            e[x].push_back({i,w});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<e[i].size();j++){
            for(int k=j+1;k<e[i].size();k++){
                int x=e[i][j].first,y=e[i][k].first;
                ll w=(ll)e[i][j].second+e[i][k].second;
                f[x][y]=min(f[x][y],w);
                f[y][x]=min(f[y][x],w);
            }
        }
    }
    floyd();
    while(q--){
        int i,j;
        i=read();j=read();
        ll ans=LINF;
        for(pii p1:e[i]){
            for(pii p2:e[j]){
                int x=p1.first,y=p2.first;
                ll w=(ll)p1.second+p2.second;
                ans=min(ans,w+f[x][y]);
            }
        }
        printf("%lld\n",ans+w0[i]+w0[j]);
    }
    return 0;
}