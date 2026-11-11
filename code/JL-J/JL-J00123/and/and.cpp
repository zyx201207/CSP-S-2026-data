#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=2e5+5,M=2005;
int n,m,a[N],b[N],t,ans,res;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(i<=m) b[i]=1;
        else b[i]=0;
    }
    do
    {
        res=(1<<31)-1;
        for(int i=1;i<=n;i++)
        {
            if(b[i]) res&=a[i];
        }
        ans=max(ans,res);
    }while(prev_permutation(b+1,b+n+1));
    printf("%lld",ans);
}
/*
4 2
3 15 12 12

12

5 3
31 3 1 15 7

7
*/
