#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int b[500010];
long long d[500010];
int n,m;
long long ans=0;
void dfs(int x,long long zhi){
    if(x==m){
        ans=max(ans,zhi);
        return;
    }
    for(int i=1;i<=n;i++){
        if(b[i]){
            continue;
        }
        long long xin=zhi&a[i];
        b[i]=1;
        dfs(x+1,xin);
        b[i]=0;
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long start=1;
    for(int i=1;i<=22;i++){
        start*=2;
    }
    start-=1;
    if(n>10){
        if(m==1){
            long long max1=0;
            for(int i=1;i<=n;i++){
                max1=max(a[i],max1);
            }
            printf("%lld\n",max1);
            return 0;
        }
        if(m==n){
            long long sum=0;
            for(int i=1;i<=n;i++){
                sum=sum&a[i];
            }
            printf("%lld\n",sum);
            return 0;
        }
        if(m==2){
            long long max1=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    max1=max(a[i]&a[j],max1);
                }

            }
            printf("%lld\n",max1);
            return 0;
        }
    }
    dfs(0,start);
    printf("%lld\n",ans);
    return 0;
}

