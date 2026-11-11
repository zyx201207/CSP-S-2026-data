#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5003,inf=0x3f3f3f3f3f3f3f3f;
inline int rd(){
    int f=1,x=0;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while('0'<=c&&c<='9') x=x*10+c-'0',c=getchar_unlocked();
    return x*f;
}
int n,d,a[N],dis[N][N],f[N][N],L[N];
void mainb(){
    n=rd(),d=rd();int ans=0;
    memset(dis,0x3f,sizeof dis);
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++){
        a[i]=rd();
        dis[i][i]=0;
        int j=i-1;
        for(;j&&a[i]-a[j]<=d;j--) dis[i][j]=dis[j][i]=1,f[i][j]=f[j][i]=1;
        L[i]=j+1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==k||k==j) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==k||k==j) continue;
                if(dis[i][k]+dis[k][j]==dis[i][j]) f[i][j]+=f[i][k]*f[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++) ans+=(f[i][j]==2);
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int test,T;test=rd(),T=rd();
    while(T--) mainb();
}
/*

-100 -97 -94 -93 -92 -91 -90 -89 -86 -83

10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

6 12
-10 -6 -2 2 6 10

*/
