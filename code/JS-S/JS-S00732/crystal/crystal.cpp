#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    long long ans=1,sum=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];//printf("%d %d %d\n",a[i],(i-j+1),sum);
        while(j<=i&&(a[i]*(i-j+1)-sum)>m)
        {
            sum-=a[j];
            j++;

        }
        //printf("%d %d\n",i,j);
        if(j<=i)
        {
            ans=max(ans,(long long)i-j+1);
        }
    }
    printf("%lld",ans);
    return 0;
}
