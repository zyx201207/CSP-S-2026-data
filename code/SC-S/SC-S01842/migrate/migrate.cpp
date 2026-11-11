#include<cstdio>
#include<algorithm>
#define N 2000005
int n,hlp[N];
long long d,x[N],fr[N],fl[N],s[N],ans;
long long g[N];
void work(long long f[]){
    for(int i=1,j=0;i<=n;i++){
        while(x[i]-x[j+1]>d)j++;
        hlp[i]=j;
    }
    for(int i=1;i<n;i++)g[i]=1,f[i]=0;
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<i;j++)if(x[i]-x[j]<=d&&x[i+1]-x[j]>d){
    //         if(x[i]-x[j-1]>d)g[i]+=g[j];
    //         else g[i]++;
    //     }
    // }
    // for(int i=1;i<n-1;i++){
    //     for(int j=1;j<i;j++)if(x[i+1]-x[j]<=d&&x[i+2]-x[j]>d){
    //         if(x[i]-x[j-1]>d)f[i]+=g[j];
    //         else f[i]++;
    //     }
    // }
    for(int i=1;i<n;i++){
        int L=hlp[i]+1,R=std::min(hlp[i+1],i-1);
        if(L<=R){
            g[i]+=R-L;
            if(x[i]-x[L-1]>d)g[i]+=g[L];
            else g[i]++;
        }
        // for(int j=1;j<i;j++)if(x[i]-x[j]<=d&&x[i+1]-x[j]>d){
        //     if(x[i]-x[j-1]>d)g[i]+=g[j];
        //     else g[i]++;
        // }
    }
    for(int i=1;i<n-1;i++){
        int L=hlp[i+1]+1,R=std::min(hlp[i+2],i-1);
        if(L<=R){
            f[i]+=R-L;
            if(x[i]-x[L-1]>d)f[i]+=g[L];
            else f[i]++;
        }
        // for(int j=1;j<i;j++)if(x[i+1]-x[j]<=d&&x[i+2]-x[j]>d){
        //     if(x[i]-x[j-1]>d)f[i]+=g[j];
        //     else f[i]++;
        // }
    }
    // for(int i=1;i<n;i++)f[i]=1+s[std::min(i-1,hlp[i+1])]-s[hlp[i]],s[i]=s[i-1]+f[i];
    // for(int i=1;i<=n;i++)s[i]=0;
}
void Main(){
    scanf("%d%lld",&n,&d),ans=0;
    for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
    work(fl);
    // for(int i=1;i<=n;i++)printf("%lld%c",fl[i],"\n "[i<n]);
    for(int i=1;i<=n;i++)x[i]=-x[i];
    std::reverse(x+1,x+n+1);
    work(fr);
    std::reverse(fr+1,fr+n+1);
    // for(int i=1;i<=n;i++)printf("%lld%c",fr[i],"\n "[i<n]);
    for(int i=2;i<n-1;i++)ans+=fl[i]*fr[i+1];
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int CID,t;
    x[0]=-3e18;
    scanf("%d%d",&CID,&t);
    while(t--)Main();
}