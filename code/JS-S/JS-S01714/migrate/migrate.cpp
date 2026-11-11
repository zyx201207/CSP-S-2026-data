#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000005],pos[2000005],f[2000005],g[2000005],sum[2000005],lst[2000005];
void solve(){
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        pos[i]=i;
        long long l=1,r=i-1;
        while(l<=r){
            long long mid=l+r>>1;
            if(a[i]-a[mid]<=d) pos[i]=mid,r=mid-1;
            else l=mid+1;
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        f[i]=0,g[i]=sum[i]=1;
        f[i-1]=g[i-1]=sum[i-1]=0;
        lst[0]=i;
        for(int j=i+1;j<=n;j++){
            long long p=max(pos[j],(long long)i);
            f[j]=f[p]+1;
            lst[f[j]]=j;
            g[j]=sum[lst[f[p]]]-sum[p-1];
            sum[j]=sum[j-1]+g[j];
            if(g[j]==2) ans++;
        }
    }
    printf("%lld\n",ans);
}
void solve1(){
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        pos[i]=i;
        long long l=1,r=i-1;
        while(l<=r){
            long long mid=l+r>>1;
            if(a[i]-a[mid]<=d) pos[i]=mid,r=mid-1;
            else l=mid+1;
        }
    }
    long long ans=0;
    vector<long long>tmp;
    f[1]=0,g[1]=sum[1]=1;
    f[1-1]=g[1-1]=sum[1-1]=0;
    lst[0]=1;
    for(int i=2;i<=n;i++){
        long long p=max(pos[i],1ll);
        f[i]=f[p]+1;
        lst[f[i]]=i;
        g[i]=sum[lst[f[p]]]-sum[p-1];
        sum[i]=sum[i-1]+g[i];
        if(g[i]==2) tmp.push_back(i);
    }
    for(long long i:tmp) ans+=n-i+1;
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    scanf("%lld%lld",&c,&t);
    while(t--){
        if(c==11||c==12) solve1();
        else solve();
    }
    return 0;
}