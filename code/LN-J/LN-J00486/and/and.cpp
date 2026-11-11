#include <bits/stdc++.h>
using namespace std;

long long n,m,a[209999],c[209999],ans=-1;

inline void dfs(long long x){
    if(x>n)
        return;
    long long l=0;
    for(long long i=1;i<=x;i++)
        if(c[i])
            l++;
    if(l==m){
        long long cnt=0;
        for(long long i=1;i<=n;i++)
        if(c[i]){
            cnt=a[i];
            break;
        }
        for(long long i=1;i<=n;i++)
            if(c[i]){
                cnt&=a[i];
            }
        ans=max(ans,cnt);
        return;
    }
    c[x+1]=0;
    dfs(x+1);
    c[x+1]=1;
    dfs(x+1);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    memset(c,0,sizeof(c));
    c[1]=0;
    dfs(1);
    c[1]=1;
    dfs(1);
    printf("%lld",ans);
}
