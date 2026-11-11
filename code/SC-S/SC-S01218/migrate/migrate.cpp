#include<bits/stdc++.h>
const long long N=2e6+5,inf=1e18;
long long c,t,n,d,x[N];
namespace r1{
    const long long N=5005;
    long long ans,f[N][N],g[N][N],s[N][N];
    void main(){
        ans=0;
        for(long long i=1;i<=n;i++){
            f[i][i]=0,g[i][i]=s[i][i]=1;
            for(long long j=i+1;j<=n;j++){
                long long l=std::lower_bound(x+i,x+j,x[j]-d)-x;
                if(l<j){
                    f[i][j]=f[i][l]+1;
                    long long r=(std::upper_bound(f[i]+l+1,f[i]+j,f[i][l])-f[i])-1;
                    g[i][j]=s[i][r]-s[i][l-1];
                    s[i][j]=s[i][j-1]+g[i][j];
                    if(g[i][j]==2)ans++; 
                }
                else f[i][j]=inf,g[i][j]=0,s[i][j]=0;
            }
        }
        printf("%lld\n",ans);
    }
}
namespace r2{
    long long ans,f[N],g[N],s[N];
    void main(){
        ans=0;
        f[1]=0,g[1]=s[1]=1;
        for(long long i=2;i<=n;i++){
            long long l=std::lower_bound(x+1,x+i,x[i]-d)-x;
            if(l<i){
                f[i]=f[l]+1;
                long long r=(std::upper_bound(f+l+1,f+i,f[l])-f)-1;
                g[i]=s[r]-s[l-1];
                s[i]=s[i-1]+g[i];
                if(g[i]==2){
                    ans+=n-i+1;
                }
            }
            else f[i]=inf,g[i]=0,s[i]=0;
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(long long i=1;i<=n;i++)scanf("%lld",&x[i]);
        if(c<=10)r1::main();
        else r2::main();
    }
}