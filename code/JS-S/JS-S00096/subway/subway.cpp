#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9'){x=x*10+c-48;c=getchar();}
    return x*f;
}
int k[510],w[510];
int dp[1510][1510];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=m+1; i<=2*m; i++){
        for(int j=m+1; j<=2*m; j++){
            dp[i][j]=0x3f3f3f3f;
        }dp[i][i]=0;
    }
    for(int i=1; i<=m; i++){
        int a;
        a=read();
        w[i]=a;
        //e[i].push_back({i+500,a});
        //e[i+500].push_back({i,a});
        dp[i][i+m]=dp[i+m][i]=a;
    }for(int i=1; i<=n; i++){
        k[i]=read();
        int a1,a2;
        a1=read();
        a2=read();
        for(int j=2; j<=k[i]; j++){
            int b,t;
            b=read();
            t=read();
            //e[j+1000].push_back({b+500,t});
            //e[b+500].push_back({j+1000,t});
            dp[a1+m][b+m]=dp[b+m][a1+m]=t+a2;
        }
    }for(int k=m+1; k<=2*m; k++){
        for(int i=m+1; i<=2*m; i++){
            for(int j=m+1; j<=2*m; j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }for(int i=1; i<=q; i++){
        int x,y;
        x=read();
        y=read();
        printf("%d\n",dp[x+m][y+m]+w[x]+w[y]);
    }
    //for(int i=1; i<=3*m; i++){
    //    for(int j=1; j<=3*m; j++){
    //        cout<<dp[i][j]<<' ';
    //    }cout<<endl;
    //}

}
