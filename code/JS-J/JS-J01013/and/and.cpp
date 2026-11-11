#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,m;
ll a[200005],f[20005][2005],ans;
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
            scanf("%lld",&a[i]);
            f[i][0]=2147483647;
    }
    for(int i=1;i<=n+1;++i){
        for(int j=0;j<=int(min(i,m));++j){
            f[i][j]=max(f[i][j],f[i-1][j]);
            if(j>0)f[i][j]=max(f[i][j],f[i-1][j-1]&a[i-1]);
        }
    }
    for(int i=m;i<=n+1;++i)ans=max(ans,f[i][m]);
    printf("%lld",ans);
    return 0;
}
