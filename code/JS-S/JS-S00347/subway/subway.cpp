#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=510;
const int M=5e5+10;
struct Node{
    int sub;
    LL t;
};
LL mp[N][N],w[M];
vector<Node> f[M];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            if(i==j)mp[i][j]=0;
            else mp[i][j]=10000000000000;
        }
    }
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a;
            LL tt;
            scanf("%d%lld",&a,&tt);
            Node in;
            in.sub=i,in.t=tt;
            f[a].push_back(in);
        }
    }
    for(int i=1;i<=m;i++){
        for(int r=0;r<f[i].size();r++){
            for(int l=0;l<r;l++){
                mp[f[i][l].sub][f[i][r].sub]=min(f[i][l].t+f[i][r].t,mp[f[i][l].sub][f[i][r].sub]);
                mp[f[i][r].sub][f[i][l].sub]=min(f[i][l].t+f[i][r].t,mp[f[i][r].sub][f[i][l].sub]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        LL ans=10000000000000;
        scanf("%d%d",&x,&y);
        int stx=0,sty=0;
        for(int i=0;i<f[x].size();i++){
            for(int j=0;j<f[y].size();j++){
                if(ans>mp[f[x][i].sub][f[y][j].sub]){
                    ans=mp[f[x][i].sub][f[y][j].sub];
                    stx=i;
                    sty=j;
                }
            }
        }
        ans=ans+w[x]+w[y]+f[x][stx].t+f[y][sty].t;
        printf("%lld\n",ans);
    }
    return 0;
}
