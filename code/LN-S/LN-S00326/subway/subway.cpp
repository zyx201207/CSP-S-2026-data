#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005,M=10005;
int C,n,m,d,q,w[N],a[N][N],t[N][N],mx=0;
int f[M][M],num=0,dd[N],xl[N][N],tl[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    num=m;
    for(int i=1;i<=min(m*d,M);i++){
        for(int j=1;j<=min(m*d,M);j++)f[i][j]=3e18;
        f[i][i]=0;
    }
    for(int i=1,k;i<=n;i++){
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            dd[a[i][j]]++,xl[a[i][j]][dd[a[i][j]]]=i;
            tl[a[i][j]][dd[a[i][j]]]=j;
        }
        for(int j=1;j<k;j++){
            int tn1=(dd[a[i][j]]-1)*m+a[i][j];
            int tn2=(dd[a[i][j+1]]-1)*m+a[i][j+1];
            f[tn1][tn2]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=dd[i];j++){
            for(int k=1;k<j;k++){
                int tn1=(j-1)*m+i,tn2=(k-1)*m+i;mx=max(max(tn1,tn2),mx);
                f[tn1][tn2]=f[tn2][tn1]=t[xl[i][j]][tl[i][j]]+t[xl[i][k]][tl[i][k]];
            }
        }
    }
    for(int i=1;i<=mx;i++){
        for(int j=1;j<=mx;j++){
            for(int k=1;k<=mx;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;scanf("%lld%lld",&x,&y);int ans=3e18;
        for(int i=1;i<=dd[x];i++){
            for(int j=1;j<=dd[y];j++){
                int tn1=(i-1)*m+x,tn2=(j-1)*m+y;
                ans=min(ans,f[tn1][tn2]);
            }
        }printf("%lld\n",ans+w[x]+w[y]);
    }
}
